Here's a README for your project:

---

# Bytecode Virtual Machine (BVM)

A simple virtual machine (VM) that executes a custom bytecode instruction set. The BVM supports a variety of operations, including arithmetic, stack manipulation, and flow control.

## Features

- Stack-based architecture
- Supports integer, float, and pointer operations
- Basic arithmetic operations (ADD, MUL, DIV, DEC, INC)
- Stack operations (PUSH, POP, DUP, SWAP)
- Flow control operations (IF, JMP, JMPT, SETSP)
- Input/output operations (PRINT)
- Instruction set includes NOP and HALT
- Simple disassembler and program loader

## Getting Started

### Prerequisites

- A C compiler (GCC, Clang, etc.)

### Building the Project

1. Clone the repository:

   ```sh
   https://github.com/BlagojeBlagojevic/BVM.git
   cd bvm
   ```

2. Compile the project:

   ```sh
   gcc -o bvm main.c bvm.c
   ```

### Running the VM

To run the VM with a program:

```sh
./bvm program.txt
```

`program.txt` should contain the bytecode instructions.

## Bytecode Instruction Set

The VM supports the following instructions:

- `PUSH`: Push an integer onto the stack.
- `PUSHF`: Push a float onto the stack.
- `PUSHIP`: Push the instruction pointer onto the stack.
- `POP`: Pop the top value from the stack.
- `PRINT`: Print the top value on the stack.
- `ADD`: Add the top two values on the stack.
- `MUL`: Multiply the top two values on the stack.
- `DEC`: Decrement the top value on the stack.
- `DIV`: Divide the top two values on the stack.
- `DUP`: Duplicate the top value on the stack.
- `IF`: Perform a comparison and push the result.
- `JMP`: Jump to a specific instruction.
- `JMPT`: Jump to a specific instruction if the top value on the stack is true.
- `SETSP`: Set the stack pointer.
- `COPY`: Copy a value to a specific stack position.
- `SWAP`: Swap the top value with a specific stack position.
- `SWAPF`: Swap the top float value with a specific stack position.
- `NOP`: No operation.
- `HALT`: Halt the VM.
- `INC`: Increment the top value on the stack.
- `NEWLINE`: No operation (for readability).
- `END`: End the program.

## Functions

- `initBVM()`: Initialize the BVM.
- `executeInstruction(Bvm *bvm)`: Execute a single instruction.
- `loop(Bvm *bvm)`: Run the instruction execution loop.
- `textToProgram(const char* name, Instruction *instruction)`: Load a program from a text file.
- `dissasembler(Bvm *bvm)`: Disassemble the loaded program (not implemented).
- `programToBin(const char* name, Instruction *instruction, u64 numOfInstruction)`: Save a program to a binary file.
- `binToProgram(const char* name, Instruction *instruction)`: Load a program from a binary file.

## Example Program

Example of a simple program in `program.txt`:

```
PUSH 10
PUSH 20
ADD i
PRINT i
END
```

This program pushes two integers onto the stack, adds them, prints the result, and ends the execution.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing

Feel free to submit issues, fork the repository and send pull requests!

---
