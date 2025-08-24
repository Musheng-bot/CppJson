#ifndef JSON_ERROR_HPP
#define JSON_ERROR_HPP

#include <stdexcept>

namespace CppJson
{
    class TypeError : public std::runtime_error{
        public:
            using std::runtime_error::runtime_error;
    };

    class IndexError : public std::runtime_error{
        public:
            using std::runtime_error::runtime_error;
    };

    class KeyError : public std::runtime_error
    {
        public:
            using std::runtime_error::runtime_error;
    };

    class ParseError : public std::runtime_error{
        public:
            using std::runtime_error::runtime_error;
    };

    class SyntaxError : public std::runtime_error{
        public:
            using std::runtime_error::runtime_error;
    };
} // namespace CppJson


#endif