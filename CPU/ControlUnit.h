#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include <cstdint>
#include <vector>

class ControlUnit {
public:
    ControlUnit(const std::vector<unsigned int>& InstructionRegister) : IR(InstructionRegister) {}
    void decode_and_execute();

private:
    uint16_t createHL(uint8_t Ci1, uint8_t Ci2);
    std::vector<unsigned int> IR;
    uint16_t HL;
};

#endif