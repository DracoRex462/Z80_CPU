#include "ALU.h"
#include "../Memory/Register.h"
#include "../Memory/Memory.h"

#include "../Hardware/Combinational/FullAdder8.h"
#include "../Hardware/Combinational/FullSubtractor8.h"

// ----------------------------------------------------------------------------------

void ALU::execute(unsigned int op, unsigned int yField, unsigned int zField, uint16_t HL)
{
    switch(op)
    {
        case 1:          executeLD(yField, HL);     break;      // LD
        case 2:          executeADD(yField, HL);    break;      // ADD
        case 3:          executeSUP(yField, HL);    break;      // SUP
    }
}
uint8_t ALU::executeADD(unsigned int zField, uint16_t HL)
{
    Register reg;
    Memory mem;
    FullAdder8 Adder;

    if (zField == 6)    { Adder.add(reg.read(0), mem.read(HL)); }
    else                { Adder.add(reg.read(0), reg.read(zField)); }
    return Adder.getSumADDR();
}

uint8_t ALU::executeSUP(unsigned int zField, uint16_t HL)
{
    Register reg;
    Memory mem;
    FullSubtractor8 Sub;

    if (zField == 6)    { Sub.sub(reg.read(0), mem.read(HL)); }
    else                { Sub.sub(reg.read(0), reg.read(zField)); }
    return Sub.getSumSUP();
}

void ALU::executeLD(int yField, int zField, uint16_t HL)
{
    Register reg;
    Memory mem;

    if (yField != 6 && zField != 6)         { reg.write(reg.read(zField), reg.read(yField)); }  // R <- R
    else if (yField != 6 && zField == 6)    { reg.write(reg.read(zField), HL); }                // R <- HL
    else if (yField == 6 && zField != 6)    { mem.write(HL, reg.read(yField));}                      // HL <- R
    else if (yField == 6 && zField == 6)    { mem.write(HL, HL); }                                        // HL <- HL
}