#ifndef JSON_OBJECT_HPP
#define JSON_OBJECT_HPP

#include "JsonCore.hpp"
#include "JsonString.hpp"

namespace CppJson
{
    class JsonObject : public ValueBase{
        public:
            JsonObject(const Object_t &val = Object_t());
            ~JsonObject() override;

            std::unique_ptr<ValueBase> clone() const override;
            bool isObject() const override;
            const JsonObject &asObject() const;

            const Value &operator[](const Key_t &key) const;    
            Value &operator[](const Key_t &key);
            const Value &operator[](const char *key) const;
            const Value &operator[](const std::string &key) const;
            Value &operator[](const char *key);
            Value &operator[](const std::string &key);

            const Object_t &toStdMap() const;
            Object_t &toStdMap();

            Value toValue() const override;
        private:
            Object_t val_;
    };
} // namespace CppJson


#endif