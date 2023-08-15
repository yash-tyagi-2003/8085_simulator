#ifndef logical
#define logical
#include "setup.h"

void CPU::logic_ana_req()
{
    zero=(A==0);
    parity=parity_check(A);
    sign=A & 0x80;
    carry=false;
    aux_carry=true;
}
void CPU::logic_xra_req()
{
    zero=(A==0);
    parity=parity_check(A);
    sign=A & 0x80;
    carry=false;
    aux_carry=false;
}
void CPU::ana_a()
{
    A=A&A;
    logic_ana_req();
}
void CPU::ana_b()
{
    A=A&B;
    logic_ana_req();
}
void CPU::ana_c()
{
    A=A&C;
    logic_ana_req();
}
void CPU::ana_d()
{
    A=A&D;
    logic_ana_req();
}
void CPU::ana_e()
{
    A=A&E;
    logic_ana_req();
}
void CPU::ana_h()
{
    A=A&H;
    logic_ana_req();
}
void CPU::ana_l()
{
    A=A&L;
    logic_ana_req();
}
void CPU::xra_a()
{
    A=A^A;
    logic_xra_req();
}
void CPU::xra_b()
{
    A=A^B;
    logic_xra_req();
}
void CPU::xra_c()
{
    A=A^C;
    logic_xra_req();
}
void CPU::xra_d()
{
    A=A^D;
    logic_xra_req();
}
void CPU::xra_e()
{
    A=A^E;
    logic_xra_req();
}
void CPU::xra_h()
{
    A=A^H;
    logic_xra_req();
}
void CPU::xra_l()
{
    A=A^L;
    logic_xra_req();
}
void CPU::ora_a()
{
    A=A|A;
    logic_xra_req();
}
void CPU::ora_b()
{
    A=A|B;
    logic_xra_req();
}
void CPU::ora_c()
{
    A=A|C;
    logic_xra_req();
}
void CPU::ora_d()
{
    A=A|D;
    logic_xra_req();
}
void CPU::ora_e()
{
    A=A|E;
    logic_xra_req();
}
void CPU::ora_h()
{
    A=A|H;
    logic_xra_req();
}
void CPU::ora_l()
{
    A=A|L;
    logic_xra_req();
}
void CPU::cmp_a()
{
}
void CPU::cmp_b()
{
    if(A<B)
    carry=true;
    else
    carry=false;
    if(A==B)
    zero=true;
    else
    zero=false;
}
void CPU::cmp_c()
{
    if(A<C)
    carry=true;
    else
    carry=false;
    if(A==C)
    zero=true;
    else
    zero=false;
}
void CPU::cmp_d()
{
    if(A<D)
    carry=true;
    else
    carry=false;
    if(A==D)
    zero=true;
    else
    zero=false;
}
void CPU::cmp_e()
{
    if(A<E)
    carry=true;
    else
    carry=false;
    if(A==E)
    zero=true;
    else
    zero=false;
}
void CPU::cmp_h()
{
    if(A<H)
    carry=true;
    else
    carry=false;
    if(A==H)
    zero=true;
    else
    zero=false;
}
void CPU::cmp_l()
{
    if(A<L)
    carry=true;
    else
    carry=false;
    if(A==L)
    zero=true;
    else
    zero=false;
}
void CPU::cma()
{
    A=!A;
}
void CPU::cmc()
{
    carry=!carry;
}
void CPU::ani()
{
    A&=obj.mem[PC++];
    logic_ana_req();
}
void CPU::xri()
{
    A^=obj.mem[PC++];
    logic_xra_req();
}
void CPU::cpi()
{
    if(A<obj.mem[PC++])
    carry=true;
    else
    carry=false;
}
void CPU::ori()
{
    A|=obj.mem[PC++];
    logic_xra_req();
}
void CPU::ora_m()
{
    uint16_t x=((uint16_t)H << 8) | L;
    A=A|obj.mem[x];
    logic_xra_req();
}
void CPU::ana_m()
{
    uint16_t x=((uint16_t)H << 8) | L;
    A=A&obj.mem[x];
    logic_ana_req();
}
void CPU::cmp_m()
{
    uint16_t x=((uint16_t)H << 8) | L;
    if(A<obj.mem[x])
    carry=true;
    else
    carry=false;
    if(A==obj.mem[x])
    zero=true;
    else
    zero=false;
}
void CPU::xra_m()
{
    uint16_t x=((uint16_t)H << 8) | L;
    A=A^obj.mem[x];
    logic_xra_req();
}

#endif