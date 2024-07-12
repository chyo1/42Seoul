#ifndef FILECONTROLLER_CPP
#define FILECONTROLLER_CPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class fileController {
    private:
        char* inputFileName;
        std::string outputFileName;
        std::string str;
        std::string newStr;
        std::string fileContents;
        void replaceSubstring(size_t pos, std::string& dst, size_t str1_len, const std::string &src);
        
    public:
        fileController(char* inputFileName, char* str1, char* str2);
        bool readFile();
        void replaceSubstrings();
        bool writeFile();

};


#endif