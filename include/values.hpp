#ifndef VALUES_HPP
#define VALUES_HPP

#include <stdint.h>
#include <string>
#include <vector>

namespace VM
{
    // This defines the available value types
    // Perhaps we can use the class itself to represent those.
    // Each class have a well defined constructor
    // But what if we want a single value class
    // capable of handling everything itself? Let's use overloading!
    // Looks cleaner :D

    typedef enum : uint8_t {
        VALUE_INTEGER,
        VALUE_FLOAT,
        VALUE_BOOLEAN,
        VALUE_STRING,
        VALUE_LIST
    } ValueType;

    class Value
    {
        public:
            ValueType type;
            union {
                int ivalue;
                float fvalue;
                bool bvalue;
                std::string *svalue;
                std::vector<Value *> *lvalue;
            };

            Value(int value) : ivalue(value), type(VALUE_INTEGER) {}
            Value(float value) : fvalue(value), type(VALUE_FLOAT) {}
            Value(bool value) : bvalue(value), type(VALUE_BOOLEAN) {}
            Value(std::string *value) : svalue(value), type(VALUE_STRING) {}
            Value(std::vector<Value *> *value) : lvalue(value), type(VALUE_LIST) {}

            // This will cast the value to a float
            float to_float();

            // This will cast the value to a string
            std::string to_string();

            // This will perform an addition with another value
            Value *add(Value *b);
    };
}

#endif
