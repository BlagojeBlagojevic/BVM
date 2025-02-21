
---
# Bytecode Virtual Machine (BVM)

A simple virtual machine (VM) that executes a custom bytecode instruction set. The BVM supports a variety of operations, including arithmetic, stack manipulation, flow control, and system calls. To program this vm see https://github.com/BlagojeBlagojevic/blang.

## Features

- Stack-based architecture
- Supports integer, float, and character operations
- Arithmetic operations (ADD, MUL, DIV, MOD, DEC, INC)
- Bitwise operations (SHR, SHL, OR, AND, BNOT)
- Stack manipulation (PUSH, POP, DUP, OVER, ROT, SWAP)
- Flow control (IF, JMP, JMPT, JMPF,)
- Memory operations (MEM, COPY, COPYSTACK, MEMSTACK)
- System calls (WRITE, READ, EXIT, SYSTEM, etc.) via `SYSCALLS` define
- FFI(DRIVER)
- Input/output operations (PRINT, PRINTSTRING, PRINTSTACK)

## Getting Started

### Prerequisites

- A C compiler (GCC, Clang, etc.)

### Building the Project

1. Clone the repository:

   ```sh
   git clone https://github.com/BlagojeBlagojevic/BVM.git
   cd BVM
   ```

2. Compile the project (enable syscalls with `-DSYSCALLS -DSYSTEM` if needed):

   ```sh
   gcc -o bvm main.c -DSYSCALLS -DSYSTEM
   ```

### Running the VM

Execute a program from a text file:

```sh
./bvm program.txt
```

## Bytecode Instruction Set

### Stack Operations
- **`PUSH <value>`**: Push an integer onto the stack.
- **`PUSHF <value>`**: Push a float onto the stack.
- **`PUSHIP`**: Push the current instruction pointer (IP) onto the stack.
- **`PUSHSP`**: Push the stack pointer (SP) onto the stack.
- **`POP`**: Remove the top value from the stack.
- **`DUP`**: Duplicate the top stack value.
- **`OVER`**: Copy the second stack item to the top.
- **`ROT`**: Rotate the top three stack items.
- **`SWAP_NO`**: Swap the top two stack values.
- **`SWAP <index>`**: Swap the top value with the value at `index`.

### Arithmetic Operations
- **`ADD <type>`**: Add top two values. `type`: 0 (int), 1 (float), 2 (uint).
- **`MUL <type>`**, **`DIV <type>`**, **`DEC <type>`**, **`MOD`**: Multiply, divide, decrement, modulo.
- **`INC <value>`**: Increment the top value by `value`.

### Bitwise Operations
- **`SHR`**, **`SHL`**: Shift right/left.
- **`OR`**, **`AND`**, **`BNOT`**: Bitwise OR, AND, NOT.

### Control Flow
- **`IF <cond>`**: Compare top two values. `cond`: '>' (0), '<' (1), '==' (2). Push 1/0.
- **`JMP <address>`**: Jump to `address`.
- **`JMPT <address>`**: Jump if top value is non-zero.
- **`JMPF <address>`**: Jump if top value is zero.
- **`SETSP <index>`**: Set stack pointer to `index`.
- **`RESTORE <new_sp>`**:  Restore SP to <new_sp> and IP from the stack..

### Memory Operations
- **`COPY <index>`**: Copy value at `index` to the top.
- **`MEM <index>`**: Store top value at `index`.
- **`COPYSTACK <memaddres>`**: Copy value from memaddres to a SP-1
- **`MEMSTACK <memaddres, value>`**: Copy value to a mem addres 

### I/O Operations
- **`PRINT <type>`**: Print top value. `type`: 0 (int), 1 (float), 2 (char).
- **`PRINTSTRING`**: Print null-terminated string from the stack.
- **`PRINTSTACK`**: Dump the entire stack.

### System Calls (Require `SYSCALLS` define)
- **`WRITE`**: Write to a file descriptor (args: fd, data, size).
- **`READ`**: Read from a file descriptor.
- **`EXIT`**: Terminate the VM with a status code.
- **`SYSTEM`**: Execute a shell command (requires `SYSTEM` define).

### FFI
- **`DRIVER`**: Calls a device driver function specified by the driver number.


### Miscellaneous
- **`NOP`**: No operation.
- **`HALT`**: Pause execution (debugging).
- **`END`**: Terminate the VM gracefully.

## Example Program

```plaintext
PUSH 10
PUSH 20
ADD 0
PRINT 0
PUSH 65
PRINT 2    # Prints 'A'
PUSH 0
PUSH 1
IF >
JMPT 7     # Jump to HALT if 1 > 0
PRINT 0
HALT
END
```

## License

MIT License. See [LICENSE](LICENSE) for details.



