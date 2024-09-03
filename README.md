# Instruction Set

## Display Operations
- **SET (x, y), (R, G, B)**: Set color values of the display for coordinates `(x, y)`.

## Data Transfer
- **MOV R1, R2**: Move the value from register `R1` to register `R2`.
- **LOAD R1, [R2]**: Load the value from memory at `MEM[R2]` into register `R1`.
- **STORE R1, [R2]**: Store the value in register `R1` into memory at `MEM[R2]`.

## Arithmetic Operations
- **ADD R1, R2, R3**: Add the value of register `R1` to the value of register `R2` and store the result in register `R3`.
- **ADD R1, #IMM, R3**: Add the value of register `R1` to the immediate value `#IMM` and store the result in register `R3`.
- **SUB R1, R2, R3**: Subtract the value of register `R2` from the value of register `R1` and store the result in register `R3`.
- **SUB R1, #IMM, R3**: Subtract the immediate value `#IMM` from the value of register `R1` and store the result in register `R3`.
- **MUL R1, R2, R3**: Multiply the value of register `R1` by the value of register `R2` and store the result in register `R3`.
- **MUL R1, #IMM, R3**: Multiply the value of register `R1` by the immediate value `#IMM` and store the result in register `R3`.
- **DIV R1, R2, R3**: Divide the value of register `R1` by the value of register `R2` and store the result in register `R3`.
- **DIV R1, #IMM, R3**: Divide the value of register `R1` by the immediate value `#IMM` and store the result in register `R3`.
- **INC R1**: Increment the value of register `R1` by 1.
- **DEC R1**: Decrement the value of register `R1` by 1.

## Shift Operations
- **SHL R1, R3**: Shift the value in register `R1` to the left by 1 bit and store the result in register `R2`.
- **SHL #IMM, R3**: Shift the value `IMM` to the left by 1 bit and store the result in register `R1`.
- **SHR R1, R3**: Shift the value in register `R1` to the right by 1 bit and store the result in register `R2`.
- **SHR #IMM, R3**: Shift the value `IMM` to the right by 1 bit and store the result in register `R1`.
- **SAR R1, R3**: Shift the value in register `R1` to the right arithmetically by 1 bit and store the result in register `R2`. (Sign bit is preserved for signed values.)
- **SAR #IMM, R3**: Shift the value `IMM` to the right arithmetically by 1 bit and store the result in register `R1`. (Sign bit is preserved for signed values.)


## Branching Operations
- **BEQ R1, R2, #IMM**: Increment the program counter (`pc`) by `#IMM` if the value of register `R1` is equal to the value of register `R2`.
- **BNE R1, R2, #IMM**: Increment the program counter (`pc`) by `#IMM` if the value of register `R1` is not equal to the value of register `R2`.
- **BGEZ R1, #IMM**: Increment the program counter (`pc`) by `#IMM` if the value of register `R1` is greater than or equal to zero.
- **BLTZ R1, #IMM**: Increment the program counter (`pc`) by `#IMM` if the value of register `R1` is less than zero.

## Bitwise Operations
- **AND R1, R2, R3**: Perform a bitwise AND operation between the values of registers `R1` and `R2` and store the result in register `R3`.
- **AND R1, #IMM, R3**: Perform a bitwise AND operation between the value of register `R1` and the immediate value `#IMM` and store the result in register `R3`.
- **XOR R1, R2, R3**: Perform a bitwise XOR operation between the values of registers `R1` and `R2` and store the result in register `R3`.
- **XOR R1, #IMM, R3**: Perform a bitwise XOR operation between the value of register `R1` and the immediate value `#IMM` and store the result in register `R3`.
- **NOT R1, R3**: Perform a bitwise NOT operation on the value of register `R1` and store the result in register `R3`.
- **NOT #IMM, R3**: Perform a bitwise NOT operation on the immediate value `#IMM` and store the result in register `R1`.


## Stack Operations
- **PUSH R1**: Push the value of register `R1` onto the stack.
- **POP R1**: Pop the top value from the stack into register `R1`.
