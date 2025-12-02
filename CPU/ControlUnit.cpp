#include "ControlUnit.h"
#include "CPU/ALU.h"

void ControlUnit::decode_and_execute()
{
    ALU alu;

    for (int i = 0; i < IR.size(); i++)
    {
        unsigned int yField = (IR[i] & 0b11110000) >> 4;
        unsigned int xField = (IR[i] & 0b00001111);
        alu.execute(xField, yField);
    }
}
