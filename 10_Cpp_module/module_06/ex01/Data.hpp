#ifndef DATA_HPP
#define DATA_HPP

class Data {
    public:
        Data();
        Data(Data const &src);
        Data &operator=(Data const &src);
        ~Data();
};
#endif