#ifndef LOGICAL_H
#define LOGICAL_H

#include "symbols.h"

class Logical {
public:
    Logical(Byte* Y, bool* C, bool* V);

    void logic(Byte A, Byte B, bool OA);

private:
    Byte* Y;    // Pointer to the result
    bool* C;    // Pointer to the carry out
    bool* V;    // Pointer to the overflow
};
#endif
