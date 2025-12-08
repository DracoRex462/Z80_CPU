#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include <cstdint>
#include <vector>

class ControlUnit {
public:
    ControlUnit(const std::vector<uint8_t>& InstructionRegister) : IR(InstructionRegister) {}
    void decode_and_execute();

private:
    std::vector<uint8_t> IR;
    uint16_t createHL(uint8_t Ci1, uint8_t Ci2);
    void decodeOpcode(uint8_t command);


    int xField;
    int yField;
    int zField;
    uint16_t HL;
};

#endif