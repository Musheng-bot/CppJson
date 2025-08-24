#ifndef JSON_HANDLER_HPP
#define JSON_HANDLER_HPP

#include "JsonParser.hpp"
#include "JsonReader.hpp"
#include "JsonLexer.hpp"
#include <memory>

namespace CppJson{
    class JsonHandler{
        public:
            JsonHandler();
            ~JsonHandler();

            std::string serialize(const Value &value);
            void readFile(const std::string &file);
            Value parse(const std::string &json);
            Value parse();
            bool writeJsonToFile(const std::string &file);

        private:
            std::unique_ptr<JsonReader> reader_;
            std::unique_ptr<JsonParser> parser_;
            std::unique_ptr<JsonLexer> lexer_;
            std::string json_str_;
    };
}

#endif