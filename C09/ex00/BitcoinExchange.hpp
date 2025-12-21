#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>

#define DEAFULT_DB "data.csv"

class BitcoinExchange
{
private:
    std::map<std::string, std::string> db_map; 
    std::string db;
    
public:
    BitcoinExchange();
    BitcoinExchange(std::string& db);
    BitcoinExchange(char *db);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator =(const BitcoinExchange& other);
    ~BitcoinExchange();
    
    void    ParseDB(void);
    void    Binance(char *file);
    bool    isValidRow(std::string& date, std::string& sep, std::string& val);
    bool    isValidValue(std::string& val);
    bool    isValidDate(std::string& date);
};

#endif
