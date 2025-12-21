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

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : db(other.db)
{}

BitcoinExchange& BitcoinExchange::operator =(const BitcoinExchange& other)
{
    if (this == &other)
        return *this;
    db = other.db;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

void    BitcoinExchange::ParseDB()
{
    std::ifstream   fdb(this->db.c_str());
    std::string     line, key, val;
    bool            isFirstLine;

    isFirstLine = true;
    while (!fdb.eof())
    {
        getline(fdb, line);
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
        this->db_map.insert(std::make_pair(key, val));
    }
    fdb.close();
    // ! List map
    // for (std::map<std::string, std::string>::iterator i = this->db_map.begin();  i != this->db_map.end(); i++)
    //     std::cout << "DB[" << i->first << "] = " << i->second << '\n';
}


void    BitcoinExchange::Binance(char *fileName)
{
    std::string     line, date, val, sep;
    bool            isFirstLine;
    std::ifstream   InputFile(fileName);
    
    isFirstLine = true;
    while (!InputFile.eof())
    {
        date.clear();
        sep.clear();
        val.clear();
        getline(InputFile, line);
        if (line.empty())
            return ;
        if (isFirstLine)
        {
            if (line.compare("date | value"))
            {
                std::cerr <<  "Error : Invalid Column Name\n";
                return ;
            }
            isFirstLine = false;
            continue;   
        }
        std::stringstream strm(line);
        strm >> date;
        // if (strm.eof())
        // {
        //     std::cerr <<  "Error : Invalid Row\n";
        //     continue;
        // }
        strm >> sep;
        // if (strm.eof())
        // {
        //     std::cerr <<  "Error : Invalid Row\n";
        //     continue;
        // }
        strm >> val;
        if (isValidRow(date, sep, val))
            std::cout << " < Yeha! Valid Row\n";
        else
            std::cerr << " < Error : Invalid Row => " << '\n';
    }
    
}

bool    BitcoinExchange::isValidRow(std::string& date, std::string& sep, std::string& val)
{
    if (!isValidDate(date))
    {
        std::cerr << "Error : is not valid date\n";
        return (false);
    }
    if (sep != "|")
    {
        std::cerr << "Error : expect '|' instead of " << sep << '\n';
        return (false);
    }
    if (!isValidValue(val))
    {
        std::cerr << "Error : value must be between 1 and 1000\n";
        return (false);
    }
    return (true);
}

bool    BitcoinExchange::isValidValue(std::string& val)
{
    char *pEnd = NULL;
    long n = std::strtod(val.c_str(),&pEnd);

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
    if (*endPtr)
        return false;
    M = std::strtol(month.c_str(), &endPtr, 10);
    if (*endPtr)
        return false;
    D = std::strtol(day.c_str(), &endPtr, 10);
    if (*endPtr)
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