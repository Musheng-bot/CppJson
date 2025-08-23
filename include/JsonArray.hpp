#ifndef JSON_ARRAY_HPP
#define JSON_ARRAY_HPP

#include "JsonCore.hpp"

namespace CppJson{
    class JsonArray : public ValueBase{
        public:
            JsonArray(const Array_t &val);
            ~JsonArray() override;

            std::unique_ptr<ValueBase> clone() const override;
            bool isArray() const;
            const JsonArray &asArray() const override;

            Value &operator[](const Index_t index);
            const Value &operator[](const Index_t index) const;

        private:
            Array_t val_;
    };
    
}

#endif //JSON_ARRAY_HPP