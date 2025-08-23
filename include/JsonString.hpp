#ifndef JSON_STRING_HPP
#define JSON_STRING_HPP

#include "JsonCore.hpp"
#include <iostream>

namespace CppJson
{
    class JsonString : public ValueBase{
        public:
            JsonString(const String_t &val = String_t());
            JsonString(const char *val);
            ~JsonString() override;

            std::unique_ptr<ValueBase> clone() const override;
            bool isString() const override;
            const JsonString &asString() const override;

            bool operator<(const JsonString &other) const;
            const String_t &toStdString() const;
            String_t &toStdString(); 

        private:
            String_t val_;
    };
} // namespace CppJson


#endif