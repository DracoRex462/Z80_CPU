#include <iostream>
#include <cstdint>
#include <vector>

#include "Z80.h"
#include "Memory/Memory.h"
#include "Memory/Register.h"

int main() {
    //std::vector<uint8_t> IR = { 0x71, 0x00, 0x01, 0x91, 0x76 };
    std::vector<uint8_t> IR = { 0x76 };
    Memory memory;
    memory.write(0x0001, 2);

    Register R;
    R.write(0x01, 1);
    R.write(0x02, 2);

    Z80 CPU(IR);
    std::cout << "Anfang Methode\n" << std::endl;
    CPU.PrintRegister();
    std::cout << "Ende Methode\n" << std::endl;
 /*
    Register R;
    uint8_t val = R.read(0);
    std::cout << "Ergebnis: " << static_cast<int>(val) << std::endl;
*/
    return 0;
}
