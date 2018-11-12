#include "../include/program.hpp"

using namespace VM;

void Program::add_op_code(uint32_t code)
{
    this->code.push_back(code);
}

void Program::add_constant_code(Value *value)
{
    this->add_op_code(this->add_constant(value));
}

uint32_t Program::add_constant(Value *value)
{
    this->constants.push_back(value);

    // This returns the index where it was placed...
    return this->constants.size() - 1;
}

void Program::debug()
{
    for (uint32_t i = 0; i < this->code.size(); i++) {
        if (this->code[i] == OP_CONSTANT) {
            printf("%s ", CodeString[this->code[i++]].c_str());
            printf("%s\n", this->constants[this->code[i]]->to_string().c_str());
        } else printf("%s\n", CodeString[this->code[i]].c_str());
    }
}
