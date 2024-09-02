#include "decoder.h"
#include <iostream>


// Constructor
Decoder::Decoder(Byte* dr, Byte* sa, Byte* sb, Byte* imm, bool* mb, Byte* fs, bool* md, bool* ld, bool* mw, bool* hlt, Byte* bs, Byte* off)
    : dr(dr), sa(sa), sb(sb), imm(imm), mb(mb), fs(fs), md(md), ld(ld), mw(mw), hlt(hlt), bs(bs), off(off) {
}

// Decode method
void Decoder::decode(Word INST) {

    Byte OP = (INST >> 12) & 0xF;
    Byte RS = (INST >> 9) & 0x7;
    Byte RT = (INST >> 6) & 0x7;
    Byte RD = (INST >> 3) & 0x7;
    Byte FUNCT = INST & 0x7;
    Byte IMM_INST = INST & 0x3F;
    switch (OP) {
        case 0x0:
            if (FUNCT == 0x0) {
                *dr = RD;
                *sa = RS;
                *sb = RT;
                *imm = IMM_INST;
                *mb = false;
                *fs = 0x0;
                *md = false;
                *ld = false;
                *mw = false;
                *hlt = false;
                *bs = 0x4;
                *off = 0x0;
            } else {
                *dr = RD;
                *sa = RS;
                *sb = RT;
                *imm = IMM_INST;
                *mb = false;
                *fs = 0x0;
                *md = false;
                *ld = false;
                *mw = false;
                *hlt = true;
                *bs = 0x4;
                *off = 0x0;
            }
            break;
        case 0x2:
            *dr = RT;
            *sa = RS;
            *sb = RT;
            *imm = IMM_INST;
            *mb = true;
            *fs = 0x0;
            *md = true;
            *ld = true;
            *mw = false;
            *hlt = false;
            *bs = 0x4;
            *off = 0x0;
            break;
        case 0x4:
            *dr = RT;
            *sa = RS;
            *sb = RT;
            *imm = IMM_INST;
            *mb = true;
            *fs = 0x0;
            *md = false;
            *ld = false;
            *mw = true;
            *hlt = false;
            *bs = 0x4;
            *off = 0x0;
            break;
        case 0x5:
            *dr = RT;
            *sa = RS;
            *sb = RT;
            *imm = IMM_INST;
            *mb = true;
            *fs = 0x0;
            *md = false;
            *ld = true;
            *mw = false;
            *hlt = false;
            *bs = 0x4;
            *off = 0x0;
            break;
        case 0x6:
            *dr = RT;
            *sa = RS;
            *sb = RT;
            *imm = IMM_INST;
            *mb = true;
            *fs = 0x5;
            *md = false;
            *ld = true;
            *mw = false;
            *hlt = false;
            *bs = 0x4;
            *off = 0x0;
            break;
        case 0x7:
            *dr = RT;
            *sa = RS;
            *sb = RT;
            *imm = IMM_INST;
            *mb = true;
            *fs = 0x6;
            *md = false;
            *ld = true;
            *mw = false;
            *hlt = false;
            *bs = 0x4;
            *off = 0x0;
            break;
        case 0x8:
            *dr = 0x0;
            *sa = RS;
            *sb = RT;
            *imm = IMM_INST;
            *mb = false;
            *fs = 0x1;
            *md = false;
            *ld = false;
            *mw = false;
            *hlt = false;
            *bs = 0x0;
            *off = IMM_INST;
            break;
        case 0x9:
            *dr = 0x0;
            *sa = RS;
            *sb = RT;
            *imm = IMM_INST;
            *mb = false;
            *fs = 0x1;
            *md = false;
            *ld = false;
            *mw = false;
            *hlt = false;
            *bs = 0x1;
            *off = IMM_INST;
            break;
        case 0xA:
            *dr = 0x0;
            *sa = RS;
            *sb = 0x0;
            *imm = 0x0;
            *mb = true;
            *fs = 0x0;
            *md = false;
            *ld = false;
            *mw = false;
            *hlt = false;
            *bs = 0x2;
            *off = IMM_INST;
            break;
            
        case 0xB:
            *dr = 0x0;
            *sa = RS;
            *sb = 0x0;
            *imm = 0x0;
            *mb = true;
            *fs = 0x1;
            *md = false;
            *ld = false;
            *mw = false;
            *hlt = false;
            *bs = 0x3;
            *off = IMM_INST;
            break;
        case 0xF:
            *dr = RD;
            *sa = RS;
            *sb = RT;
            *imm = IMM_INST;
            *mb = false;
            *fs = FUNCT;
            *md = false;
            *ld = true;
            *mw = false;
            *hlt = false;
            *bs = 0x4;
            *off = 0x0;
            break;
        default:
            *dr = RD;
            *sa = RS;
            *sb = RT;
            *imm = IMM_INST;
            *mb = false;
            *fs = 0x0;
            *md = false;
            *ld = false;
            *mw = false;
            *hlt = false;
            *bs = 0x4;
            *off = 0x0;
            break;
    }
}
