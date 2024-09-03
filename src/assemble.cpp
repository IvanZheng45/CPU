#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>
#include <optional>
#include <set>
#include <iomanip>
#include "assemble.h"
#include "symbols.h"

Assembler::Assembler() : codeGen() {}


// Function to compute the negative of a bitset
std::string MachineCodeGenerator::negative(const std::bitset<6>& bitset) {
    std::bitset<6> inverted = ~bitset; // Invert all bits
    std::bitset<6> result = inverted.to_ulong() + 1; // Add 1 to the inverted bits
    
    return result.to_string(); // Convert back to a 6-bit binary string
}

// Machine code generator class
std::string MachineCodeGenerator::getMachineCode(const AsmInstruction& asmInst) {
    switch (asmInst.instr) {
        case Instruction::MOV:
            return generateMov(asmInst, std::nullopt, std::nullopt);
        case Instruction::LOAD:
            return generateLoad(asmInst, std::nullopt, std::nullopt);
        case Instruction::STORE:
            return generateStore(asmInst, std::nullopt, std::nullopt);
        case Instruction::ADD:
            return generateAdd(asmInst, std::nullopt, std::nullopt, std::nullopt, std::nullopt);
        case Instruction::SUB:
            return generateSub(asmInst, std::nullopt, std::nullopt, std::nullopt, std::nullopt);
        case Instruction::MUL:
            // return generateMul(asmInst, std::nullopt, std::nullopt);
        case Instruction::DIV:
            // return generateDiv(asmInst, std::nullopt);
        case Instruction::INC:
            return generateInc(asmInst, std::nullopt); 
        case Instruction::DEC:
            return generateDec(asmInst, std::nullopt); 
        case Instruction::BEQ:
            return generateBeq(asmInst, std::nullopt, std::nullopt, std::nullopt); 
        case Instruction::BNE:
            return generateBne(asmInst, std::nullopt, std::nullopt, std::nullopt); 
        case Instruction::BGEZ:
            return generateBgez(asmInst, std::nullopt, std::nullopt); 
        case Instruction::BLTZ:
            return generateBltz(asmInst, std::nullopt, std::nullopt);
        case Instruction::AND:
            return generateAnd(asmInst, std::nullopt, std::nullopt, std::nullopt, std::nullopt);
        case Instruction::XOR:
            return generateXor(asmInst, std::nullopt, std::nullopt, std::nullopt, std::nullopt);
        case Instruction::OR:
            return generateOr(asmInst, std::nullopt, std::nullopt, std::nullopt, std::nullopt);
        case Instruction::NOT:
            return generateNot(asmInst, std::nullopt, std::nullopt, std::nullopt);
        case Instruction::PUSH:
            return generatePush(asmInst, std::nullopt);
        case Instruction::POP:
            return generatePop(asmInst, std::nullopt);
        case Instruction::SHL:
            return generateShl(asmInst, std::nullopt, std::nullopt, std::nullopt);
        case Instruction::SHR:
            return generateShr(asmInst, std::nullopt, std::nullopt, std::nullopt);
        case Instruction::SAR:
            return generateSar(asmInst, std::nullopt, std::nullopt, std::nullopt);
        case Instruction::SET:
            // return generateSet(asmInst, std::nullopt, std::nullopt, std::nullopt, std::nullopt);
        default:
            return "UNKNOWN_INSTRUCTION";
    }
}


std::optional<std::bitset<3>> MachineCodeGenerator::findMissingReg(
const std::optional<std::bitset<3>>& reg1 = std::nullopt, 
const std::optional<std::bitset<3>>& reg2 = std::nullopt,
const std::optional<std::bitset<3>>& reg3 = std::nullopt,
const std::optional<std::bitset<3>>& reg4 = std::nullopt
)
{
    // Create a set of provided registers
    std::set<int> providedRegs;
    if (reg1) providedRegs.insert(reg1->to_ulong());
    if (reg2) providedRegs.insert(reg2->to_ulong());
    if (reg3) providedRegs.insert(reg3->to_ulong());
    if (reg4) providedRegs.insert(reg4->to_ulong());

    // Iterate through all possible registers (0-6) to find the missing one
    for (int reg = 0; reg <= 6; ++reg) {
        if (providedRegs.find(reg) == providedRegs.end()) {
            return std::bitset<3>(reg);
        }
    }

    // If no missing register is found
    return std::nullopt;
}

