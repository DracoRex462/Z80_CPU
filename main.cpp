#include <iostream>
#include <cstdint>
#include <vector>

#include "Z80.h"
#include "Memory/Memory.h"
#include "Memory/Register.h"
int main() {
    std::vector<uint8_t> IR = { 0x71, 0x00, 0x01, 0x91, 0x76 };
    Memory memory;
    memory.write(0x0001, 2);

    Z80* CPU = new Z80(IR);
    CPU->Run();

    Register R;
    std::cout << "Ergebniss: " << R.read(0) << std::endl;
}
