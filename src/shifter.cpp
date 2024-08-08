#include "shifter.h"
#include "symbols.h"

Shifter::Shifter(Byte* Y, bool* C, bool* V) : Y(Y), C(C), V(V) {}

void Shifter::shift(Byte A, Byte B, bool LA, bool LR) {
    *Y |= (LR ? ((A >> 1) & 0x01) : 0) << 0;
    *Y |= (LR ? ((A >> 2) & 0x01) : ((A >> 0) & 0x01)) << 1;
    *Y |= (LR ? ((A >> 3) & 0x01) : ((A >> 1) & 0x01)) << 2;
    *Y |= (LR ? ((A >> 4) & 0x01) : ((A >> 2) & 0x01)) << 3;
    *Y |= (LR ? ((A >> 5) & 0x01) : ((A >> 3) & 0x01)) << 4;
    *Y |= (LR ? ((A >> 6) & 0x01) : ((A >> 4) & 0x01)) << 5;
    *Y |= (LR ? ((A >> 7) & 0x01) : ((A >> 5) & 0x01)) << 6;
    *Y |= (LR ? (LA ? ((A >> 7) & 0x01) : 0) : ((A >> 6) & 0x01)) << 7;

    *C = LR ? (A & 0x01) : ((A >> 7) & 0x01);
    *V = 0;

}
