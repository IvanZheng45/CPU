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

// Enum class for different instructions
enum class Instruction {
    SET, MOV, LOAD, STORE,
    ADD, SUB, MUL, DIV, INC, DEC,
    BEQ, BNE, BGEZ, BLTZ,
    AND, XOR, NOT, PUSH, POP
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

// Function to compute the negative of a bitset
std::string negative(const std::bitset<6>& bitset);

// Machine code generator class
class MachineCodeGenerator {
public:
    std::string getMachineCode(const AsmInstruction& asmInst);

private:
    std::optional<std::bitset<3>> findMissingReg(
        const std::optional<std::bitset<3>>& reg1 = std::nullopt,
        const std::optional<std::bitset<3>>& reg2 = std::nullopt,
        const std::optional<std::bitset<3>>& reg3 = std::nullopt
    );

    std::string generateMov(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg2 = std::nullopt);
    
    std::string generateLoad(const AsmInstruction& asmInst, 
                             const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                             const std::optional<std::bitset<3>>& customReg2 = std::nullopt);
    
    std::string generateStore(const AsmInstruction& asmInst, 
                              const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                              const std::optional<std::bitset<3>>& customReg2 = std::nullopt);
    
    std::string generateAdd(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg2 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                            const std::optional<std::bitset<6>>& customImm = std::nullopt);
    
    std::string generateSub(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg2 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                            const std::optional<std::bitset<6>>& customImm = std::nullopt);
    
    std::string generateMul(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg2 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg3 = std::nullopt);
    
    std::string generateDiv(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt);
    
    std::string generateInc(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt);
    
    std::string generateDec(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt);
    
    std::string generateBeq(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt,
                            const std::optional<std::bitset<3>>& customReg2 = std::nullopt,
                            const std::optional<std::bitset<6>>& customImm = std::nullopt);
    
    std::string generateBne(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt,
                            const std::optional<std::bitset<3>>& customReg2 = std::nullopt,
                            const std::optional<std::bitset<6>>& customImm = std::nullopt);
    
    std::string generateBgez(const AsmInstruction& asmInst, 
                             const std::optional<std::bitset<3>>& customReg1 = std::nullopt,
                             const std::optional<std::bitset<6>>& customImm = std::nullopt);
    
    std::string generateBltz(const AsmInstruction& asmInst, 
                             const std::optional<std::bitset<3>>& customReg1 = std::nullopt,
                             const std::optional<std::bitset<6>>& customImm = std::nullopt);

    std::string generateAnd(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg2 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                            const std::optional<std::bitset<6>>& customImm = std::nullopt);
    
    std::string generateOr(const AsmInstruction& asmInst, 
                           const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                           const std::optional<std::bitset<3>>& customReg2 = std::nullopt, 
                           const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                           const std::optional<std::bitset<6>>& customImm = std::nullopt);

    std::string generatePush(const AsmInstruction& asmInst, 
                             const std::optional<std::bitset<3>>& customReg1 = std::nullopt);
    
    std::string generatePop(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt);

    std::string generateNot(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                            const std::optional<std::bitset<6>>& customImm = std::nullopt);

    std::string generateXor(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg2 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                            const std::optional<std::bitset<6>>& customImm = std::nullopt);
};

// Basic assembler class
class Assembler {
public:
    Assembler();
    void parse(const std::string& line);
    std::vector<Word> assemble();
    void readFile(const std::string& filename);
    std::vector<Word> convertMachineCodesToBinary(const std::vector<std::string>& machineCodes);

private:
    MachineCodeGenerator codeGen;
    std::vector<AsmInstruction> instructions;
    std::bitset<3> parseRegister(const std::string& reg);
};

#endif // ASSEMBLE_H
