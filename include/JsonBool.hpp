#ifndef JSON_BOOL_HPP
#define JSON_BOOL_HPP

#include "JsonCore.hpp"

namespace CppJson
{
    class JsonBool : public ValueBase
    {
        public:
            JsonBool(const Bool_t val);
            ~JsonBool() override;
            std::unique_ptr<ValueBase> clone() const override;

            bool isBool() const override;
            const JsonBool &asBool() const override;
        
        private:
            bool val_;
    };
} // namespace CppJson

#endif