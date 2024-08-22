#include "shifter.h"
#include "symbols.h"

Shifter::Shifter(Word* Y, bool* C, bool* V) : Y(Y), C(C), V(V) {}

void Shifter::shift(Word A, Word B, bool LA, bool LR) {
    *Y = 0; // Clear Y before shifting

    // Perform the shift operation for each bit
    for (int i = 0; i < 16; ++i) {
        *Y |= (LR ? ((A >> (i + 1)) & 0x01) : (i < 15 ? ((A >> (i + 1)) & 0x01) : 0)) << i;
    }

    // Update carry and overflow
    *C = LR ? (A & 0x01) : ((A >> 15) & 0x01);
    *V = 0;
}
