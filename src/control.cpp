#include "control.h"
#include "symbols.h"

Control::Control(bool* BSEL, bool* CISEL, Byte* CSEL, Byte* OSEL, bool* LA, bool* LR, bool* OA)
    : BSEL(BSEL), CISEL(CISEL), CSEL(CSEL), OSEL(OSEL), LA(LA), LR(LR), OA(OA) {}

void Control::control(Byte FS) {

    switch (FS) {

    case FS_ADD:
        *BSEL = BSEL_B;
        *CISEL = CISEL_add;
        *CSEL = CSEL_adder;
        *OSEL = OSEL_adder;
        *LA = 0;
        *LR = 0;
        *OA = 0;
        break;
    case FS_SUB:
        *BSEL = BSEL_BN;
        *CISEL = CISEL_sub;
        *CSEL = CSEL_adder;
        *OSEL = OSEL_adder;
        *LA = 0;
        *LR = 0;
        *OA = 0;
        break;
    case FS_SRL:
        *BSEL = 0;
        *CISEL = 0;
        *CSEL = CSEL_shifter;
        *OSEL = OSEL_shifter;
        *LA = LA_logical;
        *LR = LR_right;
        *OA = 0;
        break;
    case FS_SRA:
        *BSEL = 0;
        *CISEL = 0;
        *CSEL = CSEL_shifter;
        *OSEL = OSEL_shifter;
        *LA = LA_arithmetic;
        *LR = LR_right;
        *OA = 0;
        break;
    case FS_SLL:
        *BSEL = 0;
        *CISEL = 0;
        *CSEL = CSEL_shifter;
        *OSEL = OSEL_shifter;
        *LA = LA_arithmetic;
        *LR = LR_left;
        *OA = 0;
        break;
    case FS_AND:
        *BSEL = 0;
        *CISEL = 0;
        *CSEL = CSEL_logic;
        *OSEL = OSEL_logic;
        *LA = 0;
        *LR = 0;
        *OA = OA_and;
        break;
    case FS_OR:
        *BSEL = 0;
        *CISEL = 0;
        *CSEL = CSEL_logic;
        *OSEL = OSEL_logic;
        *LA = 0;
        *LR = 0;
        *OA = OA_or;
        break;
    default:
        *BSEL = 0;
        *CISEL = 0;
        *CSEL = 0;
        *OSEL = 0;
        *LA = 0;
        *LR = 0;
        *OA = 0;
    }
}
