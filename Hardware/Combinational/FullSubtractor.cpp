#include "Subtractor.h"
#include "../Logic/OR.h"

void FullSubtractor::sub(unsigned int Bin, unsigned int A, unsigned int B) {
    XOR xorGate;
    AND andGate;
    OR orGate;

    unsigned int A_xor_B = xorGate.CalcXOR(A, B);
    C = xorGate.CalcXOR(A_xor_B, Bin);

    unsigned int borrow1 = andGate.CalcAND((~A) & 1, B);
    unsigned int borrow2 = andGate.CalcAND(A_xor_B, Bin);

    S = orGate.CalcOR(borrow1, borrow2);
}

unsigned int Subtractor::getC() { return OutputC; }
unsigned int Subtractor::getS() { return OutputS; }
