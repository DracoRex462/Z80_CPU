#include "FullSuptractor8.h"
#include "Subtractor.h" 

void FullSuptractor8::sub(uint8_t input1, uint8_t input2)
{
    Subtractor Sub;
    unsigned int borrow = 0;

    for (int i = 0; i < 8; ++i)
    {
        unsigned int bitA = (input1 >> i) & 1u;
        unsigned int bitB = (input2 >> i) & 1u;

        Sub.sub(borrow, bitA, bitB);

        SVector[i] = Sub.getS();
        borrow = Sub.getC();
        CVector[i] = borrow;
    }
}

unsigned int FullSuptractor8::getSumSUP()
{
    unsigned int result = 0;
    for (int i = 0; i < SVector.size(); ++i)
    {
        result |= (SVector[i] << i);
    }
    return result;
}
