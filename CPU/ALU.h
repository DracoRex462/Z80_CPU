#ifndef ALU_H
#define ALU_H

#include <cstdint>
#include "Register/Register.h"

class ALU {
    public:
        ALU();
        ~ALU() = default;

        // operator
        uint8_t add(uint8_t value, bool withCarry = false);
        uint8_t sub(uint8_t value, bool withCarry = false);
        uint8_t cp(uint8_t value);
        
        // logical operators
        uint8_t andOp(uint8_t value);
        uint8_t orOp(uint8_t value);
        uint8_t xorOp(uint8_t value);

        // increase/decrease value at 1
        uint8_t inc(uint8_t value);
        uint8_t dec(uint8_t value);

        // 16Bit adder
        uint16_t add16(uint16_t base, uint16_t offset);

    private:
        Registers& regs;
        void updateFlags(int result, uint8_t valA, uint8_t valB, bool isSub, bool is16Bit = false);
};

#endif