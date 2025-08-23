#include "JsonInt.hpp"

namespace CppJson
{
    JsonInt::JsonInt(const Int_t val):
        val_(val)
    {}
    JsonInt::~JsonInt() = default;
    std::unique_ptr<ValueBase> JsonInt::clone() const
    {
        return std::make_unique<JsonInt>(this->val_);
    }
    bool JsonInt::isInt() const
    {
        return true;
    }
    const JsonInt &JsonInt::asInt() const
    {
        return *this;
    }
} // namespace CppJson
