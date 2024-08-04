#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

class BitcoinExchange {
    private:
        float rate;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        void setRate(float rate);
        float getRate() const;
        float convertToBitcoin(float usd) const;
        float convertToUsd(float bitcoin) const;
};
#endif