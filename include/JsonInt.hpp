#ifndef JSON_INT_HPP
#define JSON_INT_HPP

#include "JsonCore.hpp"

namespace CppJson
{
    class JsonInt : public ValueBase{
        public:
            JsonInt(const Int_t val = 0);
            JsonInt(const int val);
            ~JsonInt() override;
            std::unique_ptr<ValueBase> clone() const  override;

            bool isInt() const override;
            const JsonInt &asInt() const override;
            const Int_t toStdInt() const;
        private:
            Int_t val_;
    };
} // namespace CppJson


#endif 