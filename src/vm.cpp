#include "../include/vm.hpp"

#define GET_INSTRUCTION(pc) this->program->code.at(pc)

using namespace VM;

Value *Instance::pop()
{
    // We need to decrement it BEFORE we get the value
    // since the stack pointer points to the first
    // available position
    return this->stack[--stack_pointer];
}

void Instance::push(Value *value)
{
    // To push a new value to the stack we
    // just need to add it to the stack_pointer position
    // and further increment it afterwards
    this->stack[stack_pointer++] = value;
}

static std::string *multiplyString(std::string *a, uint32_t times)
{
    auto result = new std::string("");
    for (; times > 0; times--) result->append(*a);

    return result;
}

void Instance::run()
{
    this->program_counter = 0;
    // The run basically is a big loop with a switch inside
    // We stop the loop when the exit OPCODE is found.
    for (uint32_t instruction;;this->program_counter++) {
        // Get need a way to get the instruction that we need to run
        // thus we need a program counter :)
        // This will get the current executing instruction
        instruction = GET_INSTRUCTION(this->program_counter);

        // Let's define what our opcodes actually do!
        switch (instruction) {
            case OP_CONSTANT: {
                // We add a new constant to the stack.
                // We got the index of the constant pool in the next program_counter
                //
                push(this->program->constants.at(GET_INSTRUCTION(++this->program_counter)));
                break;
            }
            case OP_ADD: {
                // We pop the last 2 values on the stack and further perform an addition
                Value *a = this->pop();
                Value *b = this->pop();

                // The following addition need to be done by a separate action, since two classes cannot be added!
                // We need a way to add two separate values of diferent types. An example would be to define them in
                // the class. As we defined a to_float method, we can now push a new value to the stack that's the
                // addition of the 2 poped values as a float. Keep in mind it's b - a, not a - b because of how
                // a stack works. First in, last out!

                // Check if you're adding a string at some of the operans:
                if (a->type == VALUE_STRING || b->type == VALUE_STRING) push(new Value(new std::string(b->to_string() + a->to_string())));
                else push(new Value(b->to_float() + a->to_float()));

                break;
            }
            case OP_SUB: {
                // We pop the last 2 values on the stack and further perform a substraction
                Value *a = this->pop();
                Value *b = this->pop();

                push(new Value(b->to_float() - a->to_float()));
                break;
            }
            case OP_MUL: {
                // We pop the last 2 values on the stack and further perform a multiplication
                Value *a = this->pop();
                Value *b = this->pop();

                // Check if we want to multiply a string.
                if (b->type == VALUE_STRING && a->type == VALUE_STRING) { printf("Can't multiply two strings\n"); return; }
                else if (b->type == VALUE_STRING) push(new Value(multiplyString(b->svalue, a->to_float())));
                else if (a->type == VALUE_STRING) push(new Value(multiplyString(a->svalue, b->to_float())));
                else push(new Value(b->to_float() * a->to_float()));

                break;
            }
            case OP_DIV: {
                // We pop the last 2 values on the stack and further perform a division
                Value *a = this->pop();
                Value *b = this->pop();

                // Keep in mind a division by 0 cannot be performed.
                // Let's check to avoid that:
                if (a->to_float() == 0) {
                    printf("A division by 0 was found. Aborting.\n");
                    return;
                }

                push(new Value(b->to_float() * a->to_float()));
                break;
            }
            case OP_PRINT: {
                // When the print opcode is found, we pop and print the last
                // value on the stack. So we need a way to represent the values as string
                auto value = pop();
                printf("%s\n", value->to_string().c_str());
                break;
            }
            case OP_EXIT: { return; }
        }
    }
}
