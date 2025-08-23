#ifndef JSON_CORE_HPP
#define JSON_CORE_HPP

#include "JsonError.hpp"
#include <memory>
#include <vector>
#include <map>
#include <string>

namespace CppJson{
    class Value;
    class JsonNull;
    class JsonBool;
    class JsonInt;
    class JsonFloat;
    class JsonString;
    class JsonArray;
    class JsonObject;

    using Key_t = JsonString;
    using Bool_t = bool;
    using Float_t = _Float64;
    using Int_t = int64_t;
    using String_t = std::string;
    using Array_t = std::vector<Value>;
    using Object_t = std::map<Key_t, Value>;
    using Index_t = unsigned long long;
    

    class ValueBase{
        public:
            ValueBase() = default;
            virtual ~ValueBase() = default;
            ValueBase(const ValueBase &) = delete;
            ValueBase &operator=(const ValueBase &) = delete;
            ValueBase(ValueBase &&) = delete;
            ValueBase &operator=(ValueBase &&) = delete;

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

            JsonNull &asNull() {return const_cast<JsonNull &>(static_cast<const ValueBase &>(*this).asNull()); }
            JsonBool &asBool() { return const_cast<JsonBool &>(static_cast<const ValueBase &>(*this).asBool()); }
            JsonInt &asInt() {return const_cast<JsonInt &>(static_cast<const ValueBase &>(*this).asInt()); }
            JsonFloat &asFloat() { return const_cast<JsonFloat &>(static_cast<const ValueBase &>(*this).asFloat()); }
            JsonString &asString() { return const_cast<JsonString &>(static_cast<const ValueBase &>(*this).asString()); }
            JsonArray &asArray() { return const_cast<JsonArray &>(static_cast<const ValueBase &>(*this).asArray()); }
            JsonObject &asObject() { return const_cast<JsonObject &>(static_cast<const ValueBase &>(*this).asObject()); }
    };

}

#endif //JSON_CORE_HPP