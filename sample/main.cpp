#include "../include/vm.hpp"
#include <stdio.h>

int main()
{
    auto virtual_machine = new VM::Instance();

    // We can manually add the opcodes using
    // the virtual_machine->add_op_code() function
    // or pass the whole code as a parameter
    auto program = new VM::Program();

    // Let's define the opcodes of our program

    // Multiply 10 by 10
    // SHould print this:
    // 100.000000
    program->add_op_code(VM::OP_CONSTANT);
    program->add_constant_code(new VM::Value(10));
    program->add_op_code(VM::OP_CONSTANT);
    program->add_constant_code(new VM::Value(10));
    program->add_op_code(VM::OP_MUL);
    program->add_op_code(VM::OP_PRINT);

    // Multiply a string by 2
    // SHould print this:
    // ABCABC
    program->add_op_code(VM::OP_CONSTANT);
    program->add_constant_code(new VM::Value(new std::string("ABC")));
    program->add_op_code(VM::OP_CONSTANT);
    program->add_constant_code(new VM::Value(2));
    program->add_op_code(VM::OP_MUL);
    program->add_op_code(VM::OP_PRINT);

    // Print a list constant (a bit messy I know)
    // Should print this:
    // [1, Hello, 0, 5.100000, [1, 2, 3]]
    program->add_op_code(VM::OP_CONSTANT);
    program->add_constant_code(new VM::Value(new std::vector<VM::Value *>({
        new VM::Value(1),
        new VM::Value(new std::string("Hello")),
        new VM::Value(false),
        new VM::Value((float) 5.10),
        new VM::Value(new std::vector<VM::Value *>({ new VM::Value(1), new VM::Value(2), new VM::Value(3), })),
    })));
    program->add_op_code(VM::OP_PRINT);

    // Add a string with another type
    // SHould print this:
    // ABC100
    program->add_op_code(VM::OP_CONSTANT);
    program->add_constant_code(new VM::Value(new std::string("ABC")));
    program->add_op_code(VM::OP_CONSTANT);
    program->add_constant_code(new VM::Value(100));
    program->add_op_code(VM::OP_ADD);
    program->add_op_code(VM::OP_PRINT);

    // Very important to add the OP_EXIT if we want our VM to exit when done
    program->add_op_code(VM::OP_EXIT);

    // Se the program to the virtual machine
    virtual_machine->program = program;

    // You can also debug the program defined in the screen to know what is happening
    printf("\nProgram defined:\n\n");
    program->debug();

    // Now we can run the virtual machine :D
    printf("\nStart the virtual machine...\n\n");
    virtual_machine->run();

    return 0;
}
