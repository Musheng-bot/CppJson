#ifndef JSON_FLOAT_HPP
#define JSON_FLOAT_HPP

#include "JsonCore.hpp"

namespace CppJson
{
    class JsonFloat : public ValueBase{
        public:
            JsonFloat(const Float_t val);
            ~JsonFloat() override;
            std::unique_ptr<ValueBase> clone() const override;

            bool isFloat() const override;
            const JsonFloat &asFloat() const override;
        
        private:
            Float_t val_;
    };
} // namespace CppJson


#endif