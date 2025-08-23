#include "JsonLexer.hpp"

#include <math.h>

namespace CppJson{

    void JsonLexer::skipWhiteSpace(){
        char cur_ch = currentChar();
        while(cur_ch != '\0' && isspace(cur_ch)){
            this->advance();
            cur_ch = currentChar();
        }
    }
    char JsonLexer::currentChar() const{
        if (cur_pos_ >= length_){
            return '\0';
        }
        return json_[cur_pos_];
    }
    void JsonLexer::advance()
    {
        if (cur_pos_ < length_){
            cur_pos_++;
        }
    }
    Int_t JsonLexer::strToInt64(const std::string &str, bool negative_sign)
    {
        Int_t num = 0;
        for (const char ch : str){
            num = 10 * num + ch - '0';
        }
        if (negative_sign){
            num *= -1;
        }
        return num;
    }
    Float_t JsonLexer::strToFloat64(const std::string &str, bool negative_sign)
    {
        Float_t num;
        int offset = 0;
        for (auto ch : str){
            if (offset > 0){
                num += (ch - '0') * 1.0 / pow(10, offset);
                ++offset;
            }
            else{
                if (ch == '.'){
                    ++offset;
                    continue;
                }
                num = 10 * num + ch - '0';
            }
        }
        if (negative_sign){
            num *= -1;
        }
        return num;
    }
    JsonLexer::JsonLexer(const std::string &str):
        json_(str),
        length_(json_.size()),
        cur_pos_(0)
    {
    }
    void JsonLexer::reset(){
        cur_pos_ = 0;
        parsed_tokens_.clear();
    }
    const std::vector<Token> &JsonLexer::parseJson()
    {
        try{
            Token token = TokenFactory::getToken(CppJson::Token::JsonType::Symbol, JsonSymbol::JSON_PARSE_END);
            do{
                token = this->nextToken();
                this->parsed_tokens_.emplace_back(token);
            }while((token.isJsonSymbol() && token.toJsonSymbol() != JSON_PARSE_END) || !token.isJsonSymbol());
        }
        catch(const std::exception &e){
            std::cout << e.what() << std::endl;
        }
        return this->parsed_tokens_;
    }
    Token JsonLexer::parseString()
    {
        this->advance();
        pos_t start_pos = this->cur_pos_;
        if (start_pos == length_){
            throw ParseError("Invalid string syntax.");
        }
        char cur_ch = this->currentChar();
        std::string str;

        while(cur_ch != '\0' && cur_ch != JSON_STRING_MARK){
            if (cur_ch == '\\'){
                this->advance();
                cur_ch = currentChar();
                switch (cur_ch)
                {
                case '\\':
                    str += '\\';
                    break;
                case 'n':
                    str += '\n';
                    break;
                case 'r':
                    str += '\r';
                    break;
                case '\"':
                    str += '\"';
                    break;
                case 't':
                    str += '\t';
                    break;
                case 'b':
                    str += '\b';
                    break;
                default:
                    throw ParseError("Invalid string syntax.");
                    break;
                }
            }
            else{
                str += cur_ch;
            }
            this->advance();
            cur_ch = this->currentChar();
        }
        if(cur_ch != '\"'){
            throw ParseError("Invalid string syntax.");
        }
        this->advance();
        return TokenFactory::getToken(Token::JsonType::String, str);
    }
    Token JsonLexer::parseNum(){
        char cur_ch = this->currentChar();
        bool sign = false;
        bool is_float = false;
        if (cur_ch == '-'){
            sign = true;
            this->advance();
            cur_ch = currentChar();
        }
        std::string str_num;
        if (!isdigit(cur_ch)){
            throw ParseError("Parse error during parsing number.");
        }
        while(cur_ch != '\0' && (isdigit(cur_ch) || cur_ch == '.')){
            str_num += cur_ch;
            if (cur_ch == '.'){
                is_float = true;
            }
            this->advance();
            cur_ch = this->currentChar();
        }
        return is_float ? TokenFactory::getToken(Token::JsonType::Float, strToFloat64(str_num, sign)) : TokenFactory::getToken(Token::JsonType::Integer, strToInt64(str_num, sign));
    }
    Token JsonLexer::nextToken()
    {
        this->skipWhiteSpace();
        char cur_ch = this->currentChar();
        switch (cur_ch)
        {
            case JSON_PARSE_END:
                return TokenFactory::getToken(Token::JsonType::Symbol, JSON_PARSE_END);
                break;
            case JSON_OBJECT_BEGIN:
            case JSON_OBJECT_END:
            case JSON_ARRAY_BEGIN:
            case JSON_ARRAY_END:
            case JSON_OBJECT_KEY_VALUE_SEPARATION:
            case JSON_ITEM_SEPARATION:
                this->advance();
                return TokenFactory::getToken(Token::JsonType::Symbol, static_cast<JsonSymbol>(cur_ch));
            case JSON_STRING_MARK:
                return this->parseString();
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
            case '-':
                return this->parseNum();
                break;
            case 't':
            case 'f':
                return this->parseBool();
                break;
            case 'n':
                return this->parseNull();
                break;

            default:
                throw TypeError("Invalid character");
                break;
        }
    }
    Token JsonLexer::parseBool(){
        char cur_ch = this->currentChar();
        if (cur_ch == 't'){
            if (json_.substr(cur_pos_, 4) != "true"){
                throw ParseError("Invalid value to be 'true'.");
            }
            for (int i = 0; i < 4; ++i){
                this->advance();
            }
            return TokenFactory::getToken(Token::JsonType::Boolean, true);
        }
        else if (cur_ch == 'f')
        {
            if (json_.substr(cur_pos_, 5) != "false")
            {
                throw ParseError("Invalid value to be 'false'.");
            }
            for (int i = 0; i < 5; ++i)
            {
                this->advance();
            }
            return TokenFactory::getToken(Token::JsonType::Boolean, false);
        }
        else{
            throw ParseError("Invalid syntax");
        }
    }
    Token JsonLexer::parseNull()
    {
        char cur_ch = this->currentChar();
        if (cur_ch == 'n')
        {
            if (json_.substr(cur_pos_, 4) != "null")
            {
                throw ParseError("Invalid value to be 'null'.");
            }
            for (int i = 0; i < 4; ++i)
            {
                this->advance();
            }
            return TokenFactory::getToken(Token::JsonType::Null);
        }
        else{
            throw ParseError("Invalid syntax");
        }
    }
}
