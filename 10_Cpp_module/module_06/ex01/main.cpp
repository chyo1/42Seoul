#include "Serializer.hpp"
#include <iostream>
int main() {

    Data data(100);

    uintptr_t serialized = Serializer::serialize(&data);
    Data *deserialized = Serializer::deserialize(serialized);

    std::cout << "Data: " << &data << std::endl;
    std::cout << "Serialized: " << serialized << std::endl;
    std::cout << "Deserialized: " << deserialized << std::endl;
	std::cout << deserialized->getA() << std::endl;

    return 0;
}≠≠