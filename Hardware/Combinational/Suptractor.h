#ifndef SUBTRACTOR_H
#define SUBTRACTOR_H

#include <vector>

class Subtractor {
public:
    Subtractor() : OutputC(0), OutputS(0) {};
    void sub(unsigned int C, unsigned int input_1, unsigned int input_2);

    unsigned int getC() const;
    unsigned int getS() const;

private:
    unsigned int OutputS;
    unsigned int OutputC;
};

#endif
