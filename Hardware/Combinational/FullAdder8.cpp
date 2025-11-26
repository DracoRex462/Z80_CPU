#include "FullAdder8.h"
#include <vector>
#include <cstdint>

void FullAddr8::add(uint8_t input1, uint8_t input2)
{
    SVector.resize(8);
    CVector.resize(8);

    FullAdder adder;
    unsigned int carry = 0u;

    for (int i = 0; i < 8; ++i)
    {
        unsigned int bitA = (input1 >> i) & 1u;
        unsigned int bitB = (input2 >> i) & 1u;

        adder.add(carry, bitA, bitB);

        SVector[i] = adder.getSum();
        carry = adder.getCout();
        CVector[i] = carry;
    }
}

unsigned int FullAddr8::getSumADDR()
{
    unsigned int result = CVector.back();
    for (int i = SVector.size() - 1; i >= 0; --i) { result = (result << 1) | SVector[i]; }
    return result;
}
