#ifndef ALU_H
#define ALU_H

#include <cstdint>

class ALU
{
public:
    ALU() {};
    void execute(unsigned int op, unsigned int yField, unsigned int zField, uint16_t HL);

private:
    uint8_t  executeADD(unsigned int zField, uint16_t HL);
    uint8_t  executeSUP(unsigned int zField, uint16_t HL);
    unsigned int executeLD(int yField, int zField, uint16_t HL);
};

#endif