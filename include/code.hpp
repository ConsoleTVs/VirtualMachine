#ifndef CODE_HPP
#define CODE_HPP

#include <stdint.h>
#include <string>

namespace VM
{
    // The virtual machine code (opcodes) will be defined here

    typedef enum : uint32_t {
        OP_CONSTANT,
        OP_ADD,
        OP_SUB,
        OP_MUL,
        OP_DIV,
        OP_PRINT,
        OP_EXIT
    } Code;

    // Simple way to print enums :)
    const std::string CodeString[] = {
        "OP_CONSTANT",
        "OP_ADD",
        "OP_SUB",
        "OP_MUL",
        "OP_DIV",
        "OP_PRINT",
        "OP_EXIT"
    };
}

#endif
