#ifndef JSON_LEXER_HPP
#define JSON_LEXER_HPP

#include "Token.hpp"
#include "JsonReader.hpp"
#include "JsonCore.hpp"

namespace CppJson{
    class JsonLexer{
            using pos_t = unsigned long long;
        public:
            explicit JsonLexer(const std::string &str);
            void reset(const std::string &str);
            const std::vector<Token> &parseJson();
            Token parseString();
            Token parseNum();
            Token nextToken();
            Token parseBool();
            Token parseNull();

        private:
            std::string json_;
            std::vector<Token> parsed_tokens_;
            pos_t length_;
            pos_t cur_pos_;

            void skipWhiteSpace();
            char currentChar() const;
            void advance();
            static Int_t strToInt64(const std::string &str, bool negative_sign);
            static Float_t strToFloat64(const std::string &str, bool negative_sign);
    };
}

#endif