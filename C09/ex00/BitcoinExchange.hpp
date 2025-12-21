#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

#define DEAFULT_DB "data.csv"

class BitcoinExchange
{
private:
    // std::string inputFile;
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

};

#endif
