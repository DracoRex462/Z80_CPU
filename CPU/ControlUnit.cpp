#include "ControlUnit.h"


#include <cstdint>

void ControlUnit::decode_and_execute()
{
    for (int i = 0; i < IR.size(); i++)
    {
        decodeOpcode(IR[counter->getCounter()]);
        alu.execute(op, yField, zField, HL);
        if (op != 1) { executeLDReg(); }
        counter->setCounter(counter->getCounter() + 1);
    }
}

void ControlUnit::decodeOpcode(uint8_t command, uint8_t H, uint8_t L)
{
    xField = (command >> 6) & 0x03;
    yField = (command >> 3) & 0x07;
    zField = command & 0x07;
    HL = static_cast<uint16_t>(H) << 8 | L;

    switch (xField)
    {
        case 0x4 ... 0x7:   op = 1;
        case 0x7:           op = 2;
        case 0x8:           op = 3;
    }

}

void ControlUnit::executeAluToA()
{
    reg->write(0, temp->getValue());
}