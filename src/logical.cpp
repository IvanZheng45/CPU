#include "logical.h"
#include "symbols.h"
#include <iostream>
Logical::Logical(Word* Y, bool* C, bool* V) : Y(Y), C(C), V(V) {}

// Function to perform logical operations
void Logical::logic(Word A, Word B, bool OA) {
    *C = 0; // No carry in logical operations
    *V = 0; // No overflow in logical operations

    *Y = 0; // Initialize result to 0

    // Calculate the logical operation for each bit
    for (int i = 0; i < 16; i++) {
        bool bitA = (A >> i) & 1; // Extract the ith bit of A
        bool bitB = (B >> i) & 1; // Extract the ith bit of B
        bool bitY = OA ? (bitA & bitB) : (bitA | bitB); // AND if OA is true, OR if OA is false
        
        *Y |= (bitY << i); // Set the bit in the result
    }

}
