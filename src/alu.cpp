#include "alu.h"
#include <iostream>
#include "symbols.h"
#include <bitset>
#include <cstdint>


Alu::Alu(Byte* Y, bool* C, bool* V, bool* N, bool* Z)
    : Y(Y), C(C), V(V), N(N), Z(Z), 
      control(&BSEL, &CISEL, &CSEL, &OSEL, &LA, &LR, &OA),
      logical(Y, C, V),
      shifter(Y, C, V),
      adder(Y, C, V) {
    BSEL = false;
    CISEL = false;
    CSEL = 0;
    OSEL = 0;
    LA = false;
    LR = false;
    OA = false;
}


void Alu::alu(Byte A, Byte B, Byte fs) {

    control.control(fs);

    OSEL = OSEL_adder;
    A = 127;
    B = 127;
    BSEL = false;
    CISEL = false;

    if (OSEL == OSEL_adder){

      Byte B_input = BSEL ? ~B : B;
      bool CI = CISEL ? 1 : 0;

      adder.add(A, B_input, CI);
    };
    if (OSEL == OSEL_logic){
  
      logical.logic(A, B, OA);
    };

    if (OSEL == OSEL_shifter){
      shifter.shift(A, B, LA, LR);
    };

    *Z = 
        !(*Y & (1 << 0)) &
        !(*Y & (1 << 1)) &
        !(*Y & (1 << 2)) &
        !(*Y & (1 << 3)) &
        !(*Y & (1 << 4)) &
        !(*Y & (1 << 5)) &
        !(*Y & (1 << 6)) &
        !(*Y & (1 << 7));
    
    *N = (*Y >> 7) & 1;
}


