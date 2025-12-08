#ifndef MEMORY_H
#define MEMORY_H

#include <vector>

class Memory {
    public:
        void write(uint8_t addr, uint8_t value) { data[addr].push_back(value); };
        std::vector<uint8_t>& read(uint8_t addr) { return data[addr]; }

    private:
        std::vector<uint8_t> data[64000];
};

#endif