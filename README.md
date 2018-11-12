# Erik Virtual Machine
This is a stack based virtual machine under development. It is able
to perform diferent operation on diferent kind of operands.

- No dependencies required
- Quite fast
- Built as a library. (automatically builds itself as a static library)
- Easy API with examples on sample/main.cpp
- Youtube video stream of how I built it
- Pure C++

# How to build

## Using the Makefile

```
make library
```

This will compile the library, creating a `vm.a` at `build/`. You may then statically link it to your project as you wish.
For the example provided (windows. Remvoe the .exe to build on linux):

```
g++ -std=c++11 -O3 sample/main.cpp -o bin/sample.exe build/vm.a
```

You can also use the following command to build the library and the sample at the same time :)

```
make
```

This will compile the library, creating the .a at the same directory as mentioned above and will create the executable
file at `bin/` for the example provided.

## Using manual compilation

- To build the library

```
g++ -std=c++11 -O3 -c src/vm.cpp -o src/vm.o
g++ -std=c++11 -O3 -c src/program.cpp -o src/program.o
g++ -std=c++11 -O3 -c src/values.cpp -o src/values.o
ar rcs build/vm.a src/vm.o src/program.o src/values.o
rm src/vm.o src/program.o src/values.o
```

- To build the library + the sample

```
g++ -std=c++11 -O3 -c src/vm.cpp -o src/vm.o
g++ -std=c++11 -O3 -c src/program.cpp -o src/program.o
g++ -std=c++11 -O3 -c src/values.cpp -o src/values.o
ar rcs build/vm.a src/vm.o src/program.o src/values.o
rm src/vm.o src/program.o src/values.o
g++ -std=c++11 -O3 sample/main.cpp -o bin/sample.exe build/vm.a
```

# Valid values supported

- VALUE_INTEGER
- VALUE_FLOAT
- VALUE_BOOLEAN
- VALUE_STRING
- VALUE_LIST

# Valid operations:

- OP_CONSTANT
- OP_ADD
- OP_SUB
- OP_MUL
- OP_DIV
- OP_PRINT
- OP_EXIT
