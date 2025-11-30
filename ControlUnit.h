#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include <vector>

class ControlUnit {
public:
    ControlUnit(const std::vector<unsigned int>& InstructionRegister) : IR(InstructionRegister) {}
    void decode_and_execute();

private:
    std::vector<unsigned int> IR;
};

#endif