#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "code.hpp"
#include "values.hpp"
#include <vector>

namespace VM
{
    class Program
    {
        public:
            // This represents our program code
            std::vector<uint32_t> code;

            // Apart from the program code itself, we need
            // a constant pool to push all the values
            std::vector<Value *> constants;

            Program() {}
            Program(std::vector<uint32_t> code) : code(code) {}
            Program(std::vector<uint32_t> code, std::vector<Value *> constants) : code(code), constants(constants) {}

            // The following function adds a new code to the operations to be done
            // It returns void since no additional info is needed.
            void add_op_code(uint32_t code);

            // Similar to the add_op_code I'll define:
            void add_constant_code(Value *value);

            // The following function adds a new value to the constant pool and
            // returns a valid index position
            uint32_t add_constant(Value *value);

            // This will output all the current operations to be performed
            void debug();
    };
}

#endif
