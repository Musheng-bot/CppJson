#ifndef JSON_CORE_HPP
#define JSON_CORE_HPP

#include "JsonError.hpp"
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <iostream>

namespace CppJson{
    class Value;
    class ValueBase;
    class JsonNull;
    class JsonBool;
    class JsonInt;
    class JsonFloat;
    class JsonString;
    class JsonArray;
    class JsonObject;

    using Bool_t = bool;
    using Float_t = _Float64;
    using Int_t = int64_t;
    using String_t = std::string;
    using Array_t = std::vector<Value>;
    using Key_t = JsonString;
    using Object_t = std::map<Key_t, Value>;
    using Index_t = unsigned long long;

    class Value{
        public:
            Value();
            ~Value();
            Value(const int val);
            Value(const Bool_t val);
            Value(const Int_t val);
            Value(const Float_t val);
            Value(const String_t &val);
            Value(const char *val);
            Value(const Array_t &val);
            Value(const Object_t &val);
            Value(const Value &other);
            Value &operator=(const Value &other);
            Value(Value &&other);
            Value &operator=(Value &&other);

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
            std::unique_ptr<ValueBase> clone() const;

            friend std::ostream &operator<<(std::ostream &out, const Value &value);

        private:
            std::unique_ptr<ValueBase> val_;
    };

    class ValueBase{
        public:
            ValueBase() = default;
            virtual ~ValueBase() = default;
            ValueBase(const ValueBase &) = default;
            ValueBase &operator=(const ValueBase &) = default;
            ValueBase(ValueBase &&) = default;
            ValueBase &operator=(ValueBase &&) = default;

            virtual std::unique_ptr<ValueBase> clone() const = 0;

            virtual bool isNull() const {return false;}
            virtual bool isBool() const {return false;}
            virtual bool isInt() const {return false;}
            virtual bool isFloat() const {return false;}
            virtual bool isString() const {return false;}
            virtual bool isArray() const {return false;}
            virtual bool isObject() const {return false;}

            virtual const JsonNull &asNull() const {throw TypeError("Invalid type : not Null");}
            virtual const JsonBool &asBool() const { throw TypeError("Invalid type : not Bool");}
            virtual const JsonInt &asInt() const { throw TypeError("Invalid type : not Int"); }
            virtual const JsonFloat &asFloat() const { throw TypeError("Invalid type : not Float"); }
            virtual const JsonArray &asArray() const { throw TypeError("Invalid type : not Array"); }
            virtual const JsonString &asString() const { throw TypeError("Invalid type : not String"); }
            virtual const JsonObject &asObject() const { throw TypeError("Invalid type : not Object"); }

            JsonNull &asNull() {return const_cast<JsonNull &>(static_cast<const ValueBase *>(this)->asNull()); }
            JsonBool &asBool() { return const_cast<JsonBool &>(static_cast<const ValueBase *>(this)->asBool()); }
            JsonInt &asInt() {return const_cast<JsonInt &>(static_cast<const ValueBase *>(this)->asInt()); }
            JsonFloat &asFloat() { return const_cast<JsonFloat &>(static_cast<const ValueBase *>(this)->asFloat()); }
            JsonString &asString() { return const_cast<JsonString &>(static_cast<const ValueBase *>(this)->asString()); }
            JsonArray &asArray() { return const_cast<JsonArray &>(static_cast<const ValueBase *>(this)->asArray()); }
            JsonObject &asObject() { return const_cast<JsonObject &>(static_cast<const ValueBase *>(this)->asObject()); }
    };

}

#endif