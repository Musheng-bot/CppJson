#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "JsonCore.hpp"

namespace CppJson{

    enum JsonSymbol
    {
        JSON_OBJECT_BEGIN = '{',
        JSON_OBJECT_END = '}',
        JSON_ARRAY_BEGIN = '[',
        JSON_ARRAY_END = ']',
        JSON_STRING_MARK = '\"',
        JSON_OBJECT_KEY_VALUE_SEPARATION = ':',
        JSON_ITEM_SEPARATION = ',',
        JSON_SPACE = ' ',
        JSON_CHANGE_LINE = '\n',
        JSON_PARSE_END = '\0',
    };

    class Token{
        public:

            enum class JsonType
            {
                Symbol,  // JsonSymbol类型
                Integer, // 整型
                Float,   // 浮点型
                Boolean, // 布尔型
                Null,    // NULL
                String,  // 字符串型
            };
            
            Token(JsonType type, const Value &value);
            ~Token();

            const JsonType type() const;
            const Value &value() const;
            JsonBool toJsonBool() const;
            JsonFloat toJsonFloat() const;
            JsonInt toJsonInt() const;
            JsonString toJsonString() const;
            JsonNull toJsonNull() const;
            JsonSymbol toJsonSymbol() const;

            bool isJsonSymbol() const;

        private:
            JsonType type_; //标识Token类型
            Value value_;
    };

    class TokenFactory{
        public:
            static Token getToken(const Token::JsonType type, const JsonSymbol symbol);
            static Token getToken(const Token::JsonType type, const bool boolean);
            static Token getToken(const Token::JsonType type, const Int_t integer);
            static Token getToken(const Token::JsonType type, const Float_t num);
            static Token getToken(const Token::JsonType type);
            static Token getToken(const Token::JsonType type, const char *str);
            static Token getToken(const Token::JsonType type, const std::string &str);
            static Token getToken(const Token::JsonType type, const int integer);
        };
}

#endif