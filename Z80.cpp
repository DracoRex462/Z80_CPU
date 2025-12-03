#include "Z80.h"
#include "CPU/ControlUnit.h"
#include "Memory/Register.h"
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


void PrintRegister()
{
    Register R;
    for (int i = 0; i < R.size(); ++i)
        std::cout << "Register " << i << ": " << R[i] << std::endl;
};