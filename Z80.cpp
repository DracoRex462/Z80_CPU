#include "Z80.h"
#include "CPU/ControlUnit.h"

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