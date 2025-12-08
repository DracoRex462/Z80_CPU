#include "ALU.h"

#include "../Hardware/Combinational/FullAdder8.h"
#include "../Hardware/Combinational/FullSubtractor8.h"

void ALU::execute(unsigned int op, unsigned int yField, unsigned int zField, uint16_t HL)
{
    switch(op)
    {
        case 1:          executeLD(yField, zField, HL);     break;      // LD
        case 2:          executeADD(zField);                break;      // ADD
        case 3:          executeSUP(zField);                break;      // SUP
    }
}

uint8_t ALU::executeADD(unsigned int zField)
{
    FullAdder8 Adder;
    Adder.add(reg->read(0), reg->read(zField));
    temp.setValue(Adder.getSumADDR());
    return Adder.getSumADDR();
}

uint8_t ALU::executeSUP(unsigned int zField, uint16_t HL)
{
    FullSubtractor8 Sub;
    Sub.sub(reg->read(0), reg->read(zField));
    temp.setValue(Sub.getSumSUB());
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