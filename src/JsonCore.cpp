#include "JsonCore.hpp"
#include "JsonBool.hpp"
#include "JsonArray.hpp"
#include "JsonObject.hpp"
#include "JsonFloat.hpp"
#include "JsonInt.hpp"

namespace CppJson{
    std::ostream &operator<<(std::ostream &out, const CppJson::Value &value)
    {
        if (value.isNull()){
            out << "null ";
        }
        else if (value.isBool()){
            out << ( value.asBool().toStdBool() ? "true " : "false ");
        }
        else if (value.isFloat()){
            out << value.asFloat().toStdFloat() << ' ';
        }
        else if (value.isInt()){
            out << value.asInt().toStdInt() << ' ';
        }
        else if (value.isString()){
            out << '\"' << value.asString().toStdString() << '\"' << ' ';
        }
        else if (value.isArray()){
            const CppJson::Array_t &vec = value.asArray().toStdVector();
            out << '[';
            int i = 0;
            for (const Value &val : vec){
                if (i == 0){
                    out << val;
                }
                else{
                    out << ',' << ' ' << val;
                }
                ++i;
            }
            out << ']' << ' ';
        }
        else if (value.isObject()){
            const CppJson::Object_t &m = value.asObject().toStdMap();
            out << '{';
            int i = 0;
            for (const auto &pair : m){
                if (i == 0){
                    out << '\"' << pair.first.asString().toStdString() << '\"' << " : " << pair.second;
                }
                else{
                    out << ',' << ' ' << '\"' << pair.first.asString().toStdString() << '\"' << " : " << pair.second << ' ';
                }
                ++i;
            }
            out << '}';
        }
        return out;
    }

}