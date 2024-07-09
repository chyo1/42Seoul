#include "fileController.hpp"

fileController::fileController(char* inputFileName, char* str1, char* str2) {
    this->inputFileName = inputFileName;
    str = str1;
    newStr = str2;
}

// /*--------------파일 열어서 스트림에 담기------------*/
bool fileController::readFile() {
    std::ifstream openFile(this->inputFileName); // c++ 98?

    // 파일이 열림 -> 파일이 있음
    if (!openFile.is_open()) {
        std::cout << "check file name to open" << std::endl;
        return true;
    }
    std::stringstream buffer;
    // 파일 스트림의 내용을 읽어와서 buffer에 넣음
    buffer << openFile.rdbuf();

    // 스트림의 내용을 문자열로 저장
    fileContents = buffer.str();

    // 파일을 닫음
    openFile.close();

    return false;
}

/*--------------문자열 바꾸기------------*/
void fileController::replaceSubstrings() {
    
    // str1을 str2로 바꿈
    size_t pos = 0;
    while ((pos = fileContents.find(str, pos)) != std::string::npos) {
        replaceSubstring(pos, fileContents, str.length(), newStr);
        pos += newStr.length();
    }
}

bool fileController::writeFile() {
    outputFileName = (std::string)inputFileName + ".replace";

    std::ofstream outfile(outputFileName.c_str());
    if (!outfile.is_open()) {
        std::cerr << "Failed to open output file" << std::endl;
        return 1;
    }

    // std::stringstream의 내용을 파일에 쓰기
    outfile << fileContents;

    // 파일 닫기
    outfile.close();

    std::cout << "Contents have been written to output.txt" << std::endl;
    
    return false;
}

void fileController::replaceSubstring(size_t pos, std::string& dst, size_t src_len, const std::string &src) {
    std::string front = dst.substr(0, pos);
    std::string back = dst.substr(pos + src_len);
    dst = front + src + back;
}