std::string MachineCodeGenerator::generateMov(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                        const std::optional<std::bitset<3>>& customReg2 = std::nullopt) {
    std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
    std::string reg2 = customReg2.value_or(asmInst.reg2).to_string();
    return "0101" + reg1 + reg2 + "000000";
}

std::string MachineCodeGenerator::generateLoad(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg2 = std::nullopt) {
    std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
    std::string reg2 = customReg2.value_or(asmInst.reg2).to_string();
    return "0010" + reg2 + reg1 + "000000";
}

std::string MachineCodeGenerator::generateStore(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg2 = std::nullopt) {
    std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
    std::string reg2 = customReg2.value_or(asmInst.reg2).to_string();
    return "0100" + reg2 + reg1 + "000000";
}

std::string MachineCodeGenerator::generateAdd(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                        const std::optional<std::bitset<3>>& customReg2 = std::nullopt, 
                        const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                        const std::optional<std::bitset<6>>& customImm = std::nullopt) {
    std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
    std::string reg2 = customReg2.value_or(asmInst.reg2).to_string();
    std::string reg3 = customReg3.value_or(asmInst.reg3).to_string();
    std::string imm = customImm.has_value() ? customImm->to_string() : asmInst.imm.to_string();
    if  (customReg2 == std::nullopt && (customImm != std::nullopt || asmInst.imm_set))  { // Check for non-zero immediate value
        return "0101" + reg1 + reg3 + imm;
    } else {
        return "1111" + reg1 + reg2 + reg3 + "000";
    }
}

std::string MachineCodeGenerator::generateSub(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                        const std::optional<std::bitset<3>>& customReg2 = std::nullopt, 
                        const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                        const std::optional<std::bitset<6>>& customImm = std::nullopt) {
    std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
    std::string reg2 = customReg2.value_or(asmInst.reg2).to_string();
    std::string reg3 = customReg3.value_or(asmInst.reg3).to_string();
    std::string imm = customImm.has_value() ? negative(*customImm) : negative(asmInst.imm);

    if  (customReg2 == std::nullopt && (customImm != std::nullopt || asmInst.imm_set))  { // Check for non-zero immediate value
        return "0101" + reg1 + reg3 + imm;
    } else {
        return "1111" + reg1 + reg2 + reg3 + "001";
    }
}

std::string MachineCodeGenerator::generateMul(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                        const std::optional<std::bitset<3>>& customReg2 = std::nullopt, 
                        const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                        const std::optional<std::bitset<6>>& customImm = std::nullopt) {
    std::bitset<3> reg1 = customReg1.value_or(asmInst.reg1);
    std::bitset<3> reg2 = customReg2.value_or(asmInst.reg2);
    std::bitset<3> reg3 = customReg3.value_or(asmInst.reg3);

    std::bitset<6> imm = customImm.value_or(asmInst.imm);
    
    if  (customReg2 == std::nullopt && (customImm != std::nullopt || asmInst.imm_set))  { // Check for non-zero immediate value
        std::bitset<3> emptyReg = findMissingReg(reg1, reg3).value();
        std::bitset<3> emptyReg2 = findMissingReg(reg1, reg3, emptyReg).value();

        return generatePush(asmInst, emptyReg) + "\n"
        + generatePush(asmInst, emptyReg2) + "\n"
        + generateSub(asmInst, emptyReg, emptyReg, emptyReg) + "\n"
        + generateSub(asmInst, emptyReg2, emptyReg2, emptyReg2) + "\n"
        + generateAdd(asmInst, emptyReg, std::nullopt, emptyReg, 16);

    } else {
        std::bitset<3> emptyReg = findMissingReg(reg1, reg2, reg3).value();
        std::bitset<3> emptyReg2 = findMissingReg(reg1, reg2, reg3, emptyReg).value();
    
        return generatePush(asmInst, emptyReg) + "\n";
    }
}
                        

