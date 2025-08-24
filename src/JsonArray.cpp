#include "JsonArray.hpp"

CppJson::JsonArray::JsonArray(const Array_t &val):
    val_(val)
{
}

CppJson::JsonArray::~JsonArray() = default;

std::unique_ptr<CppJson::ValueBase> CppJson::JsonArray::clone() const{
    return std::make_unique<JsonArray>(this->val_);
}

bool CppJson::JsonArray::isArray() const{
    return true;
}

const CppJson::JsonArray &CppJson::JsonArray::asArray() const{
    return *this;
}

// CppJson::JsonArray &CppJson::JsonArray::asArray(){
//     return const_cast<JsonArray &>(static_cast<const JsonArray &>(*this).asArray());
// }

CppJson::Value &CppJson::JsonArray::operator[](const Index_t index)
{
    return const_cast<Value &>(static_cast<const JsonArray &>(*this)[index]);
}

void CppJson::JsonArray::emplaceBack(const Value &value){
    this->val_.emplace_back(value);
}

const CppJson::Value &CppJson::JsonArray::operator[](const Index_t index) const
{
    return this->val_[index];
}

const std::vector<CppJson::Value> &CppJson::JsonArray::toStdVector() const
{
    return this->val_;
}

std::vector<CppJson::Value> &CppJson::JsonArray::toStdVector()
{
    return const_cast<std::vector<Value> &>(static_cast<const JsonArray &>(*this).toStdVector());
}

CppJson::Value CppJson::JsonArray::toValue() const{
    return Value(this->toStdVector());
}
