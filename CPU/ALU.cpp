#include "ALU.h"
#include "../Memory/Register.h"
#include "../Memory/Memory.h"

#include "../Hardware/Combinational/FullAdder8.h"
#include "../Hardware/Combinational/FullSubtractor8.h"

void ALU::execute(unsigned int xField, unsigned int yField)
{
    switch(xField)
    {
        case 0x9: //SUP
            loadA(executeSUP(yField));
        case 0x8: //ADD
            loadA(executeADD(yField));
        case 0x7: //LD
            break;
    }
}
void ALU::loadA(unsigned int value)
{
    Register R;
    R.write(0, value);
};

unsigned int ALU::executeADD(unsigned int yField)
{
    Register R;
    FullAdder8 Adder;
    Adder.FullSup8(R.read(0), yField);
    return Adder.getSumADDR();
}

unsigned int ALU::executeSUP(unsigned int yField)
{
    Register R;
    FullSuptractor8 Subtractor;
    Subtractor.FullSup8(R.read(0), yField);
    return Subtractor.getSumSUP();
}

unsigned int ALU::executeLD(unsigned int yField) {}
