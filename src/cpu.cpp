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
    Byte Data[MAX_MEM];

    void Initialize() {
        for (u32 i = 0; i < MAX_MEM; i++) {
            Data[i] = 0;
        }
    }

    Byte operator[](u32 Address) const {
        return Data[Address];
    }

    Byte& operator[](u32 Address) {
        return Data[Address];
    }
};

struct reg_file {
    Byte reg[8];

    void Initialize() {
        for (Byte i = 0; i < 8; i++) {
            reg[i] = 0;
        }
        reg[8] = 0xFF;
    }

    Byte operator[](Byte reg_num) const {
        return reg[reg_num];
    }

    Byte& operator[](Byte reg_num) {
        return reg[reg_num];
    }
};

struct CPU {
    Word pc;
    Word sp;
    
    Byte dr, sa, sb, imm, fs, bs, off, Y;
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

    Word word_fetch(Mem& memory, Word point) {
        Byte a = memory[point];
        Byte b = memory[point + 1];
            
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

    void update_video(Mem& memory) {
        static constexpr u32 MAX_MEM = 1024 * 64;
        static constexpr u32 video_size = 64*64*2;
        Word video_start = MAX_MEM - video_size; // allocate 2 bytes (16 bits) for each pixel

        while (video_start < MAX_MEM - video_size+1) {
            SDL_Color sdl_color;
            
            Byte x = ((video_start - video_size) % 128)/2;
            Byte y = ((video_start - video_size) / 128);

            Word color = word_fetch(memory, video_start);

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

        while (word_fetch(memory, pc)) {
            Word Iin = word_fetch(memory, pc);

            decoder.decode(Iin);
            imm = 0b111111;
            Byte IMM_SE = imm & 0x3F;
            IMM_SE |= ((imm & 0x20) ? 0xC0 : 0);

            Byte DataA = reg[sa];
            Byte DataB = reg[sb];

            alu.alu(DataA, mb ? IMM_SE : DataB, fs);
            Byte DataD = Y;

            Byte DataC = md ? memory[Y] : DataD;

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

            if (!pcsel) {
                pc += 2;
            } else {

                alu.alu(IMM_SE, 0, 4);

                alu.alu(pc, Y, 0);

                pc = Y;

            }
            sp = reg[8];
        }
    }
};

int main() {
    Mem mem;
    CPU cpu;
    reg_file reg;
    cpu.Reset(mem, reg);

    mem[0x100] = 0b00100000;
    mem[0x101] = 0b10011111;
    mem[0x102] = 0b00000000;
    mem[0x103] = 0b00000001;

    cpu.Execute(mem, reg);

    return 0;
}
