#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : db(DEAFULT_DB)
{
    ParseDB();
}

BitcoinExchange::BitcoinExchange(std::string& db) : db(db)
{
    ParseDB();
}

BitcoinExchange::BitcoinExchange(char *db) : db(db)
{
    ParseDB();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : DBMap(other.DBMap), db(other.db)
{}

BitcoinExchange& BitcoinExchange::operator =(const BitcoinExchange& other)
{
    if (this == &other)
        return *this;
    this->DBMap = other.DBMap;
    this->db = other.db;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

void    BitcoinExchange::ParseDB()
{
    std::ifstream   dataCSV(this->db.c_str());
    std::string     line, key, val;
    bool            isFirstLine;

    if (!dataCSV.is_open())
        throw std::runtime_error("Error : cannot open database file");
    isFirstLine = true;
    while (!dataCSV.eof())
    {
        getline(dataCSV, line);
        if (isFirstLine)
        {
            if (line.compare("date,exchange_rate"))
            {
                std::cerr <<  "Error : Invalid Column Name\n";
                return ;
            }
            isFirstLine = false;
            continue;   
        }
        std::stringstream strm(line);
        getline(strm, key, ',');
        if (key.empty())
            break;
        getline(strm, val);
        this->DBMap.insert(std::make_pair(key, val));
    }
    dataCSV.close();
}


void    BitcoinExchange::Binance(char *fileName)
{
    std::string     line, date, val, sep;
    bool            isFirstLine;
    std::ifstream   InputFile(fileName);
    
    if (!InputFile.is_open())
        throw std::runtime_error("Error : cannot open input file");
    isFirstLine = true;
    while (!InputFile.eof())
    {
        date.clear();
        sep.clear();
        val.clear();
        getline(InputFile, line);
        if (line.empty())
            continue;
        if (isFirstLine)
        {
            if (line.compare("date | value"))
            {
                std::cerr <<  "Error : Invalid Column Name\n";
                return;
            }
            isFirstLine = false;
            continue;   
        }
        std::stringstream strm(line);
        strm >> date;
        strm >> sep;
        strm >> val;
        if (isValidRow(date, sep, val))
            doExchange(date, val);
    }
}

bool    BitcoinExchange::isValidRow(std::string& date, std::string& sep, std::string& val)
{
    if (!isValidDate(date))
    {
        std::cerr << "Error : invalid date\n";
        return (false);
    }
    if (sep != "|")
    {
        std::cerr << "Error : expect '|' instead of '" << sep << "'\n";
        return (false);
    }
    if (!isValidValue(val))
    {
        std::cerr << "Error : the value must be an integer between 0 and 1000\n";
        return (false);
    }
    return (true);
}

bool    BitcoinExchange::isValidValue(std::string& val)
{
    double    n;
    char    *pEnd;
    
    if (val.empty())
        return (false);
    n = std::strtod(val.c_str(),&pEnd);
    if (!*pEnd && n >= 0 && n <= 1000)
        return (true);
    return (false);
}

bool    BitcoinExchange::convertStrToDate(std::string& date, int& Y, int& M, int& D)
{
    char        *endPtr;
    std::string year, month, day;
    
    if (std::count(date.begin(), date.end(), '-') != 2)
    {
        std::cerr << "Error : Bad date format => " << date << '\n';
        return (false);
    }
    std::stringstream strm(date);
    getline(strm, year, '-');
    getline(strm, month, '-');
    getline(strm, day);
    Y = std::strtol(year.c_str(), &endPtr, 10);
    if (*endPtr || Y < 2000)
        return false;
    M = std::strtol(month.c_str(), &endPtr, 10);
    if (*endPtr || M > 12 || M < 1)
        return false;
    D = std::strtol(day.c_str(), &endPtr, 10);
    if (*endPtr || M > 31 || M < 1)
        return false;
    return (true);
}

bool    BitcoinExchange::isValidDate(std::string& date)
{
    tm  dt;
    int Y, M, D;

    if (!convertStrToDate(date, Y, M, D))
        return (false);
    dt.tm_year = Y - 1900;
    dt.tm_mon = M - 1;
    dt.tm_mday = D;
    dt.tm_hour = 0;
    dt.tm_min = 0;
    dt.tm_sec = 0;
    dt.tm_isdst = 0;
    if (mktime(&dt) == -1)
        return (false);
    if (dt.tm_year + 1900 != Y || dt.tm_mon + 1 != M || dt.tm_mday != D)
        return (false);
    return (true);
}

void    BitcoinExchange::doExchange(std::string& date, std::string& amount)
{
    double  dAmount, dPrice;
    
    std::map<std::string, std::string>::iterator it;
    it = DBMap.lower_bound(date);
    if (it == DBMap.begin() && it->first != date)
    {
        std::cerr << "Error : this date is before the birth of bitcoin!\n";
        return ;
    }
    if (it == DBMap.end() || it->first != date)
        --it;
    dAmount = strtod(amount.c_str(), NULL);
    dPrice = strtod(it->second.c_str(), NULL);
    std::cout << date << " => " << amount << " = " << std::fixed << std::setprecision(2) << (dAmount * dPrice) << std::endl;
}