#ifndef REGISTER_H
#define REGISTER_H

#include <cstdint>
#include <vector>

class Register
{
public:
    void write(unsigned int addr, unsigned int value) { R[addr].push_back(value); };
    uint8_t read(unsigned int addr) { return R[addr][0]; }

private:
    std::vector<uint8_t> R[7];
};


#endif