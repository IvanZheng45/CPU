#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decoder.h"
#include <iostream>
#include "symbols.h"


struct Mem
{
    static constexpr u32 MAX_MEM = 1024*64;
    Byte Data[MAX_MEM];
    
    void Initialize(){

        for (u32 i = 0; i<MAX_MEM; i++){
            Data[i] = 0;
        }
    }

    Byte operator[](u32 Address) const{
        return Data[Address];
    }

    Byte& operator[](u32 Address) {
        return Data[Address];
    }


};

struct CPU
{   
    
    Word PC;
    Word SP;

    Byte C : 1;
    Byte V : 1;
    Byte N : 1;
    Byte Z : 1;

    void Reset(Mem& memory){
        PC = 0xFFFC;
        SP = 0xFF;
        C = V = N = Z = 0;

        memory.Initialize();
    }

    Word instruction_fetch(Mem& memory){
        
        Byte a = memory[PC];
        Byte b = memory[PC+1];

        char str_a[8], str_b[8];

        sprintf(str_a, "%02X", a);
        sprintf(str_b, "%02X", b);

        char result_str[16];

        strcpy(result_str, str_a);
        strcat(result_str, str_b);

        // Convert the concatenated string back to an integer
        Word Iin = static_cast<Word>(strtol(result_str, nullptr, 16));
        
        return Iin;
    }

    void Execute(Mem& memory){
        while (true){
            Word Iin = instruction_fetch(memory);
            Decoder decoder(Iin);
            decoder.decode();

            std::cout << "DR: " << static_cast<int>(decoder.getDR()) << std::endl;
            std::cout << "SA: " << static_cast<int>(decoder.getSA()) << std::endl;
            std::cout << "SB: " << static_cast<int>(decoder.getSB()) << std::endl;
            std::cout << "IMM: " << static_cast<int>(decoder.getIMM()) << std::endl;
            std::cout << "MB: " << decoder.getMB() << std::endl;
            std::cout << "FS: " << static_cast<int>(decoder.getFS()) << std::endl;
            std::cout << "MD: " << decoder.getMD() << std::endl;
            std::cout << "LD: " << decoder.getLD() << std::endl;
            std::cout << "MW: " << decoder.getMW() << std::endl;
            std::cout << "HLT: " << decoder.getHLT() << std::endl;
            std::cout << "BS: " << static_cast<int>(decoder.getBS()) << std::endl;
            std::cout << "OFF: " << static_cast<int>(decoder.getOFF()) << std::endl;

        }

    }

};

int main()
{   
    Mem mem;
    CPU cpu;
    cpu.Reset(mem);

    mem[0xFFFC] = 0xA9;
    mem[0xFFFD] = 0xA9;
    cpu.Execute(mem);
    

}