#include "FullSubtractor.h"
#include "../Logic/OR.h"
#include "../Logic/XOR.h"
#include "../Logic/AND.h"

void FullSubtractor::sub(unsigned int Bin, unsigned int A, unsigned int B) {
    XOR xorGate;
    AND andGate;
    OR orGate;

    unsigned int A_xor_B = xorGate.CalcXOR(A, B);
    unsigned int C = xorGate.CalcXOR(A_xor_B, Bin);

    unsigned int borrow1 = andGate.CalcAND((~A) & 1, B);
    unsigned int borrow2 = andGate.CalcAND(A_xor_B, Bin);

    unsigned int S = orGate.CalcOR(borrow1, borrow2);
}

unsigned int FullSubtractor::getC() { return OutputC; }
unsigned int FullSubtractor::getS() { return OutputS; }
