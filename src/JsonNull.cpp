#include "JsonNull.hpp"
#include "JsonInt.hpp"

CppJson::JsonNull::JsonNull() = default;

CppJson::JsonNull::~JsonNull() = default;

std::unique_ptr<CppJson::ValueBase> CppJson::JsonNull::clone() const
{
    return std::make_unique<JsonNull>();
}

bool CppJson::JsonNull::isNull() const
{
    return true;
}

const CppJson::JsonNull &CppJson::JsonNull::asNull() const
{
    return *this;
}
