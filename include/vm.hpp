#ifndef VM_HPP
#define VM_HPP

#include "values.hpp"
#include "program.hpp"

#define STACK_SIZE 256

namespace VM
{
    class Instance
    {
        public:
            // We define the virtual machine stack here
            // The stack will begin empty and will be filled
            // when a OP_CONSTANT comes in
            Value *stack[STACK_SIZE];

            // The stack pointer points to the first AVAILABLE position
            // Keep that in mind
            uint32_t stack_pointer;

            // We define the virtual machine program here
            // This is the program to be executed :)
            Program *program;
            uint32_t program_counter;

            Instance() : stack_pointer(0) {}

            // This will pop the last value on the stack and return it
            Value *pop();

            // This will push a new value to the stack
            void push(Value *value);

            // This is the entrypoint of the virtual machine, this is where
            // it will start running all the opcodes provided
            void run();

    };
}

#endif