std::string MachineCodeGenerator::generateDiv(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                        const std::optional<std::bitset<3>>& customReg2 = std::nullopt, 
                        const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                        const std::optional<std::bitset<6>>& customImm = std::nullopt) {
    std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
    return "DIV_MACHINE_CODE";
}
std::string MachineCodeGenerator::generateInc(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt) {
    std::bitset<3> reg1 = customReg1.value_or(asmInst.reg1);
    return generateAdd(asmInst, reg1, std::nullopt, reg1, 1);
}
std::string MachineCodeGenerator::generateDec(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt) {
    std::bitset<3> reg1 = customReg1.value_or(asmInst.reg1);
    return generateAdd(asmInst, reg1, std::nullopt, reg1, -1); // Placeholder
}
std::string MachineCodeGenerator::generateBeq(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt,
                        const std::optional<std::bitset<3>>& customReg2 = std::nullopt,
                        const std::optional<std::bitset<6>>& customImm = std::nullopt) {
    std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
    std::string reg2 = customReg2.value_or(asmInst.reg1).to_string();
    std::string imm = customImm.value_or(asmInst.imm).to_string();
    return "1000" + reg1 + reg2+ imm; 
}
std::string MachineCodeGenerator::generateBne(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt,
                        const std::optional<std::bitset<3>>& customReg2 = std::nullopt,
                        const std::optional<std::bitset<6>>& customImm = std::nullopt) {
    std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
    std::string reg2 = customReg2.value_or(asmInst.reg1).to_string();
    std::string imm = customImm.value_or(asmInst.imm).to_string();
    return "1001" + reg1 + reg2+ imm; 
}
std::string MachineCodeGenerator::generateBgez(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt,
                        const std::optional<std::bitset<6>>& customImm = std::nullopt) {
    std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
    std::string imm = customImm.value_or(asmInst.imm).to_string();
    return "1010" + reg1 + reg1+ imm; 
}
std::string MachineCodeGenerator::generateBltz(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt,
                        const std::optional<std::bitset<6>>& customImm = std::nullopt) {
    std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
    std::string imm = customImm.value_or(asmInst.imm).to_string();
    return "1011" + reg1 + reg1 + imm;
}

std::string MachineCodeGenerator::generateAnd(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                        const std::optional<std::bitset<3>>& customReg2 = std::nullopt, 
                        const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                        const std::optional<std::bitset<6>>& customImm = std::nullopt) {
    std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
    std::string reg2 = customReg2.value_or(asmInst.reg2).to_string();
    std::string reg3 = customReg3.value_or(asmInst.reg3).to_string();
    std::string imm = customImm.has_value() ? customImm->to_string() : asmInst.imm.to_string();
    if  (customReg2 == std::nullopt && (customImm != std::nullopt || asmInst.imm_set))  { // Check for non-zero immediate value
        return "0110" + reg1 + reg3 + imm;
    } else {
        return "1111" + reg1 + reg2 + reg3 + "101";
    }
}
std::string MachineCodeGenerator::generateOr(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                        const std::optional<std::bitset<3>>& customReg2 = std::nullopt, 
                        const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                        const std::optional<std::bitset<6>>& customImm = std::nullopt) {
    std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
    std::string reg2 = customReg2.value_or(asmInst.reg2).to_string();
    std::string reg3 = customReg3.value_or(asmInst.reg3).to_string();
    std::string imm = customImm.has_value() ? customImm->to_string() : asmInst.imm.to_string();
    if  (customReg2 == std::nullopt && (customImm != std::nullopt || asmInst.imm_set))  { // Check for non-zero immediate value
        return "0111" + reg1 + reg3 + imm;
    } else {
        return "1111" + reg1 + reg2 + reg3 + "110";
    }
}

std::string MachineCodeGenerator::generatePush(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt) {
    std::bitset<3> reg1 = customReg1.value_or(asmInst.reg1);
    
    
    return generateStore(asmInst, reg1, 7) + "\n" 
    + generateSub(asmInst, 7, std::nullopt, 7, 1);
}

    std::string MachineCodeGenerator::generatePop(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt) {
    std::bitset<3> reg1 = customReg1.value_or(asmInst.reg1);
    
        
    return generateAdd(asmInst, 7, std::nullopt, 7, 1)  +  "\n"
    + generateLoad(asmInst, reg1, 7);
}

std::string MachineCodeGenerator::generateNot(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                        const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                        const std::optional<std::bitset<6>>& customImm = std::nullopt) {
    std::bitset<3> reg1 = customReg1.value_or(asmInst.reg1);
    std::bitset<3> reg3 = customReg3.value_or(asmInst.reg3);
    std::bitset<6> imm = customImm.value_or(asmInst.imm);
    

    if  (customReg1 == std::nullopt && (customImm != std::nullopt || asmInst.imm_set))  { // Check for non-zero immediate value
        std::bitset<3> emptyReg = findMissingReg(reg3).value();
        
        return generatePush(asmInst, emptyReg) + "\n"
        + generateSub(asmInst, emptyReg, emptyReg, emptyReg) + "\n"
        + generateSub(asmInst, emptyReg, std::nullopt, reg3, imm) + "\n"
        + generateSub(asmInst, reg3, std::nullopt, reg3, 1) + "\n"
        + generatePop(asmInst, emptyReg);
    } else {
        std::bitset<3> emptyReg = findMissingReg(reg1, reg3).value();
        return generatePush(asmInst, emptyReg) + "\n"
        + generateSub(asmInst, emptyReg, emptyReg, emptyReg) + "\n"
        + generateSub(asmInst, emptyReg, reg1, reg3) + "\n"
        + generateSub(asmInst, reg3, std::nullopt, reg3, 1) + "\n"
        + generatePop(asmInst, emptyReg);
    }
}

