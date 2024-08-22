#ifndef ADDER_H
#define ADDER_H

#include "symbols.h"

class Adder {
public:
    Adder(Word* Y, bool* C, bool* V);

    void add(Word A, Word B, bool CI);

private:
    Word* Y;    // Pointer to the result
    bool* C;    // Pointer to the carry out
    bool* V;    // Pointer to the overflow
};
#endif // ADDER_H
