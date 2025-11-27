#ifndef BIT_H
#define BIT_H

class Bit {
    public:
        Bit(unsigned int valueset) { setValue(valueset); };

        unsigned int toggle() { return value = !value; };
        
        void setValue(unsigned int valueset) { value = valueset % 2; };
        const unsigned int getValue() { return value; };

    private:
        unsigned int value;
};

#endif