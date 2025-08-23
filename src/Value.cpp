#include "JsonCore.hpp"
#include "JsonNull.hpp"
#include "JsonInt.hpp"
#include "JsonBool.hpp"
#include "JsonString.hpp"
#include "JsonArray.hpp"
#include "JsonObject.hpp"
#include "JsonFloat.hpp"
#include <iostream>

namespace CppJson
{
    Value::Value():
        val_(std::make_unique<JsonNull>())
    {
    }
    Value::~Value() = default;
    Value::Value(const int val):
        val_(std::make_unique<JsonInt>(val))
    {
    }
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
    Value::Value(const String_t &val):
        val_(std::make_unique<JsonString>(val))
    {
    }
    Value::Value(const char *val):
        val_(std::make_unique<JsonString>(val))
    {
    }
    Value::Value(const Array_t &val) : val_(std::make_unique<JsonArray>(val))
    {
    }
    Value::Value(const Object_t &val):
        val_(std::make_unique<JsonObject>(val))
    {
    }
    Value::Value(const Value &other):
        val_(other.clone())
    {
    }
    Value &Value::operator=(const Value &other)
    {
        if (&other == this){
            return *this;
        }
        this->val_ = other.clone();
        return *this;
    }
    Value::Value(Value &&other):
        val_(other.clone())
    {
    }
    Value &Value::operator=(Value &&other)
    {
        this->val_ = other.clone();
        return *this;
    }

    bool Value::isNull() const{
        return val_->isNull();
    }
    bool Value::isBool() const{
        return val_->isBool();
    }
    bool Value::isInt() const{
        return val_->isInt();
    }
    bool Value::isFloat() const{
        return val_->isFloat();
    }
    bool Value::isString() const{
        return val_->isString();
    }
    bool Value::isArray() const{
        return val_->isArray();
    }
    bool Value::isObject() const{
        return val_->isObject();
    }

    const JsonNull &Value::asNull() const{
        return val_->asNull();
    }
    const JsonBool &Value::asBool() const{
        return val_->asBool();
    }
    const JsonInt &Value::asInt() const{
        return val_->asInt();
    }
    const JsonFloat &Value::asFloat() const{
        return val_->asFloat();
    }
    const JsonString &Value::asString() const{
        return val_->asString();
    }
    const JsonArray &Value::asArray() const{
        return val_->asArray();
    }
    const JsonObject &Value::asObject() const{
        return val_->asObject();
    }

    JsonNull &Value::asNull(){
        return const_cast<JsonNull &>(static_cast<const Value &>(*this).asNull());
    }
    JsonBool &Value::asBool(){
        return const_cast<JsonBool &>(static_cast<const Value &>(*this).asBool());
    }
    JsonString &Value::asString(){
        return const_cast<JsonString &>(static_cast<const Value &>(*this).asString());
    }
    JsonInt &Value::asInt(){
        return const_cast<JsonInt &>(static_cast<const Value &>(*this).asInt());
    }
    JsonFloat &Value::asFloat(){
        return const_cast<JsonFloat &>(static_cast<const Value &>(*this).asFloat());
    }
    JsonArray &Value::asArray(){
        return const_cast<JsonArray &>(static_cast<const Value &>(*this).asArray());
    }
    JsonObject &Value::asObject(){
        return const_cast<JsonObject &>(static_cast<const Value &>(*this).asObject());
    }

    std::unique_ptr<CppJson::ValueBase> Value::clone() const{
        return val_->clone();
    }

} // namespace CppJson
