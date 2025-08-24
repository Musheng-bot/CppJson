#ifndef JSON_PARSER_HPP
#define JSON_PARSER_HPP

//Json Parser是一个解析器，接受Token序列，然后输出JSON_OBJECT

#include "JsonCore.hpp"
#include "Token.hpp"

namespace CppJson{
    class JsonParser{
            using pos_t = unsigned long long;
        public:
            explicit JsonParser(const std::vector<Token> &tokens);
            Value parseTokens();
            JsonObject parseObject();
            void parseObjectItem(JsonObject &object);
            JsonArray parseArray();
            void parseArrayItem(JsonArray &array);
            JsonBool parseBool();
            JsonInt parseInt();
            JsonFloat parseFloat();
            JsonNull parseNull();
            JsonString parseString();
            const Token &currentToken() const;
            const Token &nextToken() const;
            void error(const std::string &message);
            void advance();
        
        private:
            std::vector<Token> tokens_;
            pos_t cur_pos_;
            pos_t length_;
    };
} // namespace CppJson


#endif