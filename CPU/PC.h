#ifndef PC_H
#define PC_H

class PC
{
public:
    PC() : counter(0x00) {};
    void setCounter(unsigned int ct) { counter = ct; };
    unsigned int  getCounter() { return counter; }

private:
    unsigned int counter;
};


#endif