#ifndef stk
#define stk
#include "setup.h"

void CPU::push_b()
{
    obj.mem[SP-1]=B;
    obj.mem[SP-2]=C;
    SP-=2;
}
void CPU::push_d()
{
    obj.mem[SP-1]=D;
    obj.mem[SP-2]=E;
    SP-=2;
}
void CPU::push_h()
{
    obj.mem[SP-1]=H;
    obj.mem[SP-2]=L;
    SP-=2;
}
void CPU::push_psw()
{
    F |= (sign << 7);
    F |= (zero << 6);
    F |= (aux_carry << 4);
    F |= (parity << 2);
    F |= (carry << 0); 
    obj.mem[SP-1]=A;
    obj.mem[SP-2]=F;
    SP-=2;
}
void CPU::pop_b()
{
    B=obj.mem[SP+1];
    C=obj.mem[SP];
    SP+=2;
}
void CPU::pop_d()
{
    D=obj.mem[SP+1];
    E=obj.mem[SP];
    SP+=2;
}
void CPU::pop_h()
{
    H=obj.mem[SP+1];
    L=obj.mem[SP];
    SP+=2;
}
void CPU::pop_psw()
{
    A=obj.mem[SP+1];
    F=obj.mem[SP];
    SP+=2;
}
void CPU::xthl()
{
    uint8_t x=H,y=L;
    H=obj.mem[SP+1];
    L=obj.mem[SP];
    obj.mem[SP+1]=x;
    obj.mem[SP]=y;
}
void CPU::pchl()
{
    PC=((uint16_t)H<<8) | L;
}
void CPU::sphl()
{
    SP=((uint16_t)H<<8) | L;
}

#endif