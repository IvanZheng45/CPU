#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decoder.h"
#include <iostream>
#include "symbols.h"
#include "control.h"

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

    Byte dr, sa, sb, imm, fs, bs, off, CSEL, OSEL;
    bool mb, md, ld, mw, hlt, C, V, N, Z, BSEL, CISEL, LA, LR, OA;

    Decoder decoder;
    Control control;

    CPU() : 
        dr(0), sa(0), sb(0), imm(0), fs(0), bs(0), off(0), CSEL(0), OSEL(0),
        mb(false), md(false), ld(false), mw(false), hlt(false),
        C(false), V(false), N(false), Z(false),
        BSEL(false), CISEL(false), LA(false), LR(false), OA(false),
        decoder(&dr, &sa, &sb, &imm, &mb, &fs, &md, &ld, &mw, &hlt, &bs, &off),
        control(&BSEL, &CISEL, &CSEL, &OSEL, &LA, &LR, &OA)
    {}


    void Reset(Mem& memory){
        PC = 0xFFFC;
        SP = 0xFF;

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
        Word Iin = instruction_fetch(memory);

        decoder.decode(Iin);   
   
        control.control(fs);

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