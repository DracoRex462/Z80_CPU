#ifndef ALU_H
#define ALU_H

class ALU
{
public:
    ALU() {};
    void execute(unsigned int xField, unsigned int yField);

private:
    unsigned int executeADD(unsigned int yField);
    unsigned int executeSUP(unsigned int yField);
    unsigned int executeLD(unsigned int yField);
};

#endif