#ifndef CPU_Z80_H
#define CPU_Z80_H

#include <vector>
#include "CPU/ControlUnit.h"

class Z80 {
public:
    Z80(std::vector<uint8_t>& InstructionRegister) : IR(InstructionRegister) {}
    void Run();
    void PrintRegister() {}
    void PrintPCCounter() {}

private:
    int ApproveVector();
    std::vector<uint8_t> IR;
};


#endif