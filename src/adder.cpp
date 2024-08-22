#include "adder.h"
#include "symbols.h"
#include <iostream>

// Constructor
Adder::Adder(Word* Y, bool* C, bool* V) : Y(Y), C(C), V(V) {}

// Function to perform the addition
void Adder::add(Word A, Word B, bool CI) {
    bool carry_out[16] = {0}; // Array to hold carry bits
    *Y = 0; // Initialize result to 0

    // Calculate the sum for each bit
    for (int i = 0; i < 16; ++i) {
        bool ai = (A >> i) & 0x01; // Extract the ith bit of A
        bool bi = (B >> i) & 0x01; // Extract the ith bit of B
        bool sum = ai ^ bi ^ CI; // Sum for the current bit
        carry_out[i] = (CI & ai) | (CI & bi) | (ai & bi); // Carry out for the next bit

        // Set the sum bit in the result
        *Y |= (sum << i); 
        
        CI = carry_out[i]; // Update CI for the next bit
    }

    // Set the final carry out and overflow
    *C = carry_out[15]; // Final carry out
    *V = carry_out[14] ^ carry_out[15]; // Overflow
}
