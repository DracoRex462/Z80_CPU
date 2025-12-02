#include "ALU.h"
#include "../Memory/Register.h"
#include "../Memory/Memory.h"
#include "../Hardware/Logic/AND.h"

void ALU::execute(unsigned int xField, unsigned int yField)
{
    switch(xField)
    {
        case 0x9: //SUP
            break;
        case 0x8: //ADD
            break;
        case 0x7: //LD
            break;
    }

}

unsigned int ALU::executeADD(unsigned int yField)
{
    Register R;
    AND And;
    registerA = R.read(0);
    return And.CalcAND(registerA, yField);
}



unsigned int ALU::executeSUP(unsigned int yField) {}
unsigned int ALU::executeLD(unsigned int yField) {}