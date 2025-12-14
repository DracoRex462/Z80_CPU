#include "Z80.h"
#include "CPU/ControlUnit.h"
#include "CPU/PC.h"

#include <iostream>

void Z80::Run()
{
    bool approved = ApproveVector();
    if (approved)
    {
        ControlUnit* Control = new ControlUnit(IR);
        Control->decode_and_execute();
    }
    else { throw; }
}

int Z80::ApproveVector()
{
    for(int pc = 0; pc < IR.size(); ++pc) {
        if(IR[pc] == 0x76) return true;
    }
    return false;
}

void Z80::PrintRegister() {
    Register R;
    std::cout << "Start" << std::endl;
    for (int i = 0; i < 7; ++i)
        std::cout << "Register " << i << ": " << R.read(i) << std::endl;
}

void Z80::PrintPCCounter() {
    PC counter;
    std::cout << "PC Counter: " << counter.getCounter() << std::endl;
}
