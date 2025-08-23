#include "Value.hpp"

#include "JsonNull.hpp"
#include "JsonInt.hpp"
#include "JsonBool.hpp"
#include "JsonString.hpp"
#include "JsonArray.hpp"
#include "JsonObject.hpp"
#include "JsonFloat.hpp"

namespace CppJson
{
    Value::Value():
        val_(std::make_unique<JsonNull>())
    {
    }

    Value::~Value() = default;

    Value::Value(const Bool_t val):
        val_(std::make_unique<JsonBool>(val))
    {
    }

    Value::Value(const Int_t val):
        val_(std::make_unique<JsonInt>(val))
    {
    }

    Value::Value(const Float_t val):
        val_(std::make_unique<JsonFloat>(val))
    {
    }

    Value::Value(const String_t val)
    {
    }

    Value::Value(const Array_t val)
    {
    }

    Value::Value(const Object_t val)
    {
    }

    bool Value::isNull() const{
        return val_->isNull();
    }

} // namespace CppJson
