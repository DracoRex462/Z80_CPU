#ifndef XOR_H
#define XOR_H

#include "Gate.h"

class XOR : public Gate {
    public:
        XOR() : Gate(0) {};
        unsigned int CalcXOR(unsigned int Input1, unsigned int Input2) { return Input1 ^ Input2; }
};

#endif