#ifndef MEMORY_H
#define MEMORY_H

#include <cstdint>

class Memory {
    public:
        void write(uint16_t addr, uint8_t value) { data[addr] = value; }
        uint8_t read(uint16_t addr) const { return data[addr]; }

    private:
        uint8_t data[65536] = {};
};

#endif
