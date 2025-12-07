#ifndef Z80_CPU_TEMP_H
#define Z80_CPU_TEMP_H

class Temp {
public:
    void setValue(unsigned int data) { value = data; };
    unsigned int getValue() { return value; };

private:
    unsigned int value;
};


#endif