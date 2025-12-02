#ifndef FULLADDER_H
#define FULLADDER_H

#include <cstdint>
#include <vector>

class FullAdder8 {
public:
    FullAdder8() {};
    void add(uint8_t input1, uint8_t input2);
    unsigned int getSumADDR();

private:
    std::vector<unsigned int> SVector[8];
    std::vector<unsigned int> CVector[8];
};

#endif