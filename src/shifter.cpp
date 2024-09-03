#include "shifter.h"
#include "symbols.h"
#include <iostream>

Shifter::Shifter(Word* Y, bool* C, bool* V) : Y(Y), C(C), V(V) {}

void Shifter::shift(Word A, Word B, bool LA, bool LR) {
  *Y = 0;

        // Perform the shifting operation using a loop
        for (int i = 0; i < 16; ++i) {
            if (LR) {
                if (i < 15) {
                    *Y |= ((A >> (i + 1)) & 1) << i;
                } else {
                    *Y |= (LA ? (A & 0x8000) : 0);  // Handle the last bit (Y[15])
                }
            } else {
                if (i > 0) {
                    *Y |= ((A >> (i - 1)) & 1) << i;
                }
            }
        }

        // Set the carry bit
        *C = LR ? (A & 1) : ((A >> 15) & 1);
    
}

    

