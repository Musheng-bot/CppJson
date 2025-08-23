#ifndef JSON_NULL_HPP
#define JSON_NULL_HPP

#include "JsonCore.hpp"

namespace CppJson
{
    class JsonNull : public ValueBase{
        public:
            JsonNull();
            ~JsonNull() override;
            std::unique_ptr<ValueBase> clone() const override;

            bool isNull() const override;
            const JsonNull &asNull() const override;
    };
} // namespace CppJson


#endif