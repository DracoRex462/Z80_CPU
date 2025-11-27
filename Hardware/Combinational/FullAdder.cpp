#include "HalfAdder.h"
#include "FullAdder.h"
#include "../Logic/XOR.h"

void FullAdder::add(unsigned int Cin, unsigned int A, unsigned int B)
{
    HalfAdder Add;
    XOR xorGate;

    Add.add(A, B);
    unsigned int Cout1 = Add.getOutputCARRY();
    unsigned int Sum1 = Add.getOutputSUM();

    Add.add(Add.getOutputSUM(), Cin);
    unsigned int Cout2 = Add.getOutputCARRY();
    
    Sum = Add.getOutputSUM();
    Cout = xorGate.CalcXOR(Cout1, Cout2);
}

unsigned int FullAdder::getCout() { return Cout; }
unsigned int FullAdder::getSum() { return Sum; }
