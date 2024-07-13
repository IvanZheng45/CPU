#ifndef DECODER_H
#define DECODER_H
#include <cstdint>
#include "symbols.h"
class Decoder {
public:
    // Constructor
    Decoder(uint16_t inst);

    // Decode method
    void decode();

    // Getter methods for output signals
    Byte getDR() const;
    Byte getSA() const;
    Byte getSB() const;
    Byte getIMM() const;
    bool getMB() const;
    Byte getFS() const;
    bool getMD() const;
    bool getLD() const;
    bool getMW() const;
    bool getHLT() const;
    Byte getBS() const;
    Byte getOFF() const;

private:
    // Input
    Word INST;

    // Outputs
    Byte DR;
    Byte SA;
    Byte SB;
    Byte IMM;
    bool MB;
    Byte FS;
    bool MD;
    bool LD;
    bool MW;
    bool HLT;
    Byte BS;
    Byte OFF;
};

#endif // DECODER_H
