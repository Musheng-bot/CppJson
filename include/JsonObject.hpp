#ifndef JSON_OBJECT_HPP
#define JSON_OBJECT_HPP

namespace CppJson
{
    class JsonObject : public ValueBase{
        public:
            JsonObject(const Object_t &val);
            ~JsonObject() override;

            std::unique_ptr<ValueBase> clone() const override;
            bool isObject() const override;
            const JsonObject &asObject() const;

            const Value &operator[](const Key_t &key) const;    
            Value &operator[](const Key_t &key);

        private:
            Object_t val_;
    };
} // namespace CppJson


#endif