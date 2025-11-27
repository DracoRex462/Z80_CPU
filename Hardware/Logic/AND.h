#ifndef AND_H
#define AND_H

#include "Gate.h"

class AND : public Gate {
    public:
        AND() : Gate(0) {};
        unsigned int CalcAND(unsigned int Input1, unsigned int Input2) { return Input1 & Input2; }
};

#endif