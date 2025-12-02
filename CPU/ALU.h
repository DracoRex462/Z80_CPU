#ifndef ALU_H
#define ALU_H

class ALU
{
public:
    ALU() {};
    void execute(unsigned int xField, unsigned int yField);

private:
    void executeADD(unsigned int yField);
    void executeSUP(unsigned int yField);
    void executeLD(unsigned int yField);
};

#endif