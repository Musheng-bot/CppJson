#ifndef JSON_STRING_HPP
#define JSON_STRING_HPP

#include "JsonCore.hpp"

namespace CppJson
{
    class JsonString : public ValueBase{
        public:
            JsonString(const String_t &val);
            ~JsonString() override;

            std::unique_ptr<ValueBase> clone() const override;
            bool isString() const override;
            const JsonString &asString() const override;
        private:
            String_t val_;
    };
} // namespace CppJson


#endif