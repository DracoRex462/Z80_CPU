#include "FullSubtractor8.h"
#include "FullSubtractor.h"

void FullSubtractor8::sub(uint8_t input1, uint8_t input2)
{
    FullSubtractor Sub;
    unsigned int borrow = 0;

    for (int i = 0; i < 8; ++i)
    {
        unsigned int bitA = (input1 >> i) & 1u;
        unsigned int bitB = (input2 >> i) & 1u;

        Sub.sub(borrow, bitA, bitB);

        SVector[i].push_back(Sub.getS());
        borrow = Sub.getC();
        CVector[i].push_back(borrow);
    }
}

unsigned int FullSubtractor8::getSumSUP()
{
    unsigned int result = 0;

    for (int i = 0; i < 8; ++i)
    {
        if (!SVector[i].empty())
            result |= (SVector[i].back() << i);
    }
    return result;
}

