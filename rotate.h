#ifndef rot
#define rot
#include "setup.h"

void CPU::rlc()
{
    uint8_t msb = A >> 7;
    A <<= 1;
    A |= msb;
    carry=msb;
}
void CPU::rrc()
{
    uint8_t lsb = A & 1;
    A = (A >> 1) | (lsb << 7);
    carry=lsb;
}
void CPU::rar()
{
    uint8_t lsb = A & 1;
    A = (A >> 1) | (carry << 7);
    carry=lsb;
}
void CPU::ral()
{
    uint8_t msb = A >> 7;
    A <<= 1;
    A |= carry;
    carry=msb;
}

#endif