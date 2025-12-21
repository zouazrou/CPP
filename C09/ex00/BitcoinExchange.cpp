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