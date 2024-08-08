#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    rates = other.rates;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    rates = other.rates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}



void BitcoinExchange::readDataFileAndGetRate() {
    std::ifstream file("data.csv");

    if (!file.is_open())
        throw std::runtime_error("File not found");
        
   std::string line;
   std::getline(file, line);
   if (line != "date,exchange_rate")
         throw std::runtime_error("Invalid file format");

    while (std::getline(file, line)) {
            size_t idx = std::find(line.begin(), line.end(), ',') - line.begin();
            if (idx == line.size())
                throw std::runtime_error("Invalid file format");
            
            std::string date = line.substr(0, idx);
            std::string rate = line.substr(idx + 1, line.size() - idx - 1);
            
            checkValidDate(date);
            checkValidRate(rate);

            rates[date] = std::stof(rate);
    }
    file.close();
}

void BitcoinExchange::checkValidDate(std::string date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        throw std::runtime_error("Invalid date format");
    
    if (date < "2009-01-02")
        throw std::runtime_error("Invalid date");
    int year, month, day;
    year = stoi(date.substr(0, 4));
    month = stoi(date.substr(5, 2));
    day = stoi(date.substr(8, 2));

    if (month < 1 || month > 12 || day < 1 || day > 31)
        throw std::runtime_error("Invalid date");
    
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw std::runtime_error("Invalid date");

    // 윤년 체크
    if(!(year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        if (month == 2 && day > 28)
            throw std::runtime_error("Invalid date");
    }
    else {
        if (month == 2 && day > 29)
            throw std::runtime_error("Invalid date");
    }
}

void BitcoinExchange::checkValidRate(std::string rate) {
    if (rate.size() == 0 || stof(rate) < 0)
        throw std::runtime_error("Invalid exchange rate");
}


float BitcoinExchange::openInputFileAndGetBitcoinPrice(char* fileName) {
    std::ifstream file(fileName);
    if (!file.is_open())
        throw std::runtime_error("File not found");

    std::string line;
    std::getline(file, line);
    if (line != "date | value")
        throw std::runtime_error("Invalid file format");
    std::cout << line << std::endl;

    while (std::getline(file, line)) {
        size_t idx = std::find(line.begin(), line.end(), '|') - line.begin();
        if (idx == line.size()) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = line.substr(0, idx - 1);
        float value = stof(line.substr(idx + 2, line.size() - idx - 2));
        
        try {
            checkValidDate(date);
        } catch (const std::exception &e) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        float price = getBitcoinPrice(date);
        std::cout << date << " => " << value << " = " << price * value << std::endl;
    }

    file.close();
    return 0;
}

// bool cmp(const std::pair<std::string, float>& pair, const std::string& key) {
//     return pair.first <= key;
// }

float BitcoinExchange::getBitcoinPrice(std::string date) {
    std::map<std::string, float>::iterator iter = rates.lower_bound(date);
    if (iter->first != date)
        --iter;
    return iter->second;
}
