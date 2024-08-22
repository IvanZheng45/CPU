#ifndef LOGICAL_H
#define LOGICAL_H

#include "symbols.h"

class Logical {
public:
    Logical(Word* Y, bool* C, bool* V);

    void logic(Word A, Word B, bool OA);

private:
    Word* Y;    // Pointer to the result
    bool* C;    // Pointer to the carry out
    bool* V;    // Pointer to the overflow
};
#endif
