#ifndef JSON_FLOAT_HPP
#define JSON_FLOAT_HPP

#include "JsonCore.hpp"

namespace CppJson
{
    class JsonFloat : public ValueBase{
        public:
            JsonFloat(const Float_t val = 0.0);
            ~JsonFloat() override;
            std::unique_ptr<ValueBase> clone() const override;

            bool isFloat() const override;
            const JsonFloat &asFloat() const override;
            const Float_t toStdFloat() const;

            Value toValue() const override;
        private:
            Float_t val_;
    };
} // namespace CppJson


#endif