#include "JsonParser.hpp"
#include "JsonTypes.hpp"

namespace CppJson{
    JsonParser::JsonParser(const std::vector<Token> &tokens):
        tokens_(tokens),
        cur_pos_(0),
        length_(tokens_.size())
    {
    }
    Value JsonParser::parseTokens()
    {
        Token token = this->currentToken();
        if (token.type() == Token::JsonType::Symbol){
            switch (token.toJsonSymbol())
            {
                case JSON_ARRAY_BEGIN:  return this->parseArray().toValue();
                case JSON_OBJECT_BEGIN: return this->parseObject().toValue();
                case JSON_PARSE_END:    return Value();
                default:                throw SyntaxError("Unknown syntax!");
            }
        }
        else{
            switch (token.type())
            {
                case Token::JsonType::Boolean:  return this->parseBool().toValue();
                case Token::JsonType::Float:    return this->parseFloat().toValue();
                case Token::JsonType::Integer:  return this->parseInt().toValue();
                case Token::JsonType::Null:     return this->parseNull().toValue();
                case Token::JsonType::String:   return this->parseString().toValue();                     
            }
        }
        return Value();
    }

    JsonObject JsonParser::parseObject(){
        // this->advance(); //Skip the '{' token.
        Token token = this->currentToken();
        JsonObject object;
        while (!((token.isJsonSymbol() && token.toJsonSymbol() == JSON_OBJECT_END) || (token.isJsonSymbol() && token.toJsonSymbol() == JSON_PARSE_END))){
            this->advance();
            this->parseObjectItem(object);
            token = this->currentToken();
        }
        //出来时，应该定位在'}'处
        this->advance();
        return object;
    }
    void JsonParser::parseObjectItem(JsonObject &object){
        const Token &key_token = this->currentToken();
        this->advance();
        if (key_token.type() != Token::JsonType::String){
            error("Key is not String type");
        }
        const Token &colon = this->currentToken();
        this->advance();
        if (!(colon.isJsonSymbol() && colon.toJsonSymbol() == JSON_OBJECT_KEY_VALUE_SEPARATION)){
            error ("Expected colon but it does not exist.");
        }
        const Token &value_token = this->currentToken();
        Value val = value_token.value();
        if (value_token.isJsonSymbol()){
            switch (value_token.toJsonSymbol()){
                case JSON_OBJECT_BEGIN:  val = this->parseObject().toValue();    break;
                case JSON_ARRAY_BEGIN: val = this->parseArray().toValue();     break;
                default:                error("Value should not be a JsonSymbol"); break;
            }
        }
        else{
            this->advance(); // 目前在逗号处
        }
        object[key_token.toJsonString()] = val;
    }

    JsonArray JsonParser::parseArray()
    {
        // this->advance(); //Skip the '[' token.
        Token token = this->currentToken();
        JsonArray array;
        while (!((token.isJsonSymbol() && token.toJsonSymbol() == JSON_ARRAY_END) || (token.isJsonSymbol() && token.toJsonSymbol() == JSON_PARSE_END))){
            this->advance();
            this->parseArrayItem(array);
            token = this->currentToken();
        }
        this->advance();
        return array;
    }

    void JsonParser::parseArrayItem(JsonArray &array){
        const Token &value_token = this->currentToken();
        Value val = value_token.value();
        if (value_token.isJsonSymbol()){
            switch (value_token.toJsonSymbol()){
                case JSON_OBJECT_BEGIN:  val = this->parseObject().toValue(); break;
                case JSON_ARRAY_BEGIN: val = this->parseArray().toValue(); break;
                default:    error("Value should not be a JsonSymbol"); break;
            }
        }
        else{
            this->advance(); // 目前在逗号处
        }
        array.emplaceBack(val);
    }

    const Token &CppJson::JsonParser::currentToken() const{
        if (cur_pos_ >= length_){
            return this->tokens_[length_ - 1];
        }
        return this->tokens_[cur_pos_];
    }
    const Token &JsonParser::nextToken() const{ 
        if (cur_pos_ + 1 >= length_){
            return this->tokens_[length_ - 1];
        }
        return this->tokens_[cur_pos_ + 1];
    }
    void JsonParser::error(const std::string &message){
        throw SyntaxError("In the " + std::to_string(cur_pos_) + " pos, happens " + message);
    }
    void JsonParser::advance(){
        if (cur_pos_ < length_){
            ++cur_pos_;
        }
    }

    JsonNull JsonParser::parseNull(){
        const Token &token = this->currentToken();
        if (token.type() != Token::JsonType::Null){
            this->error("Not Null type!");
        }
        this->advance();
        return token.toJsonNull();
    }
    JsonFloat JsonParser::parseFloat(){
        const Token &token = this->currentToken();
        if (token.type() != Token::JsonType::Float){
            this->error("Not Float type!");
        }
        this->advance();
        return token.toJsonFloat();
    }
    JsonInt JsonParser::parseInt(){
        const Token &token = this->currentToken();
        if (token.type() != Token::JsonType::Integer){
            this->error("Not Int type!");
        }
        this->advance();
        return token.toJsonInt();
    }
    JsonString JsonParser::parseString(){
        const Token &token = this->currentToken();
        if (token.type() != Token::JsonType::String)
        {
            this->error("Not String type!");
        }
        this->advance();
        return token.toJsonString();
    }
    JsonBool JsonParser::parseBool(){
        const Token &token = this->currentToken();
        if (token.type() != Token::JsonType::Boolean)
        {
            this->error("Not Bool type!");
        }
        this->advance();
        return token.toJsonBool();
    }

} // namespace CppJson
