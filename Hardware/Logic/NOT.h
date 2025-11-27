#ifndef NOT_H
#define NOT_H

#include "Gate.h"

class NOT : public Gate {
    public:
        NOT() : Gate(0) {};
        unsigned int CalcNOT(unsigned int Input1) { return !Input1; }
};

#endif