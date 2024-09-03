#ifndef ASSEMBLE_H
#define ASSEMBLE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>
#include <optional>
#include <set>
#include <iomanip>
#include "symbols.h"

// Function to compute the negative of a bitset

enum class Instruction {
    SET, MOV, LOAD, STORE,
    ADD, SUB, MUL, DIV, INC, DEC,
    BEQ, BNE, BGEZ, BLTZ,
    AND, XOR, NOT, PUSH, POP, OR, SHL, SHR, SAR
};

// Struct to represent an assembly instruction
struct AsmInstruction {
    Instruction instr;
    std::bitset<3> reg1;  // 3-bit register value
    std::bitset<3> reg2;  // 3-bit register value
    std::bitset<3> reg3;  // 3-bit register value (for third register)
    std::bitset<6> imm;   // Immediate value
    bool imm_set = false;

    // Additional fields for SET instruction
    int x = 0;  // X-coordinate
    int y = 0;  // Y-coordinate
    int r = 0;  // Red color value
    int g = 0;  // Green color value
    int b = 0;  // Blue color value
};
// Machine code generator class
class MachineCodeGenerator {
public:
    std::string getMachineCode(const AsmInstruction& asmInst);
    std::string negative(const std::bitset<6>& bitset);

private:
    std::optional<std::bitset<3>> findMissingReg(
        const std::optional<std::bitset<3>>& reg1,
        const std::optional<std::bitset<3>>& reg2,
        const std::optional<std::bitset<3>>& reg3,
        const std::optional<std::bitset<3>>& reg4
    );

    std::string generateMov(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1, 
                            const std::optional<std::bitset<3>>& customReg2);

    std::string generateLoad(const AsmInstruction& asmInst, 
                             const std::optional<std::bitset<3>>& customReg1, 
                             const std::optional<std::bitset<3>>& customReg2);

    std::string generateStore(const AsmInstruction& asmInst, 
                              const std::optional<std::bitset<3>>& customReg1, 
                              const std::optional<std::bitset<3>>& customReg2);

    std::string generateAdd(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1, 
                            const std::optional<std::bitset<3>>& customReg2, 
                            const std::optional<std::bitset<3>>& customReg3, 
                            const std::optional<std::bitset<6>>& customImm);

    std::string generateSub(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1, 
                            const std::optional<std::bitset<3>>& customReg2, 
                            const std::optional<std::bitset<3>>& customReg3, 
                            const std::optional<std::bitset<6>>& customImm);

    std::string generateMul(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1, 
                        const std::optional<std::bitset<3>>& customReg2, 
                        const std::optional<std::bitset<3>>& customReg3, 
                        const std::optional<std::bitset<6>>& customImm);

    std::string generateDiv(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1, 
                        const std::optional<std::bitset<3>>& customReg2, 
                        const std::optional<std::bitset<3>>& customReg3, 
                        const std::optional<std::bitset<6>>& customImm);

    std::string generateInc(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1);

    std::string generateDec(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1);

    std::string generateBeq(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1,
                            const std::optional<std::bitset<3>>& customReg2,
                            const std::optional<std::bitset<6>>& customImm);

    std::string generateBne(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1,
                            const std::optional<std::bitset<3>>& customReg2,
                            const std::optional<std::bitset<6>>& customImm);

    std::string generateBgez(const AsmInstruction& asmInst, 
                             const std::optional<std::bitset<3>>& customReg1,
                             const std::optional<std::bitset<6>>& customImm);

    std::string generateBltz(const AsmInstruction& asmInst, 
                             const std::optional<std::bitset<3>>& customReg1,
                             const std::optional<std::bitset<6>>& customImm);

    std::string generateAnd(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1, 
                            const std::optional<std::bitset<3>>& customReg2, 
                            const std::optional<std::bitset<3>>& customReg3, 
                            const std::optional<std::bitset<6>>& customImm);

    std::string generateOr(const AsmInstruction& asmInst, 
                           const std::optional<std::bitset<3>>& customReg1, 
                           const std::optional<std::bitset<3>>& customReg2, 
                           const std::optional<std::bitset<3>>& customReg3, 
                           const std::optional<std::bitset<6>>& customImm);

    std::string generatePush(const AsmInstruction& asmInst, 
                             const std::optional<std::bitset<3>>& customReg1);

    std::string generatePop(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1);

    std::string generateNot(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1, 
                            const std::optional<std::bitset<3>>& customReg3, 
                            const std::optional<std::bitset<6>>& customImm);

    std::string generateShl(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1, 
                        const std::optional<std::bitset<3>>& customReg3, 
                        const std::optional<std::bitset<6>>& customImm);

    std::string generateShr(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1, 
                            const std::optional<std::bitset<3>>& customReg3, 
                            const std::optional<std::bitset<6>>& customImm);
    
    std::string generateSar(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1, 
                            const std::optional<std::bitset<3>>& customReg3, 
                            const std::optional<std::bitset<6>>& customImm);

    std::string generateXor(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1, 
                            const std::optional<std::bitset<3>>& customReg2, 
                            const std::optional<std::bitset<3>>& customReg3, 
                            const std::optional<std::bitset<6>>& customImm);
};

// Basic assembler class
class Assembler {
public:
    Assembler();
    void parse(const std::string& line);
    void readFile(const std::string& filename);
    std::vector<Word> assemble();
    std::vector<Word> convertMachineCodesToBinary(const std::vector<std::string>& machineCodes);
    std::bitset<3> parseRegister(const std::string& regStr);
private:
    std::vector<AsmInstruction> instructions;
    
    MachineCodeGenerator codeGen;
};

#endif // ASSEMBLE_H
