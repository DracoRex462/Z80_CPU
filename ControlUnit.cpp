#include "ControlUnit.h"
#include "CPU/ALU.h"

void ControlUnit::decode_and_execute()
{
    ALU alu;

    for (i = 0; i < IR.size(), i++)
    {
        unsigned int y-Field = (IR[i] & 0b11110000) >> 4
        unsigned int x-Field = (IR[i] & 0b00001111)
        alu.execute(x-Field, y-Field);
    }
}
