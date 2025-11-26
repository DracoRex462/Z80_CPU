#ifndef FULLSUPTRACTOR8_H
#define FULLSUPTRACTOR8_H

#include <cstdint>
#include <vector>

class FullSuptractor8 {
public:
    FullSup8() {};
    void sub(uint8_t input1, uint8_t input2);
    unsigned int getSumSUP();

private:
    std::vector<uint8_t> SVector;
    std::vector<uint8_t> CVector;
};

#endif
