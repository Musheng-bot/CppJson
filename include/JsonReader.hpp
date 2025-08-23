#ifndef JSON_READER_HPP
#define JSON_READER_HPP

#include <string>

//接受一个来源，然后返还一个Json字符串

namespace CppJson
{
    class JsonReader
    {
    public:
        std::string readFromFile(const std::string &file_name);
    };
} // namespace CppJson


#endif