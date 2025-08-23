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

CppJson::Value &CppJson::JsonArray::operator[](const Index_t index)
{
    return const_cast<Value &>(static_cast<const JsonArray &>(*this)[index]);
}

const CppJson::Value &CppJson::JsonArray::operator[](const Index_t index) const
{
    return this->val_[index];
}
