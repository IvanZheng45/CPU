#ifndef DECODER_H
#define DECODER_H

#include <cstdint>
#include "symbols.h"

class Decoder {
public:
    // Constructor
    Decoder(Byte* dr, Byte* sa, Byte* sb, Byte* imm, bool* mb, Byte* fs, bool* md, bool* ld, bool* mw, bool* hlt, Byte* bs, Byte* off);

    // Decode method
    void decode(Word INST);

private:
    Byte* dr;
    Byte* sa;
    Byte* sb;
    Byte* imm;
    bool* mb;
    Byte* fs;
    bool* md;
    bool* ld;
    bool* mw;
    bool* hlt;
    Byte* bs;
    Byte* off;

};

#endif // DECODER_H
