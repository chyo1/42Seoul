#include "BitcoinExchange.hpp"
#include <iostream>
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "You have to put a data file" << std::endl;
        return 1;
    }


    BitcoinExchange exchange;
    exchange.setRate(10000);
    std::cout << exchange.convertToBitcoin(100) << std::endl;
    std::cout << exchange.convertToUsd(1) << std::endl;
    return 0;

}