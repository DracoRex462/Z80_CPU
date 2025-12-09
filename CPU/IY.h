#ifndef Z80_CPU_IY_H
#define Z80_CPU_IY_H

#include <cstdint>

class IY
{
public:
    IY() : addr(0) {};
    void write(int16_t address) { addr = address; };
    int16_t read() { return addr; };

private:
    int16_t addr;
};

#endif