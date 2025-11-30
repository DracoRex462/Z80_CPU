#ifndef PC_H
#define PC_H


class PC
{
public:
    PC() : counter(0x1000) {};
    void setCounter(unsigned int counter) : counter(counter) {};
    unsigned int  getCounter() { return counter; }

private:
    unsigned int counter;
};


#endif