std::string MachineCodeGenerator::generateXor(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                        const std::optional<std::bitset<3>>& customReg2 = std::nullopt, 
                        const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                        const std::optional<std::bitset<6>>& customImm = std::nullopt) {
    std::bitset<3> reg1 = customReg1.value_or(asmInst.reg1);
    std::bitset<3> reg2 = customReg2.value_or(asmInst.reg2);
    std::bitset<3> reg3 = customReg3.value_or(asmInst.reg3);

    std::bitset<6> imm = customImm.value_or(asmInst.imm);
    
    if  (customReg2 == std::nullopt && (customImm != std::nullopt || asmInst.imm_set))  { // Check for non-zero immediate value
        std::bitset<3> emptyReg = findMissingReg(reg1, reg3).value();
        std::bitset<3> emptyReg2 = findMissingReg(reg1, reg3, emptyReg).value();

        return generatePush(asmInst, emptyReg) + "\n"
        + generatePush(asmInst, emptyReg2) + "\n"
        + generateNot(asmInst, std::nullopt, emptyReg2, imm) + "\n"
        + generateAnd(asmInst, emptyReg2, reg1, emptyReg2) + "\n"
        + generateNot(asmInst, reg1, emptyReg) + "\n" 
        + generateAnd(asmInst, emptyReg, std::nullopt, emptyReg, imm) + "\n"
        + generateOr(asmInst, emptyReg2, emptyReg, reg3) + "\n"
        + generatePop(asmInst, emptyReg2) + "\n"
        + generatePop(asmInst, emptyReg);

    } else {
        std::bitset<3> emptyReg = findMissingReg(reg1, reg2, reg3).value();
        std::bitset<3> emptyReg2 = findMissingReg(reg1, reg2, reg3, emptyReg).value();
    
        return generatePush(asmInst, emptyReg) + "\n"
        + generatePush(asmInst, emptyReg2) + "\n"
        + generateNot(asmInst, reg1, emptyReg2) + "\n"
        + generateAnd(asmInst, emptyReg2, reg2, emptyReg2) + "\n"
        + generateNot(asmInst, reg2, emptyReg) + "\n"
        + generateAnd(asmInst, emptyReg, reg1, emptyReg) + "\n"
        + generateOr(asmInst, emptyReg2, emptyReg, reg3) + "\n"
        + generatePop(asmInst, emptyReg2) + "\n"
        + generatePop(asmInst, emptyReg);
    }
}
    std::string MachineCodeGenerator::generateShl(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                        const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                        const std::optional<std::bitset<6>>& customImm = std::nullopt) {
    std::bitset<3> reg1 = customReg1.value_or(asmInst.reg1);
    std::bitset<3> reg3 = customReg3.value_or(asmInst.reg3);
    std::bitset<6> imm = customImm.value_or(asmInst.imm);
    

    if  (customReg1 == std::nullopt && (customImm != std::nullopt || asmInst.imm_set))  { // Check for non-zero immediate value
        std::bitset<3> emptyReg = findMissingReg(reg3).value();
        
        return generatePush(asmInst, emptyReg) + "\n"
        + generateSub(asmInst, emptyReg, emptyReg, emptyReg) + "\n"
        + generateAdd(asmInst, emptyReg, std::nullopt, emptyReg, customImm) + "\n"
        + generateShl(asmInst, emptyReg, reg3) + "\n"
        + generatePop(asmInst, emptyReg);
    } else {
        return "1111" + reg1.to_string() + reg3.to_string() + reg3.to_string() + "100";
        }
    }

    std::string MachineCodeGenerator::generateShr(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                        const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                        const std::optional<std::bitset<6>>& customImm = std::nullopt) {
    std::bitset<3> reg1 = customReg1.value_or(asmInst.reg1);
    std::bitset<3> reg3 = customReg3.value_or(asmInst.reg3);
    std::bitset<6> imm = customImm.value_or(asmInst.imm);
    

    if  (customReg1 == std::nullopt && (customImm != std::nullopt || asmInst.imm_set))  { // Check for non-zero immediate value
        std::bitset<3> emptyReg = findMissingReg(reg3).value();
        
        return generatePush(asmInst, emptyReg) + "\n"
        + generateSub(asmInst, emptyReg, emptyReg, emptyReg) + "\n"
        + generateAdd(asmInst, emptyReg, std::nullopt, emptyReg, customImm) + "\n"
        + generateShl(asmInst, emptyReg, reg3) + "\n"
        + generatePop(asmInst, emptyReg);
    } else {
        return "1111" + reg1.to_string() + reg3.to_string() + reg3.to_string() + "011";
        }
    }

    std::string MachineCodeGenerator::generateSar(const AsmInstruction& asmInst, 
                        const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                        const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                        const std::optional<std::bitset<6>>& customImm = std::nullopt) {
    std::bitset<3> reg1 = customReg1.value_or(asmInst.reg1);
    std::bitset<3> reg3 = customReg3.value_or(asmInst.reg3);
    std::bitset<6> imm = customImm.value_or(asmInst.imm);
    

    if  (customReg1 == std::nullopt && (customImm != std::nullopt || asmInst.imm_set))  { // Check for non-zero immediate value
        std::bitset<3> emptyReg = findMissingReg(reg3).value();
        
        return generatePush(asmInst, emptyReg) + "\n"
        + generateSub(asmInst, emptyReg, emptyReg, emptyReg) + "\n"
        + generateAdd(asmInst, emptyReg, std::nullopt, emptyReg, customImm) + "\n"
        + generateShl(asmInst, emptyReg, reg3) + "\n"
        + generatePop(asmInst, emptyReg);
    } else {
        return "1111" + reg1.to_string() + reg3.to_string() + reg3.to_string() + "010";
        }
    }


