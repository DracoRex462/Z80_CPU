#include "ALU.h"
#include <cstdint>

//---------------------------------------
// operator
uint8_t ALU::add(uint8_t val, bool withCarry) {
    uint8_t cIn = (withCarry && (regs.F() & 0x01)) ? 1 : 0;
    uint16_t res = regs.A() + val + cIn;
    uint8_t h = ((regs.A() & 0x0F) + (val & 0x0F) + cIn > 0x0F) << 4;
    uint8_t v = (((regs.A() ^ res) & (val ^ res) & 0x80) >> 5);
    regs.F() = (res & 0x80) | ((uint8_t)res == 0 ? 0x40 : 0) | h | v | (res > 0xFF);
    return (uint8_t)res;
}

uint8_t ALU::sub(uint8_t val, bool withCarry) {
    uint8_t cIn = (withCarry && (regs.F() & 0x01)) ? 1 : 0;
    uint16_t res = regs.A() - val - cIn;
    uint8_t h = ((regs.A() & 0x0F) < (val & 0x0F) + cIn) << 4;
    uint8_t v = (((regs.A() ^ val) & (regs.A() ^ res) & 0x80) >> 5);
    regs.F() = (res & 0x80) | ((uint8_t)res == 0 ? 0x40 : 0) | h | v | 0x02 | (res > 0xFF);
    return (uint8_t)res;
}

uint8_t ALU::cp(uint8_t val) { 
    uint8_t oldA = regs.A(); 
    sub(val, false); 
    regs.A() = oldA;
    return oldA; 
}

//---------------------------------------
// local operator
uint8_t ALU::andOp(uint8_t val) {
    regs.A() &= val;
    regs.F() = (regs.A() & 0x80) | (regs.A() == 0 ? 0x40 : 0) | 0x10; 
    return regs.A();
}

uint8_t ALU::orOp(uint8_t val) {
    regs.A() |= val;
    regs.F() = (regs.A() & 0x80) | (regs.A() == 0 ? 0x40 : 0);
    return regs.A();
}

uint8_t ALU::xorOp(uint8_t val) {
    regs.A() ^= val;
    regs.F() = (regs.A() & 0x80) | (regs.A() == 0 ? 0x40 : 0);
    return regs.A();
}

//---------------------------------------
// 16Bit adder
uint16_t ALU::add16(uint16_t base, uint16_t offset) {
    uint32_t res = base + offset;
    uint8_t h = (((base & 0x0FFF) + (offset & 0x0FFF)) > 0x0FFF) << 4;
    regs.F() = (regs.F() & 0xC4) | h | (res > 0xFFFF); 
    return (uint16_t)res;
}

//---------------------------------------
uint8_t ALU::inc(uint8_t value) {
    uint8_t res = value + 1;
    uint8_t s = (res & 0x80); 
    uint8_t z = (res == 0) << 6;
    uint8_t h = ((value & 0x0F) == 0x0F) << 4;
    uint8_t v = (value == 0x7F) << 2;
    regs.F() = (regs.F() & 0x01) | s | z | h | v;
    return res;
}

uint8_t ALU::dec(uint8_t value) {
    uint8_t res = value - 1;
    uint8_t s = (res & 0x80);
    uint8_t z = (res == 0) << 6;
    uint8_t h = ((value & 0x0F) == 0x00) << 4;
    uint8_t v = (value == 0x80) << 2;
    uint8_t n = (1 << 1);
    regs.F() = (regs.F() & 0x01) | s | z | h | v | n;
    return res;
}
