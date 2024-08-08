#include "adder.h"
#include "symbols.h"
#include <iostream>

// Constructor
Adder::Adder(Byte* Y, bool* C, bool* V) : Y(Y), C(C), V(V) {}

// Function to perform the addition
void Adder::add(Byte A, Byte B, bool CI) {
    bool carry_out[8] = {0}; // Array to hold carry bits
    *Y = 0; // Initialize result to 0

    // Calculate the sum for each bit
    for (int i = 0; i < 8; ++i) {
        bool ai = (A >> i) & 0x01;
        bool bi = (B >> i) & 0x01;
        bool sum = ai ^ bi ^ CI; // Sum for the current bit
        carry_out[i] = (CI & ai) | (CI & bi) | (ai & bi); // Carry out for the next bit

        *Y |= (sum << i); // Set the sum bit in the result
        CI = carry_out[i]; // Update CI for the next bit
    }

    // Set the final carry out and overflow
    *C = carry_out[7]; // Final carry out
    *V = carry_out[6] ^ carry_out[7]; // Overflow
    


}
