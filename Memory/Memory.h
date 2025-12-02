#ifndef MEMORY_H
#define MEMORY_H

#include <vector>

class Memory {
    public:
        void write(unsigned int addr, unsigned int value) { data[addr].push_back(value); };
        std::vector<unsigned int>& read(unsigned int addr) { return data[addr]; }

    private:
        std::vector<unsigned int> data[64000];
};

#endif