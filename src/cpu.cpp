#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decoder.h"
#include <iostream>
#include "symbols.h"
#include "control.h"
#include "alu.h"
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

struct reg_file
{
    Byte reg[8];
    
    void Initialize(){

        for (Byte i = 0; i<8; i++){
            reg[i] = 0;
        }
    }

    Byte operator[](Byte reg_num) const{
        return reg[reg_num];
    }

    Byte& operator[](Byte reg_num) {
        return reg[reg_num];
    }


};

struct CPU
{   
    Word pc;
    Word sp;

    Byte dr, sa, sb, imm, fs, bs, off, Y;
    bool mb, md, ld, mw, hlt, mp, pcsel, C, V, N, Z;

    Decoder decoder;
    Alu alu;

    CPU() : 
        dr(0), sa(0), sb(0), imm(0), fs(0), bs(0), off(0), Y(0),
        mb(false), md(false), ld(false), mw(false), hlt(false), mp(false), pcsel(false),
        C(false), V(false), N(false), Z(false),
        decoder(&dr, &sa, &sb, &imm, &mb, &fs, &md, &ld, &mw, &hlt, &bs, &off),
        alu(&Y, &C, &V, &N, &Z)
    {}


    void Reset(Mem& memory, reg_file& reg){
        pc = 0xFFFC;
        sp = 0xFF;

        memory.Initialize();
        reg.Initialize();
    }

    Word instruction_fetch(Mem& memory){
        
        Byte a = memory[pc];
        Byte b = memory[pc+1];

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
    
    void checkButtonPress() {
        std::cout << "CPU is halted. Press Enter to continue..." << std::endl;
        std::cin.get();
    }

    void Execute(Mem& memory, reg_file& reg){
        Word Iin = instruction_fetch(memory);


        decoder.decode(Iin);   
   

        Byte IMM_SE = imm & 0x3F; 
        IMM_SE |= ((imm & 0x20) ? 0xC0 : 0);
    
        Byte DataA = reg[sa];
        Byte DataB = reg[sb];

        alu.alu(DataA, mb ? IMM_SE : DataB, fs);
        Byte DataD = Y;
        
        Byte DataC = md ? memory[Y] : DataD;
        
        if (ld){
            reg[dr] = DataC;
        }
        
        if (mw){
            memory[Y] = DataB;
        };

        if (hlt) {
            checkButtonPress();
        }

        if (bs == 0) {
            mp = Z;
        } else if (bs == 1) {
            mp = !Z;
        } else if (bs == 2) {
            mp = !N;
        } else if (bs == 3) {
            mp = N;
        } else {
            mp = false;
        }

        pcsel = mp;
        
        if (!pcsel){
            pc += 2;
        }
        else{
            pc += imm*2 + 2;
        }


    };

};

int main()
{   
    Mem mem;
    CPU cpu;
    reg_file reg;
    cpu.Reset(mem, reg);

    mem[0xFFFC] = 0;
    mem[0xFFFD] = 0;
    cpu.Execute(mem, reg);
    

}