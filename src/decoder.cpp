#include "decoder.h"
#include "symbols.h"


Decoder::Decoder(Word inst) : INST(inst) {}


void Decoder::decode() {
    Byte OP = (INST >> 12) & 0xF;
    Byte RS = (INST >> 9) & 0x7;
    Byte RT = (INST >> 6) & 0x7;
    Byte RD = (INST >> 3) & 0x7;
    Byte FUNCT = INST & 0x7;
    Byte IMM_INST = INST & 0x3F;

    switch (OP) {
        case 0x0:
            if (FUNCT == 0x0) {
                DR = RD;
                SA = RS;
                SB = RT;
                IMM = IMM_INST;
                MB = false;
                FS = 0x0;
                MD = false;
                LD = false;
                MW = false;
                HLT = false;
                BS = 0x4;
                OFF = 0x0;
            } else {
                DR = RD;
                SA = RS;
                SB = RT;
                IMM = IMM_INST;
                MB = false;
                FS = 0x0;
                MD = false;
                LD = false;
                MW = false;
                HLT = true;
                BS = 0x4;
                OFF = 0x0;
            }
            break;
        case 0x2:
            DR = RT;
            SA = RS;
            SB = RT;
            IMM = IMM_INST;
            MB = true;
            FS = 0x0;
            MD = true;
            LD = true;
            MW = false;
            HLT = false;
            BS = 0x4;
            OFF = 0x0;
            break;
        case 0x4:
            DR = RT;
            SA = RS;
            SB = RT;
            IMM = IMM_INST;
            MB = true;
            FS = 0x0;
            MD = false;
            LD = false;
            MW = true;
            HLT = false;
            BS = 0x4;
            OFF = 0x0;
            break;
        case 0x5:
            DR = RT;
            SA = RS;
            SB = RT;
            IMM = IMM_INST;
            MB = true;
            FS = 0x0;
            MD = false;
            LD = true;
            MW = false;
            HLT = false;
            BS = 0x4;
            OFF = 0x0;
            break;
        case 0x6:
            DR = RT;
            SA = RS;
            SB = RT;
            IMM = IMM_INST;
            MB = true;
            FS = 0x5;
            MD = false;
            LD = true;
            MW = false;
            HLT = false;
            BS = 0x4;
            OFF = 0x0;
            break;
        case 0x7:
            DR = RT;
            SA = RS;
            SB = RT;
            IMM = IMM_INST;
            MB = true;
            FS = 0x6;
            MD = false;
            LD = true;
            MW = false;
            HLT = false;
            BS = 0x4;
            OFF = 0x0;
            break;
        case 0x8:
            DR = 0x0;
            SA = RS;
            SB = RT;
            IMM = IMM_INST;
            MB = false;
            FS = 0x1;
            MD = false;
            LD = false;
            MW = false;
            HLT = false;
            BS = 0x0;
            OFF = IMM_INST;
            break;
        case 0x9:
            DR = 0x0;
            SA = RS;
            SB = RT;
            IMM = IMM_INST;
            MB = false;
            FS = 0x1;
            MD = false;
            LD = false;
            MW = false;
            HLT = false;
            BS = 0x1;
            OFF = IMM_INST;
            break;
        case 0xA:
            DR = 0x0;
            SA = RS;
            SB = 0x0;
            IMM = 0x0;
            MB = true;
            FS = 0x0;
            MD = false;
            LD = false;
            MW = false;
            HLT = false;
            BS = 0x2;
            OFF = IMM_INST;
            break;
        case 0xB:
            DR = 0x0;
            SA = RS;
            SB = 0x0;
            IMM = 0x0;
            MB = true;
            FS = 0x1;
            MD = false;
            LD = false;
            MW = false;
            HLT = false;
            BS = 0x3;
            OFF = IMM_INST;
            break;
        case 0xF:
            DR = RD;
            SA = RS;
            SB = RT;
            IMM = IMM_INST;
            MB = false;
            FS = FUNCT;
            MD = false;
            LD = true;
            MW = false;
            HLT = false;
            BS = 0x4;
            OFF = 0x0;
            break;
        default:
            DR = RD;
            SA = RS;
            SB = RT;
            IMM = IMM_INST;
            MB = false;
            FS = 0x0;
            MD = false;
            LD = false;
            MW = false;
            HLT = false;
            BS = 0x4;
            OFF = 0x0;
            break;
    }
}

Byte Decoder::getDR() const { return DR; }
Byte Decoder::getSA() const { return SA; }
Byte Decoder::getSB() const { return SB; }
Byte Decoder::getIMM() const { return IMM; }
bool Decoder::getMB() const { return MB; }
Byte Decoder::getFS() const { return FS; }
bool Decoder::getMD() const { return MD; }
bool Decoder::getLD() const { return LD; }
bool Decoder::getMW() const { return MW; }
bool Decoder::getHLT() const { return HLT; }
Byte Decoder::getBS() const { return BS; }
Byte Decoder::getOFF() const { return OFF; }
