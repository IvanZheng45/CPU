#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>
#include <optional>

enum class Instruction {
    SET, MOV, LOAD, STORE,
    ADD, SUB, MUL, DIV, INC, DEC,
    BEQ, BNE, BGEZ, BLTZ,
    AND, XOR, NOT, PUSH, POP
};

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
std::string negative(const std::bitset<6>& bitset) {
    std::bitset<6> inverted = ~bitset; // Invert all bits
    std::bitset<6> result = inverted.to_ulong() + 1; // Add 1 to the inverted bits
    return result.to_string(); // Convert back to a 6-bit binary string
}

// Machine code generator class
class MachineCodeGenerator {
public:
    std::string getMachineCode(const AsmInstruction& asmInst) {
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
                return generateSub(asmInst, std::nullopt);
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
                // return generateXor(asmInst, std::nullopt, std::nullopt, std::nullopt, std::nullopt);
            case Instruction::NOT:
                // return generateNot(asmInst, std::nullopt, std::nullopt, std::nullopt, std::nullopt);
            case Instruction::PUSH:
                return generatePush(asmInst, std::nullopt);
            case Instruction::POP:
                return generatePop(asmInst, std::nullopt);
            case Instruction::SET:
                // return generateSet(asmInst, std::nullopt, std::nullopt, std::nullopt, std::nullopt);
            default:
                return "UNKNOWN_INSTRUCTION";
        }
    }

    

