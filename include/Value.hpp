#ifndef VALUE_HPP
#define VALUE_HPP

#include "JsonCore.hpp"

namespace CppJson
{

    class Value final
    {
        public:
            Value();
            ~Value();
            Value(const Bool_t val);
            Value(const Int_t val);
            Value(const Float_t val);
            Value(const String_t val);
            Value(const Array_t val);
            Value(const Object_t val);

            bool isNull() const;
            bool isBool() const;
            bool isInt() const;
            bool isFloat() const;
            bool isString() const;
            bool isArray() const;
            bool isObject() const;

            const JsonNull &asNull() const;
            const JsonBool &asBool() const;
            const JsonInt &asInt() const;
            const JsonFloat &asFloat() const;
            const JsonArray &asArray() const;
            const JsonString &asString() const;
            const JsonObject &asObject() const;

            JsonNull &asNull();
            JsonBool &asBool();
            JsonInt &asInt();
            JsonFloat &asFloat();
            JsonString &asString();
            JsonArray &asArray();
            JsonObject &asObject();

        private:
            std::unique_ptr<ValueBase> val_;
    };

} // namespace CppJson


#endif