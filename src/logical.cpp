#include "logical.h"
#include "symbols.h"

Logical::Logical(Byte* Y, bool* C, bool* V) : Y(Y), C(C), V(V) {}

void Logical::logic(Byte A, Byte B, bool OA) {
    *C = 0;
    *V = 0;
   for (int i = 0; i < 8; i++) {
        int bitA = (A >> i) & 1;
        int bitB = (B >> i) & 1;
        int bitY = OA ? (bitA & bitB) : (bitA | bitB);
        *Y |= (bitY << i); 
    }; 
}
