#include "JsonString.hpp"

CppJson::JsonString::JsonString(const String_t &val):
    val_(val)
{
}

CppJson::JsonString::JsonString(const char *val):
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

// CppJson::JsonString &CppJson::JsonString::asString()
// {
//     return const_cast<JsonString &>(static_cast<const JsonString &>(*this).asString());
// }

bool CppJson::JsonString::operator<(const JsonString &other) const
{
    return val_ < other.val_;
}

const CppJson::String_t &CppJson::JsonString::toStdString() const
{
    return this->val_;
}

CppJson::String_t &CppJson::JsonString::toStdString()
{
    return this->val_;
}


