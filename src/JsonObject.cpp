#include "JsonObject.hpp"
#include "JsonString.hpp"
// #include "Value.hpp"

CppJson::JsonObject::JsonObject(const Object_t &val):
    val_(val)
{
}

CppJson::JsonObject::~JsonObject() = default;

std::unique_ptr<CppJson::ValueBase> CppJson::JsonObject::clone() const
{
    return std::make_unique<JsonObject>(this->val_);
}

bool CppJson::JsonObject::isObject() const
{
    return true;
}

const CppJson::JsonObject &CppJson::JsonObject::asObject() const{
    return *this;
}

const CppJson::Value &CppJson::JsonObject::operator[](const Key_t &key) const
{
    auto it = this->val_.find(key);
    if(it == this->val_.end()){
        throw KeyError("Invalid key!");
    }
    return it->second;
}

CppJson::Value &CppJson::JsonObject::operator[](const Key_t &key)
{
    return this->val_[key];
}

const CppJson::Value &CppJson::JsonObject::operator[](const char *key) const{
    return (*this)[JsonString(key)];
}

const CppJson::Value &CppJson::JsonObject::operator[](const std::string &key) const{
    return (*this)[JsonString(key)];
}

CppJson::Value &CppJson::JsonObject::operator[](const char *key){
    return (*this)[JsonString(key)];
}

CppJson::Value &CppJson::JsonObject::operator[](const std::string &key){
    return (*this)[JsonString(key)];
}

const CppJson::Object_t &CppJson::JsonObject::toStdMap() const
{
    return this->val_;
}

CppJson::Object_t &CppJson::JsonObject::toStdMap(){
    return const_cast<Object_t &>(static_cast<const JsonObject *>(this)->toStdMap());
}

CppJson::Value CppJson::JsonObject::toValue() const{
    return Value(this->toStdMap());
}
