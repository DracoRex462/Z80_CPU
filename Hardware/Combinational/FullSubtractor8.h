#ifndef FULLSUPTRACTOR8_H
#define FULLSUPTRACTOR8_H

#include <cstdint>
#include <vector>

class FullSuptractor8 {
public:
    FullSuptractor8() {};
    void sub(uint8_t input1, uint8_t input2);
    unsigned int getSumSUP();

private:
    std::vector<unsigned int> SVector [8];
    std::vector<unsigned int> CVector [8];
};

#endif
