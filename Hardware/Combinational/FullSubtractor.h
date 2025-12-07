#ifndef SUBTRACTOR_H
#define SUBTRACTOR_H


class FullSubtractor {
public:
    FullSubtractor() : OutputC(0), OutputS(0) {};
    void sub(unsigned int C, unsigned int input_1, unsigned int input_2);

    unsigned int getC();
    unsigned int getS();

private:
    unsigned int OutputS;
    unsigned int OutputC;
};

#endif
