#include "../include/values.hpp"

using namespace VM;

float Value::to_float()
{
    switch (this->type) {
        case VALUE_INTEGER: { return (float) this->ivalue; }
        case VALUE_FLOAT: { return (float) this->fvalue; }
        case VALUE_BOOLEAN: { return this->bvalue ? 1 : 0; }
        case VALUE_STRING: { return (float) this->svalue->length(); }
        case VALUE_LIST: { return (float) this->lvalue->size(); }
        default: { printf("Error converting value to int.\n"); }
    }
}

std::string Value::to_string()
{
    switch (this->type) {
        case VALUE_INTEGER: { return std::to_string(this->ivalue); }
        case VALUE_FLOAT: { return std::to_string(this->fvalue); }
        case VALUE_BOOLEAN: { return std::to_string(this->bvalue ? 1 : 0); }
        case VALUE_STRING: { return *this->svalue; }
        case VALUE_LIST: {
            // Printing a list is a bit more elaborate :)
            std::string result = "[";

            for (auto element : *this->lvalue) {
                result += element->to_string() + ", ";
            }

            // This will pop the last ',' and the ' '
            result.pop_back(); result.pop_back();

            return result + "]";
        }
        default: { printf("Error converting value to int.\n"); }
    }
}
