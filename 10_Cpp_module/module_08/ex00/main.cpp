#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <iostream>

int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i);

    try{
        std::cout << std::endl << "------test with vector------" << std::endl;
        std::cout << "location: " << (easyfind(vec, 5) - vec.begin()) << std::endl;
        std::cout << "location: " << (easyfind(vec, 10) - vec.begin()) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "------test with deque------" << std::endl;
    std::deque<int> deq;
    for (int i = 0; i < 10; i++)
        deq.push_back(i);
    
    try{
        std::cout << "location: " << (easyfind(deq, 5) - deq.begin()) << std::endl;
        std::cout << "location: " << (easyfind(deq, 10) - deq.begin()) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}