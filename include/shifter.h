#ifndef SHIFTER_H
#define SHIFTER_H

#include "symbols.h"

class Shifter {
public:
    Shifter(Byte* Y, bool* C, bool* V);

    void shift(Byte A, Byte B, bool LA, bool LR);

private:
    Byte* Y;    // Pointer to the result
    bool* C;    // Pointer to the carry out
    bool* V;    // Pointer to the overflow
};
#endif
