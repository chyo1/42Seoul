#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void replaceSubstring(size_t pos, std::string& dst, size_t str1_len, const std::string &src) {
    std::string front = dst.substr(0, pos);
    std::string back = dst.substr(pos + str1_len);

    dst = front + src + back;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cout << "Enter 3 Parameters: filename, str1, str2" << std::endl;
    }
    
    /*--------------파일 열어서 스트림에 담기------------*/
    // 소스 파일과 같은 경로에 있는 파일을 읽음
    std::string inputFileName = argv[1];
    std::ifstream openFile(argv[1]); // c++ 98?

    // 파일이 열림 -> 파일이 있음
    if (!openFile.is_open()) {
        std::cout << "check file name to open" << std::endl;
        return 1;
    }
    std::stringstream buffer;
    // 파일 스트림의 내용을 읽어와서 buffer에 넣음
    buffer << openFile.rdbuf();

    // 스트림의 내용을 문자열로 저장
    std::string str = buffer.str();

    // 파일을 닫음
    openFile.close();

    /*--------------문자열 바꾸기------------*/
    // str1을 str2로 바꿈
    std::string str1 = argv[2], str2 = argv[3];
    size_t pos = 0;
    while ((pos = str.find(str1, pos)) != std::string::npos) {
        replaceSubstring(pos, str, str1.length(), str2);
        pos += str2.length();
    }


    /*--------------파일에 담기------------*/
    std::string outputFileName = inputFileName + ".replace";
    char *output = &outputFileName[0];
    // std::ofstream outfile(outputFileName); c++ 11?
    std::ofstream outfile(output);
    if (!outfile.is_open()) {
        std::cerr << "Failed to open output file" << std::endl;
        return 1;
    }

    // std::stringstream의 내용을 파일에 쓰기
    outfile << str;

    // 파일 닫기
    outfile.close();

    std::cout << "Contents have been written to output.txt" << std::endl;
    return 0;
}