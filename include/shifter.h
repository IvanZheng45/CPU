#ifndef SHIFTER_H
#define SHIFTER_H

#include "symbols.h"

class Shifter {
public:
    Shifter(Word* Y, bool* C, bool* V);

    void shift(Word A, Word B, bool LA, bool LR);

private:
    Word* Y;    // Pointer to the result
    bool* C;    // Pointer to the carry out
    bool* V;    // Pointer to the overflow
};
#endif
