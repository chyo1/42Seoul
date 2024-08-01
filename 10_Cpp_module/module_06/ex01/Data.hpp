#ifndef DATA_HPP
#define DATA_HPP

class Data {
	private:
		int a;
    public:
        Data();
		Data(int a);
        Data(Data const &src);
        Data &operator=(Data const &src);
        ~Data();
		int getA() const;
};
#endif