#include "easyfind.hpp"
#include <vector>
#include <deque>


int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i);

    try{
        std::cout << "Testing with vector" << std::endl; 
        std::cout << "First locaton is " << easyfind(vec, 5) - vec.begin() << std::endl;
        std::cout << "First locaton is " << easyfind(vec, 10) - vec.begin() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::deque<int> deq;
    for (int i = 0; i < 10; i++)
        deq.push_back(i);
    
    try{
        std::cout << "Testing with list" << std::endl; 
        std::cout << "First locaton is " << easyfind(deq, 5) - deq.begin() << std::endl;
        std::cout << "First locaton is " << easyfind(deq, 10) - deq.begin() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}