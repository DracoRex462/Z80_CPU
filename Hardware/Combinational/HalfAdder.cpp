#include "HalfAdder.h"
#include "../Logic/XOR.h"
#include "../Logic/AND.h"

void HalfAddr::add(unsigned int Input1, unsigned int Input2)
{
    XOR xorGate;
    AND andGate;
    sum = xorGate.CalcXOR(Input1, Input2);
    carry = andGate.CalcAND(Input1, Input2);
}

unsigned int HalfAddr::getOutputSUM() { return sum; }
unsigned int HalfAddr::getOutputCARRY() { return carry; }
