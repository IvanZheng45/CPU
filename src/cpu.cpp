#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "decoder.h"
#include "symbols.h"
#include "control.h"
#include "alu.h"
#include <SDL2/SDL.h>
#include "display.h"

struct Mem {
    static constexpr u32 MAX_MEM = 1024 * 64;
    Word Data[MAX_MEM];

    void Initialize() {
        for (u32 i = 0; i < MAX_MEM; i++) {
            Data[i] = 0;
        }
    }

    Word operator[](u32 Address) const {
        return Data[Address];
    }

    Word& operator[](u32 Address) {
        return Data[Address];
    }
};

struct reg_file {
    Word reg[8];

    void Initialize() {
        for (Byte i = 0; i < 8; i++) {
            reg[i] = 0;
        }
        reg[8] = 0xFF;
    }

    Word operator[](Byte reg_num) const {
        return reg[reg_num];
    }

    Word& operator[](Byte reg_num) {
        return reg[reg_num];
    }
};

struct CPU {
    Word pc, sp, Y;
    
    Byte dr, sa, sb, imm, fs, bs, off;
    bool mb, md, ld, mw, hlt, mp, pcsel, C, V, N, Z;

    Decoder decoder;
    Alu alu;
    Display display;

    CPU() :
        dr(0), sa(0), sb(0), imm(0), fs(0), bs(0), off(0), Y(0),
        mb(false), md(false), ld(false), mw(false), hlt(false), mp(false), pcsel(false),
        C(false), V(false), N(false), Z(false),
        decoder(&dr, &sa, &sb, &imm, &mb, &fs, &md, &ld, &mw, &hlt, &bs, &off),
        alu(&Y, &C, &V, &N, &Z) {}

    void Reset(Mem& memory, reg_file& reg) {
        pc = 0x100;
        sp = 0xFF;

        memory.Initialize();
        reg.Initialize();
    }


    void checkButtonPress() {
        std::cout << "CPU is halted. Press Enter to continue..." << std::endl;
        std::cin.get();
    }

    void update_video(Mem& memory) {
        static constexpr u32 MAX_MEM = 1024 * 64;
        static constexpr u32 video_size = 64*64;
        Word video_start = MAX_MEM - video_size;

        while (video_start < MAX_MEM - video_size+1) {
            SDL_Color sdl_color;
            
            Byte x = ((video_start - video_size) % 128);
            Byte y = ((video_start - video_size) / 128);

            Word color = memory[video_start];

            Byte red   = (color >> 11) & 0x1F; // 5 bits for red
            Byte green = (color >> 5) & 0x3F;  // 6 bits for green
            Byte blue  = color & 0x1F;         // 5 bits for blue


            sdl_color.r = (red << 3) | (red >> 2);   // 5-bit to 8-bit
            sdl_color.g = (green << 2) | (green >> 4); // 6-bit to 8-bit
            sdl_color.b = (blue << 3) | (blue >> 2);   // 5-bit to 8-bit
            sdl_color.a = 255; // Full opacity (255)

            display.SetPixel(x, y, sdl_color);
            
            video_start +=2;
        }
        display.Update();
    }

    void Execute(Mem& memory, reg_file& reg) {

        while (memory[pc]!=0) {
            Word Iin = memory[pc];

            decoder.decode(Iin);
       
            word IMM_SE = imm & 0x3FFF;
            IMM_SE |= ((imm & 0x2000) ? 0xC000 : 0);

            Word DataA = reg[sa];
            Word DataB = reg[sb];

            alu.alu(DataA, mb ? IMM_SE : DataB, fs);
            Word DataD = Y;

            Word DataC = md ? memory[Y] : DataD;

            if (ld) {
                reg[dr] = DataC;
            }

            if (mw) {
                memory[Y] = DataB;
            }

            if (hlt) {
                checkButtonPress();
                pcsel = 0;
            }

            switch (bs) {
                case 0: mp = Z; break;
                case 1: mp = !Z; break;
                case 2: mp = !N; break;
                case 3: mp = N; break;
                default: mp = false; break;
            }

            pcsel = mp;

            update_video(memory);

            pcsel = 1;

            if (!pcsel) {
                pc += 1;
            } else {
                alu.alu(pc, IMM_SE, 0); 
                pc = Y;
            }
        
        }
    }
};

int main() {
    Mem mem;
    CPU cpu;
    reg_file reg;
    cpu.Reset(mem, reg);

    mem[0x100] = 0b0010000010011111;
    mem[0x101] = 0b0000000000000001;

    cpu.Execute(mem, reg);

    return 0;
}
