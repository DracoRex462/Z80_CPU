#ifndef ALU_H
#define ALU_H

#include <cstdint>

#include "Temp.h"
#include "../Memory/Register.h"
#include "../Memory/Memory.h"

class ALU
{
public:
    ALU() {};
    void execute(unsigned int op, unsigned int yField, unsigned int zField, uint16_t HL);

    Register* reg;
    Memory* mem;
    Temp* temp;

private:
    uint8_t  executeADD(unsigned int zField, uint16_t HL);
    uint8_t  executeSUP(unsigned int zField, uint16_t HL);
    void     executeLD(int yField, int zField, uint16_t HL);
};

#endif