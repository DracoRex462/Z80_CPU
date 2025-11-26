#include "FullAdder8.h"
#include <vector>

void FullAddr8::add(unsigned int input16_1, unsigned int input16_2)
{
    SVector.resize(8);
    CVector.resize(8);

    FullAdder adder;
    unsigned int carry = 0u;

    for (int i = 0; i < 8; ++i)
    {
        unsigned int bitA = (input8_1 >> i) & 1u;
        unsigned int bitB = (input8_2 >> i) & 1u;

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
