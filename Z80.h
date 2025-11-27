#ifndef Z80___CPU_Z80_H
#define Z80___CPU_Z80_H

#include <vector>

class Z80 {
public:
    Z80(std::vector<unsigned int>& InstructionRegister) : IR(InstructionRegister) {}
    void Run(std::vector<unsigned int> IR);

private:
    std::vector<unsigned int> IR;
};


#endif