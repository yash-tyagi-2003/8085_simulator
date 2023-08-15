#ifndef mutater
#define mutater
#include "setup.h"

void CPU::inr_b()
{
    B++;
    if(B>0xFF)
    {
        carry=true;
        aux_carry=true;
        B=0x00;
    }
    else if(B==0x10)
    aux_carry=true;
}
void CPU::inr_c()
{
    C++;
    if(C>0xFF)
    {
        carry=true;
        aux_carry=true;
        C=0x00;
    }
    else if(C==0x10)
    aux_carry=true;
}
void CPU::inr_d()
{
    D++;
    if(D>0xFF)
    {
        carry=true;
        aux_carry=true;
        D=0x00;
    }
    else if(D==0x10)
    aux_carry=true;
}
void CPU::inr_e()
{
    E++;
    if(E>0xFF)
    {
        carry=true;
        aux_carry=true;
        E=0x00;
    }
    else if(E==0x10)
    aux_carry=true;
}
void CPU::inr_h()
{
    H++;
    if(H>0xFF)
    {
        carry=true;
        aux_carry=true;
        H=0x00;
    }
    else if(H==0x10)
    aux_carry=true;
}
void CPU::inr_l()
{
    L++;
    if(L>0xFF)
    {
        carry=true;
        aux_carry=true;
        L=0x00;
    }
    else if(L==0x10)
    aux_carry=true;
}
void CPU::inr_m()
{
    obj.mem[H*100+L]++;
    if(obj.mem[H*100+L]>0xFF)
    {
        carry=true;
        aux_carry=true;
        obj.mem[H*100+L]=0x00;
    }
    else if(obj.mem[H*100+L]==0x10)
    aux_carry=true;
}
void CPU::inr_a()
{
    A++;
    if(A>0xFF)
    {
        carry=true;
        aux_carry=true;
        A=0x00;
    }
    else if(A==0x10)
    aux_carry=true;
}
void CPU::dcr_b()
{
    B--;
    if(B==0x00)
    zero=true;
}
void CPU::dcr_c()
{
    C--;
    if(C==0x00)
    zero=true;
}
void CPU::dcr_d()
{
    D--;
    if(D==0x00)
    zero=true;
}
void CPU::dcr_e()
{
    E--;
    if(E==0x00)
    zero=true;
}
void CPU::dcr_h()
{
    H--;
    if(H==0x00)
    zero=true;
}
void CPU::dcr_l()
{
    L--;
    if(L==0x00)
    zero=true;
}
void CPU::dcr_m()
{
    B--;
    if(B==0x00)
    zero=true;
}
void CPU::dcr_a()
{
    A--;
    if(A==0x00)
    zero=true;
}
void CPU::inx_b()
{
    if(C==0xFF)
    {
        if(B==0xFF)
        {
            B=0x00;
            carry=true;
        }
        else
        B+=1;
        C=0x00;
    }
    else
    C+=1;
}
void CPU::inx_d()
{
    if(E==0xFF)
    {
        if(D==0xFF)
        {
            D=0x00;
            carry=true;
        }
        else
        D+=1;
        E=0x00;
    }
    else
    E+=1;
}
void CPU::inx_h()
{
    uint16_t HL = ((uint16_t)H << 8) | L;
    HL++;
    H = (HL >> 8) & 0xFF;
    L = HL & 0xFF;
}
void CPU::inx_sp()
{
    SP+=1;
}
void CPU::dcx_b()
{
    uint16_t BC = ((uint16_t)B << 8) | C;
    BC--;
    B = (BC >> 8) & 0xFF;
    C = BC & 0xFF;
}
void CPU::dcx_d()
{
    uint16_t DE = ((uint16_t)D << 8) | E;
    DE--;
    D = (DE >> 8) & 0xFF;
    E = DE & 0xFF;
}
void CPU::dcx_h()
{
    uint16_t HL= ((uint16_t)H << 8) | L;
    HL--;
    H = (HL >> 8) & 0xFF;
    L = HL & 0xFF;
}
void CPU::dcx_sp()
{
    SP--;
}

#endif