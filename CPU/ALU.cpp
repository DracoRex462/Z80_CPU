#include "ALU.h"
#include "Temp.h"
#include "../Memory/Register.h"
#include "../Memory/Memory.h"

#include "../Hardware/Combinational/FullAdder8.h"
#include "../Hardware/Combinational/FullSubtractor8.h"


void ALU::execute(unsigned int xField, unsigned int yField, uint16_t HL)
{
    switch(xField)
    {
        case 0x4 ... 0x7:           executeLD(yField, HL); break;                  //LD
        case 0x8:                   registerLD(executeADD(yField, HL), 0);  break; //ADD
        case 0x9:                   registerLD(executeSUP(yField, HL), 0);  break; //SUP

    }
}

int ALU::controlYField(unsigned int yField)
{
    return (yField <= 5) ? 0 : (yField == 6 ? 1 : 2);
}

void ALU::registerLD(unsigned int value, int reg)
{
    Register R;
    R.write(reg, value);
};

unsigned int ALU::executeADD(unsigned int yField, uint16_t HL)
{
    Register R;
    FullAdder8 Adder;

    switch(controlYField(yField))
    {
        case 0: Adder.add(R.read(0), yField); break;
        case 1: Adder.add(R.read(0), HL); break;
        case 2: Adder.add(R.read(0), R.read(0)); break;
    }
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

unsigned int ALU::executeLD(uint8_t command, uint16_t HL)
{
    switch(command)
    {
        case 0x40 ... 0x47: loadHelper();
    }
}

unsigned int ALU::loadHelper(uint8_t command)
{
    createHL(command);
    if ()

}
