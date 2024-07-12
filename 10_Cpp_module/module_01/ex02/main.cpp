#include <iostream>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "The memory address of the string variable" << std::endl;
    std::cout << "stringPTR : " << stringPTR << std::endl;
    std::cout << "stringREF : " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "The value of the string variable" << std::endl;
    std::cout << "value of stringPTR : " << *stringPTR << std::endl;
    std::cout << "value of stringREF : " << stringREF << std::endl;

    return 0;
}