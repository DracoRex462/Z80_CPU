#ifndef FULLADDER_H
#define FULLADDER_H

#include <vector>

class FullAdder8 {
public:
    FullAdder8() {};
    void add(unsigned int input8_1, unsigned int input8_2);
    unsigned int getSumADDR();

private:
    std::vector<unsigned int> SVector;
    std::vector<unsigned int> CVector;
};

#endif