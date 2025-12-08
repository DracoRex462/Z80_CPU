#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include <cstdint>
#include <vector>

#include "PC.h"
#include "ALU.h"
#include "Temp.h"
#include "../Memory/Register.h"

class ControlUnit {
public:
    ControlUnit(const std::vector<uint8_t>& InstructionRegister) : IR(InstructionRegister), op(0), xField(0), yField(0), zField(0), HL(0) {};
    void decode_and_execute();

    PC* counter;
    Register* reg;
    Temp* temp;
    ALU alu;

private:
    std::vector<uint8_t> IR;
    void decodeOpcode(uint8_t command);
    void executeAluToA();

    unsigned int op;
    unsigned int xField;
    unsigned int yField;
    unsigned int zField;
    uint16_t HL;
};

#endif