#ifndef CONTROL_H
#define CONTROL_H

#include <cstdint>
#include "symbols.h"

class Control {
public:
    // Constructor
    Control(bool* BSEL, bool* CISEL, Byte* CSEL, Byte* OSEL, bool* LA, bool* LR, bool* OA);

    // Control method
    void control(Byte FS);

private:
    bool* BSEL;
    bool* CISEL;
    Byte* CSEL;
    Byte* OSEL;
    bool* LA;
    bool* LR;
    bool* OA;

    // Constants (consider using static for class-level constants)
    static const Byte FS_ADD = 0x0;
    static const Byte FS_SUB = 0x1;
    static const Byte FS_SRA = 0x2;
    static const Byte FS_SRL = 0x3;
    static const Byte FS_SLL = 0x4;
    static const Byte FS_AND = 0x5;
    static const Byte FS_OR  = 0x6;

    static const bool BSEL_B = false;
    static const bool BSEL_BN = true;

    static const bool CISEL_add = false;
    static const bool CISEL_sub = true;

    static const Byte CSEL_adder = 0x0;
    static const Byte CSEL_logic = 0x1;
    static const Byte CSEL_shifter = 0x2;

    static const Byte OSEL_adder = 0x0;
    static const Byte OSEL_shifter = 0x1;
    static const Byte OSEL_logic = 0x2;

    static const bool LA_logical = false;
    static const bool LA_arithmetic = true;

    static const bool LR_left = false;
    static const bool LR_right = true;

    static const bool OA_or = false;
    static const bool OA_and = true;
};

#endif // CONTROL_H
