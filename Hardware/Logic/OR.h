#ifndef OR_H
#define OR_H

#include "Gate.h"

class OR : public Gate {
    public:
        OR() : Gate(0) {};
        unsigned int CalcOR(unsigned int Input1, unsigned int Input2) { return Input1 | Input2; }
};

#endif