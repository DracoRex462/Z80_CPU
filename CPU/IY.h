#ifndef Z80_CPU_IY_H
#define Z80_CPU_IY_H

#include <cstdint>

class IY
{
public:
    IY() : addr(0) {};
    void write(int8_t address) { addr = address; };
    int8_t read() { return addr; };

private:
    int8_t addr;
};

#endif