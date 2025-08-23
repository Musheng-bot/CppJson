#include "JsonBool.hpp"

CppJson::JsonBool::JsonBool(const Bool_t val):
    val_(val)
{
}

CppJson::JsonBool::~JsonBool() = default;

std::unique_ptr<CppJson::ValueBase> CppJson::JsonBool::clone() const
{
    return std::make_unique<JsonBool>(this->val_);
}

bool CppJson::JsonBool::isBool() const
{
    return true;
}

const CppJson::JsonBool &CppJson::JsonBool::asBool() const
{
    return *this;
}
