#include "JsonHandler.hpp"

#include <sstream>
#include <fstream>

namespace CppJson{
    CppJson::JsonHandler::JsonHandler():
        reader_(std::make_unique<JsonReader>()),
        parser_(std::make_unique<JsonParser>(std::vector<Token>{})),
        lexer_(std::make_unique<JsonLexer>(""))
    {
    }

    CppJson::JsonHandler::~JsonHandler() = default;

    std::string CppJson::JsonHandler::serialize(const Value &value)
    {
        std::stringstream s;
        s << value;
        json_str_ = s.str();
        return json_str_;
    }

    void JsonHandler::readFile(const std::string &file){
        this->json_str_ = this->reader_->readFromFile(file);
    }

    Value JsonHandler::parse(const std::string &json){
        json_str_ = json;
        return parse();
    }
    Value JsonHandler::parse(){
        this->lexer_->reset(json_str_);
        this->parser_->resetTokens(this->lexer_->parseJson());
        return this->parser_->parseTokens();
    }
    bool JsonHandler::writeJsonToFile(const std::string &file){
        std::fstream f(file);
        if (!f.is_open()){
            return false;
        }
        f << this->json_str_;
        f.close();
        return true;
    }
}
