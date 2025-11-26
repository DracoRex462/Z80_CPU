#ifndef HALFADDER_H
#define HALFADDER_H

class HalfAdder {
public:
    HalfAdder() : sum(0), carry(0) {};
    void add(unsigned int Input1, unsigned int Input2);

    unsigned int getOutputSUM();
    unsigned int getOutputCARRY();

private:
    unsigned int sum;
    unsigned int carry;
};

#endif