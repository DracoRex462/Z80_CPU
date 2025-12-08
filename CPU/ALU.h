#ifndef ALU_H
#define ALU_H

#include <cstdint>

class ALU
{
public:
    ALU() {};
    void execute(int op, uint16_t HL);

private:
    void registerLD(unsigned int value);
    int controlYField(unsigned int yField);
    unsigned int executeADD(unsigned int yField, uint16_t HL);
    unsigned int executeSUP(unsigned int yField, uint16_t HL);
    unsigned int executeLD(unsigned int yField, uint16_t HL);
    unsigned int loadHelper(uint8_t command);
};

#endif