#include "CPU.h"
#include <iostream>



void CPU::step(uint16_t PC) {
    if (halted) return;
    ir = fetch(PC);   
    decode(ir);     
    execute();
}

uint8_t CPU::fetch(uint16_t IR) {
    uint8_t opcode = mem.read(reg.PC()); 
    reg.PC()++;
    return opcode;
}

void CPU::decode(uint8_t opcode) {    
    unsigned int x = (opcode & 0xC0) >> 6;
    unsigned int y = (opcode & 0x38) >> 3;
    unsigned int z = (opcode & 0x07);
}


void CPU::execute() {
    uint8_t opcode = mem.read(reg.PC());
    reg.PC()++; 

    switch (opcode) {
        case 0x00:
            break; 
        case 0x76: // Stop
            halted = true;
            break;
        case 0x78: // LD 
            reg.A() = reg.B();
            break;
        case 0x3E:
            reg.A() = mem.read(reg.PC());
            reg.PC()++; 
            break;
        case 0x80: // ADD
            alu.add(reg.A(), reg.B());
            break;
        case 0x81:
            alu.add(reg.A(), reg.C());
            break;
        case 0xC3: // JP 
        {
            uint8_t low = mem.read(reg.PC()++);
            uint8_t high = mem.read(reg.PC()++);
            uint16_t target = (high << 8) | low;
            reg.PC() = target;
            break;
        }

        default:
            break;
    }
}

void CPU::incrementPC() {
    reg.PC()++; 
}