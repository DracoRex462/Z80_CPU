#ifndef CPU_Z80_H
#define CPU_Z80_H

#include <vector>
#include "CPU/ControlUnit.h"

class Z80 {
public:
    Z80(const std::vector<unsigned int>& InstructionRegister) : IR(InstructionRegister) {}
    void Run(std::vector<unsigned int> IR);

    void PrintRegister();
    void PrintPCCounter();

private:
    int ApproveVector();
    std::vector<unsigned int> IR;
};


#endif