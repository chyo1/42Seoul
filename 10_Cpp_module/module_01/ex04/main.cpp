#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "fileController.hpp"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cout << "Enter 3 Parameters: filename, str1, str2" << std::endl;
		return 0;
    }

    fileController fc(argv[1], argv[2], argv[3]);
    if (fc.readFile())
        return 1;

    fc.replaceSubstrings();
    if (fc.writeFile())
        return 1;
    return 0;
}