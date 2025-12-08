#ifndef MEMORY_H
#define MEMORY_H

#include <vector>

class Memory {
    public:
        void write(uint16_t addr, uint8_t value) { data[addr].push_back(value); };
        std::vector<uint8_t>& read(uint16_t addr) { return data[addr]; }

    private:
        std::vector<uint8_t> data[64000];
};

#endif