private:
    std::string generateMov(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg2 = std::nullopt) {
        std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
        std::string reg2 = customReg2.value_or(asmInst.reg2).to_string();
        return "0101" + reg1 + reg2 + "000000";
    }

    std::string generateLoad(const AsmInstruction& asmInst, 
                             const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                             const std::optional<std::bitset<3>>& customReg2 = std::nullopt) {
        std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
        std::string reg2 = customReg2.value_or(asmInst.reg2).to_string();
        return "0010" + reg2 + reg1 + "000000";
    }

    std::string generateStore(const AsmInstruction& asmInst, 
                              const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                              const std::optional<std::bitset<3>>& customReg2 = std::nullopt) {
        std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
        std::string reg2 = customReg2.value_or(asmInst.reg2).to_string();
        return "0100" + reg2 + reg1 + "000000";
    }

    std::string generateAdd(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg2 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                            const std::optional<std::bitset<6>>& customImm = std::nullopt) {
        std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
        std::string reg2 = customReg2.value_or(asmInst.reg2).to_string();
        std::string reg3 = customReg3.value_or(asmInst.reg3).to_string();
        std::string imm = customImm.has_value() ? customImm->to_string() : asmInst.imm.to_string();
        std::cout << imm.empty() << std::endl;
        if  (customReg2 == std::nullopt && (customImm != std::nullopt || asmInst.imm_set))  { // Check for non-zero immediate value
            return "0101" + reg1 + reg3 + imm;
        } else {
            return "0100" + reg1 + reg2 + reg3 + "000";
        }
    }

    std::string generateSub(const AsmInstruction& asmInst, 
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

    std::string generateMul(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg2 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg3 = std::nullopt) {
        std::string reg2 = customReg2.value_or(asmInst.reg2).to_string();
        std::string reg3 = customReg3.value_or(asmInst.reg3).to_string();

        // Adjust according to your actual machine code specifications
        return "0111" + reg2 + reg3 + "000001" + "\n"
             + "1111" + reg2 + reg2 + reg2 + "100" + "\n"
             + "1111" + asmInst.reg1.to_string() + asmInst.reg1.to_string() + asmInst.reg1.to_string() + "011";
    }

    std::string generateDiv(const AsmInstruction& asmInst, 
                           const std::optional<std::bitset<3>>& customReg1 = std::nullopt) {
        std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
        return "DIV_MACHINE_CODE"; // Placeholder
    }
    std::string generateInc(const AsmInstruction& asmInst, 
                           const std::optional<std::bitset<3>>& customReg1 = std::nullopt) {
        std::bitset<3> reg1 = customReg1.value_or(asmInst.reg1);
        return generateAdd(asmInst, reg1, std::nullopt, reg1, 1); // Placeholder
    }
    std::string generateDec(const AsmInstruction& asmInst, 
                           const std::optional<std::bitset<3>>& customReg1 = std::nullopt) {
        std::bitset<3> reg1 = customReg1.value_or(asmInst.reg1);
        return generateAdd(asmInst, reg1, std::nullopt, reg1, -1); // Placeholder
    }
    std::string generateBeq(const AsmInstruction& asmInst, 
                           const std::optional<std::bitset<3>>& customReg1 = std::nullopt,
                           const std::optional<std::bitset<3>>& customReg2 = std::nullopt,
                           const std::optional<std::bitset<6>>& customImm = std::nullopt) {
        std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
        std::string reg2 = customReg2.value_or(asmInst.reg1).to_string();
        std::string imm = customImm.value_or(asmInst.imm).to_string();
        return "1000" + reg2 + reg1+ imm; 
    }
    std::string generateBne(const AsmInstruction& asmInst, 
                           const std::optional<std::bitset<3>>& customReg1 = std::nullopt,
                           const std::optional<std::bitset<3>>& customReg2 = std::nullopt,
                           const std::optional<std::bitset<6>>& customImm = std::nullopt) {
        std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
        std::string reg2 = customReg2.value_or(asmInst.reg1).to_string();
        std::string imm = customImm.value_or(asmInst.imm).to_string();
        return "1001" + reg2 + reg1 + imm; // Placeholder
    }
    std::string generateBgez(const AsmInstruction& asmInst, 
                           const std::optional<std::bitset<3>>& customReg1 = std::nullopt,
                           const std::optional<std::bitset<6>>& customImm = std::nullopt) {
        std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
        std::string imm = customImm.value_or(asmInst.imm).to_string();
        return "1001" + reg1 + reg1+ imm; // Placeholder
    }
    std::string generateBltz(const AsmInstruction& asmInst, 
                           const std::optional<std::bitset<3>>& customReg1 = std::nullopt,
                           const std::optional<std::bitset<6>>& customImm = std::nullopt) {
        std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
        std::string imm = customImm.value_or(asmInst.imm).to_string();
        return "1011" + reg1 + reg1+ imm; // Placeholder
    }

    std::string generateAnd(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg2 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                            const std::optional<std::bitset<6>>& customImm = std::nullopt) {
        std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
        std::string reg2 = customReg2.value_or(asmInst.reg2).to_string();
        std::string reg3 = customReg3.value_or(asmInst.reg3).to_string();
        std::string imm = customImm.has_value() ? customImm->to_string() : asmInst.imm.to_string();
        std::cout << imm.empty() << std::endl;
        if  (customReg2 == std::nullopt && (customImm != std::nullopt || asmInst.imm_set))  { // Check for non-zero immediate value
            return "0110" + reg1 + reg3 + imm;
        } else {
            return "1111" + reg1 + reg2 + reg3 + "000";
        }
    }
    std::string generateOr(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg2 = std::nullopt, 
                            const std::optional<std::bitset<3>>& customReg3 = std::nullopt, 
                            const std::optional<std::bitset<6>>& customImm = std::nullopt) {
        std::string reg1 = customReg1.value_or(asmInst.reg1).to_string();
        std::string reg2 = customReg2.value_or(asmInst.reg2).to_string();
        std::string reg3 = customReg3.value_or(asmInst.reg3).to_string();
        std::string imm = customImm.has_value() ? customImm->to_string() : asmInst.imm.to_string();
        std::cout << imm.empty() << std::endl;
        if  (customReg2 == std::nullopt && (customImm != std::nullopt || asmInst.imm_set))  { // Check for non-zero immediate value
            return "0111" + reg1 + reg3 + imm;
        } else {
            return "1111" + reg1 + reg2 + reg3 + "110";
        }
    }

    std::string generatePush(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt) {
        std::bitset<3> reg1 = customReg1.value_or(asmInst.reg1);
        
        
        return generateStore(asmInst, reg1, 8) + "\n" + generateSub(asmInst, 8, std::nullopt, 8, -1);
    }
    
     std::string generatePop(const AsmInstruction& asmInst, 
                            const std::optional<std::bitset<3>>& customReg1 = std::nullopt) {
        std::bitset<3> reg1 = customReg1.value_or(asmInst.reg1);
        
            
        return generateLoad(asmInst, reg1, 8)  +  "\n" + generateAdd(asmInst, 8, std::nullopt, 8, 1);
    }

};
// Basic assembler class
class Assembler {
public:
    Assembler() : codeGen() {}
    void parse(const std::string& line) {
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
                   opcode == "AND" || opcode == "XOR" || opcode == "NOT") {
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
            else if (opcode == "NOT")
                asmInst.instr = Instruction::NOT;

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
    }


    void assemble() {
        for (const auto& inst : instructions) {
            std::cout << codeGen.getMachineCode(inst) << std::endl;
        }
    }

    void readFile(const std::string& filename) {
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

private:
    std::vector<AsmInstruction> instructions;
    MachineCodeGenerator codeGen; 
    std::bitset<3> parseRegister(const std::string& regStr) {
        if (regStr.size() == 3 && regStr.find_first_not_of("01") == std::string::npos) {
            // The string is a binary representation
            return std::bitset<3>(regStr);
        } else {
            // The string is a decimal number
            return std::bitset<3>(std::stoi(regStr));
        }
    }
};

int main() {
    // Example usage
    Assembler assembler;
    assembler.readFile("/home/ivan/cpu/ASSEMBLER/src/assembly.asm");

    // Assemble the instructions and output the machine code
    assembler.assemble();




    return 0;
}
