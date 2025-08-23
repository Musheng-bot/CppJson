#ifndef JSONERROR_HPP
#define JSONERROR_HPP

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
} // namespace CppJson


#endif