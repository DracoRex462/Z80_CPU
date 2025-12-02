#ifndef ALU_H
#define ALU_H

#include <cstdint>

class ALU
{
public:
    ALU() {};
    void execute(unsigned int xField, unsigned int yField, uint16_t HL);

private:
    void loadA(unsigned int value);
    int controlYField(unsigned int yField);
    unsigned int executeADD(unsigned int yField, uint16_t HL);
    unsigned int executeSUP(unsigned int yField, uint16_t HL);
    unsigned int executeLD(unsigned int yField);
};

#endif