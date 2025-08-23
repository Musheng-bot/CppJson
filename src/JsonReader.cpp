#include "JsonReader.hpp"

#include <iostream>
#include <fstream>

namespace CppJson{

    std::string JsonReader::readFromFile(const std::string &file_name)
    {
        std::ifstream file(file_name, std::ios::binary);
        if (!file){
            throw std::runtime_error("无法打开文件");
        }

        // 使用迭代器从流中读取所有字符
        return std::string(
            std::istreambuf_iterator<char>(file),
            std::istreambuf_iterator<char>() // 迭代器结束标志
        );
    }
}