#include "Z80.h"

void Z80::Run()
{
    bool approved = ApproveVector();
    if (approved == true)
    {

    }
    else
        return 0;
}

int Z80::ApproveVector()
{
    for(size_t pc = 0; pc < IR.size(); ++pc) {
        if(IR[pc] == 0x0000) return true;
    }
    return false;
}