#include "ALU.h"
#include "Temp.h"
#include "../Memory/Register.h"
#include "../Memory/Memory.h"

#include "../Hardware/Combinational/FullAdder8.h"
#include "../Hardware/Combinational/FullSubtractor8.h"

// ----------------------------------------------------------------------------------

void ALU::execute(uint8_t command , uint16_t HL)
{
    createFields(command);
    switch(xField)
    {
        case 0x4 ... 0x7:  executeLD(yField, HL); break;                  //LD
        case 0x8:          registerLD(executeADD(yField, HL), 0);  break; //ADD
        case 0x9:          registerLD(executeSUP(yField, HL), 0);  break; //SUP
    }
}

// ----------------------------------------------------------------------------------
/*
int ALU::controlYField(unsigned int yField)
{
    return (yField <= 5) ? 0 : (yField == 6 ? 1 : 2);
}

void ALU::registerLD(unsigned int value, int reg)
{
    Register R;
    R.write(reg, value);
};
*/


unsigned int ALU::executeADD(unsigned int yField, uint16_t HL)
{
    Register reg;
    Memory mem;
    FullAdder8 Adder;

    if (zField == 6)    { Adder.add(reg.read(0), mem.read(HL)); }
    else                { Adder.add(reg.read(0), reg.read(zField)); }
    return Adder.getSumADDR();
}

unsigned int ALU::executeSUP(unsigned int yField, uint16_t HL)
{
    Register R;
    FullSubtractor8 Subtractor;

    switch(controlYField(yField))
    {
        case 0: Subtractor.sub(R.read(0), yField); break;
        case 1: Subtractor.sub(R.read(0), HL); break;
        case 2: Subtractor.sub(R.read(0), R.read(0)); break;
    }
    return Subtractor.getSumSUP();
}


// ----------------------------------------------------------------------------------------------------

void ALU::createFields(uint8_t command)
{
    xField = (command >> 6) & 0x03;
    yField = (command >> 3) & 0x07;
    zField = command & 0x07;
}

void ALU::executeLD(uint8_t command, uint16_t HL)
{
    Register reg;
    Memory mem;

    if (yField != 6 && zField != 6)         { reg.write(reg.read(zField), reg.read(yField)); }  // R <- R
    else if (yField != 6 && zField == 6)    { reg.write(reg.read(zField), HL); }                // R <- HL
    else if (yField == 6 && zField != 6)    { mem.write(HL, reg.read(yField));}                 // HL <- R
    else if (yField == 6 && zField == 6)    { mem.write(HL, HL); }                              // HL <- HL
}