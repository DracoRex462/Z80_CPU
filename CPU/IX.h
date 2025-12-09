#ifndef Z80_CPU_IX_H
#define Z80_CPU_IX_H

#include <cstdint>

class IX
{
public:
    IX() : addr(0) {};
    void write(int16_t address) { addr = address; };
    int16_t read() { return addr; };

private:
    int16_t addr;
};

#endif