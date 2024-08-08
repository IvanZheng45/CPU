#ifndef ADDER_H
#define ADDER_H

#include "symbols.h"

class Adder {
public:
    Adder(Byte* Y, bool* C, bool* V);

    void add(Byte A, Byte B, bool CI);

private:
    Byte* Y;    // Pointer to the result
    bool* C;    // Pointer to the carry out
    bool* V;    // Pointer to the overflow
};
#endif // ADDER_H