void Assembler::parse(const std::string& line) {
    std::istringstream iss(line);
    std::string opcode;
    int reg1Num, reg2Num, reg3Num, x, y, r, g, b;
    std::string immStr;
    AsmInstruction asmInst;
    char comma, hash, bracket;

    iss >> opcode;
    


    if (opcode == "MOV") {
        asmInst.instr = Instruction::MOV;
        iss >> reg1Num >> comma >> reg2Num;
        asmInst.reg1 = std::bitset<3>(reg1Num);
        asmInst.reg2 = std::bitset<3>(reg2Num);

    } else if (opcode == "LOAD") {
        asmInst.instr = Instruction::LOAD;
        iss >> reg1Num >> comma >> bracket >> reg2Num >> bracket;
        asmInst.reg1 = std::bitset<3>(reg1Num);
        asmInst.reg2 = std::bitset<3>(reg2Num);

    } else if (opcode == "STORE") {
        asmInst.instr = Instruction::STORE;
        iss >> reg1Num >> comma >> bracket >> reg2Num >> bracket;
        asmInst.reg1 = std::bitset<3>(reg1Num);
        asmInst.reg2 = std::bitset<3>(reg2Num);

    } else if (opcode == "ADD" || opcode == "SUB" || opcode == "MUL" || opcode == "DIV" ||
            opcode == "AND" || opcode == "XOR" || opcode == "OR") {
        std::string reg1, reg2, reg3;
        iss >> reg1 >> reg2 >> reg3;

        if (opcode == "ADD")
            asmInst.instr = Instruction::ADD;
        else if (opcode == "SUB")
            asmInst.instr = Instruction::SUB;
        else if (opcode == "MUL")
            asmInst.instr = Instruction::MUL;
        else if (opcode == "DIV")
            asmInst.instr = Instruction::DIV;
        else if (opcode == "XOR")
            asmInst.instr = Instruction::XOR;
        else if (opcode == "OR")
            asmInst.instr = Instruction::OR;
        else if (opcode == "AND")
            asmInst.instr = Instruction::AND;

        if (reg2[0] == '#') {  // Immediate value detected
            int immValue = std::stoi(reg2.substr(1));  // Skip the '#' and convert to int
            asmInst.reg1 = std::bitset<3>(std::stoi(reg1));
            asmInst.imm = std::bitset<6>(immValue);
            asmInst.reg3 = std::bitset<3>(std::stoi(reg3));
            asmInst.imm_set = true;
        } else {  // Register to register operation
            asmInst.reg1 = std::bitset<3>(std::stoi(reg1));
            asmInst.reg2 = std::bitset<3>(std::stoi(reg2));
            asmInst.reg3 = std::bitset<3>(std::stoi(reg3));
        }
    } else if (opcode == "BEQ" || opcode == "BNE") {
        asmInst.instr = (opcode == "BEQ") ? Instruction::BEQ : Instruction::BNE;
        iss >> reg1Num >> comma >> reg2Num >> comma >> hash >> immStr;
        asmInst.reg1 = std::bitset<3>(reg1Num);
        asmInst.reg2 = std::bitset<3>(reg2Num);
        asmInst.imm = std::bitset<6>(std::stoi(immStr));
        asmInst.imm_set = true;


    } else if (opcode == "NOT" || opcode == "SHL" || opcode == "SHR" || opcode == "SAR") {
        if (opcode == "NOT")
            asmInst.instr = Instruction::NOT;
        else if (opcode == "SHL")
            asmInst.instr = Instruction::SHL;
        else if (opcode == "SHR")
            asmInst.instr = Instruction::SHR;
        else if (opcode == "SAR")
            asmInst.instr = Instruction::SAR;
        std::string reg1, reg3;
        iss >> reg1 >> reg3;

        if (reg1[0] == '#') {
            int immValue = std::stoi(reg1.substr(1));
            asmInst.reg3 = std::bitset<3>(std::stoi(reg3));
            asmInst.imm = std::bitset<6>(immValue);
            asmInst.imm_set = true;
        }
        else{
            asmInst.reg3 = std::bitset<3>(std::stoi(reg3));
            asmInst.reg1 = std::bitset<3>(std::stoi(reg1));
        }

    } else if (opcode == "BGEZ" || opcode == "BLTZ") {
        asmInst.instr = (opcode == "BGEZ") ? Instruction::BGEZ : Instruction::BLTZ;
        iss >> reg1Num >> comma >> hash >> immStr;
        asmInst.reg1 = std::bitset<3>(reg1Num);
        asmInst.imm = std::bitset<6>(std::stoi(immStr));
        asmInst.imm_set = true;

    } else if (opcode == "INC" || opcode == "DEC") {
        asmInst.instr = (opcode == "INC") ? Instruction::INC : Instruction::DEC;
        iss >> reg1Num;
        asmInst.reg1 = std::bitset<3>(reg1Num);

    } else if (opcode == "PUSH" || opcode == "POP") {
        asmInst.instr = (opcode == "PUSH") ? Instruction::PUSH : Instruction::POP;
        iss >> reg1Num;
        asmInst.reg1 = std::bitset<3>(reg1Num);

    } else if (opcode == "SET") {
        asmInst.instr = Instruction::SET;
        iss >> bracket >> x >> comma >> y >> bracket >> comma >> bracket >> r >> comma >> g >> comma >> b >> bracket;
        asmInst.x = x;
        asmInst.y = y;
        asmInst.r = r;
        asmInst.g = g;
        asmInst.b = b;

    } else {
        std::cerr << "Unknown opcode: " << opcode << std::endl;
        return;
    }

    instructions.push_back(asmInst);
    // std::cout << opcode << std::endl;


}

