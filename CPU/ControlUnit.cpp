#include "ControlUnit.h"
#include "CPU/ALU.h"
#include "PC.h"
#include "../Hardware/Logic/OR.h"

#include <cstdint>

void ControlUnit::decode_and_execute()
{
    ALU alu;

    for (int i = 0; i < IR.size(); i++)
    {
        unsigned int xField = (IR[i] & 0b00001111);
        unsigned int yField = (IR[i] & 0b11110000) >> 4;
        if (yField == 6) { HL = createHL((IR[i + 1] & 0b11110000) >> 4, IR[i + 1] & 0b00001111); }
        else { HL = 0x0000; }

        alu.execute(xField, yField, HL);
    }
}

uint16_t ControlUnit::createHL(uint8_t Ci1, uint8_t Ci2)
{
    PC Counter;
    OR Or;
    Counter.setCounter(Counter.getCounter() + 2);
    return Ci1 << 8 | Ci2;
}


/*
void ALU::createFields(uint8_t command)
{
    xField = (command >> 6) & 0x03;
    yField = (command >> 3) & 0x07;
    zField = command & 0x07;
}
*/
