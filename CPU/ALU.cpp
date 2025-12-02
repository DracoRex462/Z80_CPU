#include "ALU.h"
#include "../Memory/Register.h"
#include "../Memory/Memory.h"

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


void ALU::executeADD(unsigned int yField) {}
void ALU::executeSUP(unsigned int yField) {}
void ALU::executeLD(unsigned int yField) {}