#ifndef Z80_CPU_TEMP_H
#define Z80_CPU_TEMP_H

class Temp {
public:
    void setValue(uint8_t data) { value = data; };
    uint8_t getValue() { return value; };

private:
    uint8_t value;
};

#endif