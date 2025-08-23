#include "JsonString.hpp"

CppJson::JsonString::JsonString(const String_t &val):
    val_(val)
{
}

CppJson::JsonString::~JsonString() = default;

std::unique_ptr<CppJson::ValueBase> CppJson::JsonString::clone() const
{
    return std::make_unique<JsonString>(this->val_);
}

bool CppJson::JsonString::isString() const
{
    return true;
}

const CppJson::JsonString &CppJson::JsonString::asString() const
{
    return *this;
}
