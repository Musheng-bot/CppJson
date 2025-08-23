#include "JsonFloat.hpp"

CppJson::JsonFloat::JsonFloat(const Float_t val):
    val_(val)
{
}

CppJson::JsonFloat::~JsonFloat() = default;

std::unique_ptr<CppJson::ValueBase> CppJson::JsonFloat::clone() const
{
    return std::make_unique<JsonFloat>(this->val_);
}

bool CppJson::JsonFloat::isFloat() const
{
    return true;
}

const CppJson::JsonFloat &CppJson::JsonFloat::asFloat() const
{
    return *this;   
}
