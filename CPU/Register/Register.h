#ifndef REGISTERBANK_H
#define REGISTERBANK_H

#include <cstdint>

union Register {
    uint16_t word; 
    struct {
        uint8_t lo; 
        uint8_t hi; 
    } byte;   
};

class Registers {
public:
    Register AF; 
    Register BC;
    Register DE;
    Register HL;

    Register AF_shadow;
    Register BC_shadow;
    Register DE_shadow;
    Register HL_shadow;
    
    Register IX;
    Register IY;

    uint16_t SP;
    uint16_t PC;
    uint8_t  I; 
    uint8_t  R; 

    Register TEMP;

    Registers() { reset(); }

    void reset() {
        AF.word = BC.word = DE.word = HL.word = 0;
        AF_shadow.word = BC_shadow.word = DE_shadow.word = HL_shadow.word = 0;
        IX.word = IY.word = 0;
        
        I = 0;
        R = 0;
        PC = 0x0000;    
        SP = 0xFFFF;    
    }

    // Getter and Satter for Register
    uint8_t& A() { return AF.byte.hi; }
    uint8_t& F() { return AF.byte.lo; }
    uint8_t& B() { return BC.byte.hi; }
    uint8_t& C() { return BC.byte.lo; }
    uint8_t& D() { return DE.byte.hi; }
    uint8_t& E() { return DE.byte.lo; }
    uint8_t& H() { return HL.byte.hi; }
    uint8_t& L() { return HL.byte.lo; }

    uint16_t& PC() { return PC; }
    uint16_t& SP() { return SP; }
    uint8_t& I() { return I; }
    uint8_t& R() { return R; }

    uint8_t& TEMP() { return TEMP.byte.hi; }
    uint8_t& TEMP() { return TEMP.byte.lo; }
};

#endif