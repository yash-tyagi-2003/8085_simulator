#ifndef branch
#define branch
#include "setup.h"

void CPU::jmp()
{
    uint16_t x=((uint16_t)obj.mem[PC] << 8) | obj.mem[PC+1];
    PC=x;
}
void CPU::jz()
{
    if(zero)
    {
        uint16_t x=((uint16_t)obj.mem[PC] << 8) | obj.mem[PC+1];
        PC=x;
    }
    else
    PC+=2;
}
void CPU::jnz()
{
    if(!zero)
    {
        uint16_t x=((uint16_t)obj.mem[PC] << 8) | obj.mem[PC+1];
        PC=x;
    }
    else
    PC+=2;
}
void CPU::jc()
{
    if(carry)
    {
        uint16_t x=((uint16_t)obj.mem[PC] << 8) | obj.mem[PC+1];
        PC=x;
    }
    else
    PC+=2;
}
void CPU::jnc()
{
    if(!carry)
    {
        uint16_t x=((uint16_t)obj.mem[PC] << 8) | obj.mem[PC+1];
        PC=x;
    }
    else
    PC+=2;
}
void CPU::jm()
{
    if(sign)
    {
        uint16_t x=((uint16_t)obj.mem[PC] << 8) | obj.mem[PC+1];
        PC=x;
    }
    else
    PC+=2;
}
void CPU::jp()
{
    if(!sign)
    {
        uint16_t x=((uint16_t)obj.mem[PC] << 8) | obj.mem[PC+1];
        PC=x;
    }
    else
    PC+=2;
}

#endif