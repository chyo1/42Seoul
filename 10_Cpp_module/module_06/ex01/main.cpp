#include "Serializer.hpp"
#include <iostream>
int main() {

    Serializer serializer;
    Data data;

    uintptr_t serialized = serializer.serialize(&data);
    Data *deserialized = serializer.deserialize(serialized);

    std::cout << "Data: " << &data << std::endl;
    std::cout << "Serialized: " << serialized << std::endl;
    std::cout << "Deserialized: " << deserialized << std::endl;
    return 0;
}