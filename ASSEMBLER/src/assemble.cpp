#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>

// Define instruction types and registers
enum class Instruction {
    SET, MOV, ADD, SUB, MUL, DIV, INC, DEC,
    BEQ, BNE, BGEZ, BLTZ,
    AND, XOR, NOT, PUSH, POP
};

// Define a structure for instructions
struct AsmInstruction {
    Instruction instr;
    std::bitset<3> reg1;  // 3-bit register value
    std::bitset<3> reg2;  // 3-bit register value
    int imm;
};

// Function to convert instruction to machine code (placeholder)
std::string getMachineCode(const AsmInstruction& asmInst) {
    // Placeholder machine code generation
    // Replace with actual machine code generation logic
    switch (asmInst.instr) {
        case Instruction::MOV:
            return "MOV_MACHINE_CODE";
        case Instruction::ADD:
            return "ADD_MACHINE_CODE";
        case Instruction::BEQ:
            return "BEQ_MACHINE_CODE"; // Handle immediate value
        // Add other cases here
        default:
            return "UNKNOWN_INSTRUCTION";
    }
}

// Basic assembler
class Assembler {
public:
    void parse(const std::string& line) {
        std::istringstream iss(line);
        std::string opcode;
        std::string reg1Str, reg2Str;
        std::string immStr;
        AsmInstruction asmInst;

        iss >> opcode;

        if (opcode == "MOV") {
            asmInst.instr = Instruction::MOV;
            iss >> reg1Str >> reg2Str;
            asmInst.reg1 = std::bitset<3>(reg1Str);
            reg2Str.erase(0, 1); // Remove leading comma
            asmInst.reg2 = std::bitset<3>(reg2Str);
        } else if (opcode == "ADD") {
            asmInst.instr = Instruction::ADD;
            iss >> reg1Str >> reg2Str;
            asmInst.reg1 = std::bitset<3>(reg1Str);
            reg2Str.erase(0, 1); // Remove leading comma
            asmInst.reg2 = std::bitset<3>(reg2Str);
        } else if (opcode == "BEQ") {
            asmInst.instr = Instruction::BEQ;
            iss >> reg1Str >> reg2Str >> immStr;
            asmInst.reg1 = std::bitset<3>(reg1Str);
            reg2Str.erase(0, 1); // Remove leading comma
            asmInst.reg2 = std::bitset<3>(reg2Str);
            asmInst.imm = std::stoi(immStr);
        } else {
            std::cerr << "Unknown opcode: " << opcode << std::endl;
            return;
        }

        // Add instruction to the list
        instructions.push_back(asmInst);
    }

    void assemble() {
        for (const auto& inst : instructions) {
            std::cout << getMachineCode(inst) << std::endl;
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
};

// Example usage
int main() {
    Assembler assembler;

    // Read and parse assembly code from a file
    assembler.readFile("assembly.asm");

    // Assemble the instructions and output the machine code
    assembler.assemble();

    return 0;
}
