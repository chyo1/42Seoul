#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <vector>
class BitcoinExchange {
    private:
        std::vector< std::pair<std::string, float> > rates;
        
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void readDataFileAndGetRate();
        void checkValidDate(std::string date);
        void checkValidRate(std::string rate);
        float openInputFileAndGetBitcoinPrice(char* fileName);
        float getBitcoinPrice(std::string date);

};
#endif