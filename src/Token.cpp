#include "Token.hpp"

#include "JsonBool.hpp"
#include "JsonFloat.hpp"
#include "JsonInt.hpp"
#include "JsonNull.hpp"
#include "JsonString.hpp"
#include "JsonError.hpp"

namespace CppJson{
    Token::Token(JsonType type, const Value &value):
        type_(type),
        value_(value)
    {
    }
    Token::~Token() = default;
    const Token::JsonType Token::type() const
    {
        return this->type_;
    }
    const Value &Token::value() const{
        return this->value_;
    }
    JsonBool Token::toJsonBool() const{
        return this->value_.asBool();
    }
    JsonFloat Token::toJsonFloat() const
    {
        return value_.asFloat();
    }
    JsonInt Token::toJsonInt() const
    {
        return value_.asInt();
    }
    JsonString Token::toJsonString() const
    {
        if(type() == JsonType::String){
            throw TypeError("Not String");
        }
        return value_.asString();
    }
    JsonNull Token::toJsonNull() const
    {
        return value_.asNull();
    }
    JsonSymbol Token::toJsonSymbol() const
    {
        if (!isJsonSymbol()){
            throw TypeError("Not Symbol!");
        }
        return static_cast<JsonSymbol>(value_.asString().toStdString()[0]);
    }
    bool Token::isJsonSymbol() const
    {
        return this->type() == Token::JsonType::Symbol;
    }
    Token TokenFactory::getToken(const Token::JsonType type, const JsonSymbol symbol)
    {
        return Token(type, Value(std::string(1, static_cast<char>(symbol))));
    }
    Token TokenFactory::getToken(const Token::JsonType type, const bool boolean)
    {
        return Token(type, Value(boolean));
    }
    Token TokenFactory::getToken(const Token::JsonType type, const Int_t integer)
    {
        return Token(type, Value(integer));
    }
    Token TokenFactory::getToken(const Token::JsonType type, const Float_t num)
    {
        return Token(type, Value(num));
    }
    Token TokenFactory::getToken(const Token::JsonType type)
    {
        return Token(type, Value());
    }
    Token TokenFactory::getToken(const Token::JsonType type, const char *str)
    {
        return Token(type, Value(str));
    }
    Token TokenFactory::getToken(const Token::JsonType type, const std::string &str)
    {
        return Token(type, Value(str));
    }
    Token TokenFactory::getToken(const Token::JsonType type, const int integer)
    {
        return Token(type, Value(integer));
    }
}
