#include "easyfind.hpp"
#include <vector>
#include <list>


int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i);

    try{
        std::cout << "Testing with vector" << std::endl; 
        easyfind(vec, 5);
        easyfind(vec, 10);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::list<int> lst;
    for (int i = 0; i < 10; i++)
        lst.push_back(i);
    
    try{
        std::cout << "Testing with list" << std::endl; 
        easyfind(lst, 5);
        easyfind(lst, 10);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}