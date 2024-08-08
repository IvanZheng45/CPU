#ifndef ALU_H
#define ALU_H

#include <cstdint>
#include "control.h"
#include "adder.h"
#include "logical.h"
#include "symbols.h"
#include "shifter.h"


class Alu {
public:
    // Constructor
    Alu(Byte* Y, bool* C, bool* V, bool* N, bool* Z);

    // Method
    void alu(Byte A, Byte B, Byte fs);

private:
    // Member variables
    Byte* Y;
    bool* C;
    bool* V;
    bool* N;
    bool* Z;
    
    // Control and Adder objects
    Control control;
    Adder adder;
    Logical logical;
    Shifter shifter;

    // Control parameters
    bool BSEL;
    bool CISEL;
    Byte CSEL;
    Byte OSEL;
    bool LA;
    bool LR;
    bool OA;

    Byte OSEL_adder = 0;
    Byte OSEL_shifter = 1;
    Byte OSEL_logic = 2;

    Byte CSEL_adder = 0;
    Byte CSEL_logic = 1;
    Byte CSEL_shifter = 2;
};

#endif // ALU_H
