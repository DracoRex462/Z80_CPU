#include "FullAdder8.h"
#include "FullAdder.h"

#include <vector>
#include <cstdint>

void FullAdder8::add(uint8_t input1, uint8_t input2)
{
    FullAdder adder;
    unsigned int carry = 0u;

    for (int i = 0; i < 8; ++i)
    {
        unsigned int bitA = (input1 >> i) & 1u;
        unsigned int bitB = (input2 >> i) & 1u;

        adder.add(carry, bitA, bitB);

        SVector[i].push_back(adder.getSum());
        carry = adder.getCout();
        CVector[i].push_back(carry);
    }
}

unsigned int FullAdder8::getSumADDR()
{
    unsigned int result = 0;

    for (int i = 7; i >= 0; --i)
    {
        if (!SVector[i].empty())
            result = (result << 1) | SVector[i].back();
    }
    return result;
}






