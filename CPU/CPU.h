#ifndef CPU_H
#define CPU_H

#include "ALU.h"
#include "Register/Register.h"
#include "../Memory/Memory.h"
#include <cstdint>

class CPU {
public:
    CPU() : ir(0), halted(false) {};
    ~CPU() = default;
    
    Registers reg;
    Memory mem;
    ALU alu;
    
    void step(uint16_t PC);
    bool isHalted() const { return halted; }

private:
    uint8_t ir;    
    bool halted;

    void incrementPC();

    uint8_t fetch(uint16_t IR); 
    void    decode(uint8_t opcode);
    void    execute();
};

#endif