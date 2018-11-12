CC = g++
C_FLAGS = -std=c++11 -O3

ifeq ($(OS),Windows_NT)
EXE = sample.exe
else
EXE = sample
endif

all: build/vm.a
	$(CC) $(C_FLAGS) sample/main.cpp -o bin/$(EXE) $^

library: build/vm.a

src/vm.o:
	$(CC) $(C_FLAGS) -c src/vm.cpp -o src/vm.o

src/program.o:
	$(CC) $(C_FLAGS) -c src/program.cpp -o src/program.o

src/values.o:
	$(CC) $(C_FLAGS) -c src/values.cpp -o src/values.o

build/vm.a: src/vm.o src/program.o src/values.o
	ar rcs build/vm.a $^
	rm $^
