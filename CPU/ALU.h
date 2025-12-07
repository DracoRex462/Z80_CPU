#ifndef ALU_H
#define ALU_H

#include <cstdint>

class ALU
{
public:
    ALU() {};
    void execute(unsigned int xField, unsigned int yField, uint16_t HL);

private:
    uint16_t HL;
    int xField;
    int yField;
    int zField;

    void createFields(uint8_t command);

    void registerLD(unsigned int value);
    int controlYField(unsigned int yField);
    unsigned int executeADD(unsigned int yField, uint16_t HL);
    unsigned int executeSUP(unsigned int yField, uint16_t HL);
    unsigned int executeLD(unsigned int yField, uint16_t HL);
    unsigned int loadHelper(uint8_t command);
};

#endif