#ifndef FULLADDR_H
#define FULLADDR_H

class FullAdder {
public:
    FullAdder() : Cout(0), Sum(0) {};
    void add(unsigned int Cin, unsigned int A, unsigned int B);

    unsigned int getCout();
    unsigned int getSum();

private:
    unsigned int Cout;
    unsigned int Sum;
};

#endif
