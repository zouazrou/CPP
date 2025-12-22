#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <sstream>
# include <algorithm>
# include <ctime>
# include <iomanip>

#define DEAFULT_DB "data.csv"

class BitcoinExchange
{
private:
    std::map<std::string, std::string> DBMap; 
    std::string db;
    
public:
    BitcoinExchange();
    BitcoinExchange(std::string& db);
    BitcoinExchange(char *db);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator =(const BitcoinExchange& other);
    ~BitcoinExchange();
    
    void    Binance(char *file);

    void    ParseDB(void);
    bool    convertStrToDate(std::string& date, int& Y, int& M, int& D);
    bool    isValidRow(std::string& date, std::string& sep, std::string& val);
    bool    isValidValue(std::string& val);
    bool    isValidDate(std::string& date);
    void    doExchange(std::string& date, std::string& val);
};

#endif