std::vector<Word> Assembler::assemble() {
    std::vector<std::string> machineCodes;
    for (const auto& inst : instructions) {
        std::string machineCode = codeGen.getMachineCode(inst);
        std::istringstream stream(machineCode);
        std::string line;
        
        while (std::getline(stream, line)) {
            if (!line.empty()) {
                machineCodes.push_back(line);
            }
            
        }
    }
    return convertMachineCodesToBinary(machineCodes);
}

void Assembler::readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        parse(line);
        
    }
    file.close();
}

std::vector<Word> Assembler::convertMachineCodesToBinary(const std::vector<std::string>& binaryStrings) {
    std::vector<Word> binaryValues;
    
    // Iterate over each binary string
    for (const auto& binaryStr : binaryStrings) {
        std::bitset<16> bits(binaryStr); // Assumes binary strings are 32 bits long
        Word binaryValue = bits.to_ulong(); // Convert bitset to unsigned long
        binaryValues.push_back(binaryValue);
    }
    
    return binaryValues;
}


std::bitset<3> Assembler::parseRegister(const std::string& regStr) {
    if (regStr.size() == 3 && regStr.find_first_not_of("01") == std::string::npos) {
        return std::bitset<3>(regStr);
    } else {
        return std::bitset<3>(std::stoi(regStr));
    }
}

