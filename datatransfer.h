#ifndef dt
#define dt
#include "setup.h"

void CPU::mov_ab()
{
    A=B;
}
void CPU::mov_ac()
{
    A=C;
}
void CPU::mov_ad()
{
    A=D;
}
void CPU::mov_ae()
{
    A=E;
}
void CPU::mov_ah()
{
    A=H;
}
void CPU::mov_al()
{
    A=L;
}
void CPU::mov_ba()
{
    B=A;
}
void CPU::mov_bc()
{
    B=C;
}
void CPU::mov_bd()
{
    B=D;
}
void CPU::mov_be()
{
    B=E;
}
void CPU::mov_bh()
{
    B=H;
}
void CPU::mov_bl()
{
    B=L;
}
void CPU::mov_ca()
{
    C=A;
}
void CPU::mov_cb()
{
    C=B;
}
void CPU::mov_cd()
{
    C=D;
}
void CPU::mov_ce()
{
    C=E;
}
void CPU::mov_ch()
{
    C=H;
}
void CPU::mov_cl()
{
    C=L;
}
void CPU::mov_da()
{
    D=A;
}
void CPU::mov_db()
{
    D=B;
}
void CPU::mov_dc()
{
    D=C;
}
void CPU::mov_de()
{
    D=E;
}
void CPU::mov_dh()
{
    D=H;
}
void CPU::mov_dl()
{
    D=L;
}
void CPU::mov_ea()
{
    E=A;
}
void CPU::mov_eb()
{
    E=B;
}
void CPU::mov_ec()
{
    E=C;
}
void CPU::mov_ed()
{
    E=D;
}
void CPU::mov_eh()
{
    E=H;
}
void CPU::mov_el()
{
    E=L;
}
void CPU::mov_ha()
{
    H=A;
}
void CPU::mov_hb()
{
    H=B;
}
void CPU::mov_hc()
{
    H=C;
}
void CPU::mov_hd()
{
    H=D;
}
void CPU::mov_he()
{
    H=E;
}
void CPU::mov_hl()
{
    H=L;
}
void CPU::mov_la()
{
    L=A;
}
void CPU::mov_lb()
{
    L=B;
}
void CPU::mov_lc()
{
    L=C;
}
void CPU::mov_ld()
{
    L=D;
}
void CPU::mov_le()
{
    L=E;
}
void CPU::mov_lh()
{
    L=H;
}
void CPU::mov_am()
{
    uint16_t x=((uint16_t)H << 8) | L;
    A=obj.mem[x];
}
void CPU::mov_bm()
{
    uint16_t x=((uint16_t)H << 8) | L;
    B=obj.mem[x];
}
void CPU::mov_cm()
{
    uint16_t x=((uint16_t)H << 8) | L;
    C=obj.mem[x];
}
void CPU::mov_dm()
{
    uint16_t x=((uint16_t)H << 8) | L;
    D=obj.mem[x];
}
void CPU::mov_em()
{
    uint16_t x=((uint16_t)H << 8) | L;
    E=obj.mem[x];
}
void CPU::mov_hm()
{
    uint16_t x=((uint16_t)H << 8) | L;
    H=obj.mem[x];
}
void CPU::mov_lm()
{
    uint16_t x=((uint16_t)H << 8) | L;
    L=obj.mem[x];
}
void CPU::mov_ma()
{
    uint16_t x=((uint16_t)H << 8) | L;
    obj.mem[x]=A;
}
void CPU::mov_mb()
{
    uint16_t x=((uint16_t)H << 8) | L;
    obj.mem[x]=B;
}
void CPU::mov_mc()
{
    uint16_t x=((uint16_t)H << 8) | L;
    obj.mem[x]=C;
}
void CPU::mov_md()
{
    uint16_t x=((uint16_t)H << 8) | L;
    obj.mem[x]=D;
}
void CPU::mov_me()
{
    uint16_t x=((uint16_t)H << 8) | L;
    obj.mem[x]=E;
}
void CPU::mov_mh()
{
    uint16_t x=((uint16_t)H << 8) | L;
    obj.mem[x]=H;
}
void CPU::mov_ml()
{
    uint16_t x=((uint16_t)H << 8) | L;
    obj.mem[x]=L;
}
void CPU::mvi_a()
{
    A= this->obj.mem[PC++];
}
void CPU::mvi_b()
{
    B= this->obj.mem[PC++];
}
void CPU::mvi_c()
{
    C= this->obj.mem[PC++];
}
void CPU::mvi_d()
{
    D= this->obj.mem[PC++];
}
void CPU::mvi_e()
{
    E= this->obj.mem[PC++];
}
void CPU::mvi_h()
{
    H= this->obj.mem[PC++];
}
void CPU::mvi_l()
{
    L= this->obj.mem[PC++];
}
void CPU::mvi_m()
{
    uint16_t x=((uint16_t)H << 8) | L;
    obj.mem[x]=obj.mem[PC++];
}
void CPU::lhld()
{
    uint16_t x=((uint16_t)obj.mem[PC] << 8) | obj.mem[PC+1];
    PC+=2;
    H=obj.mem[x];
    L=obj.mem[x+1];
}
void CPU::shld()
{
    uint16_t x=((uint16_t)obj.mem[PC] << 8) | obj.mem[PC+1];
    obj.mem[x]=H;
    obj.mem[x+1]=L;
    PC+=2;
}
void CPU::lda()
{
    uint16_t x=((uint16_t)obj.mem[PC] << 8) | obj.mem[PC+1];
    PC+=2;
    A=obj.mem[x];
}
void CPU::sta()
{
    uint16_t x=((uint16_t)obj.mem[PC] << 8) | obj.mem[PC+1];
    PC+=2;
    obj.mem[x]=A;
}
void CPU::lxi_b()
{
    B=obj.mem[PC];
    C=obj.mem[PC+1];
    PC+=2;
}
void CPU::lxi_d()
{
    D=obj.mem[PC];
    E=obj.mem[PC+1];
    PC+=2;
}
void CPU::lxi_h()
{
    H=obj.mem[PC];
    L=obj.mem[PC+1];
    PC+=2;
}
void CPU::lxi_sp()
{
    SP=((uint16_t)obj.mem[PC] << 8) | obj.mem[PC+1];
    PC+=2;
}
void CPU::ldax_b()
{
    uint16_t x=((uint16_t)B << 8) | C;
    A=obj.mem[x];
}
void CPU::ldax_d()
{
    uint16_t x=((uint16_t)D << 8) | E;
    A=obj.mem[x];
}
void CPU::stax_b()
{
    uint16_t x=((uint16_t)B << 8) | C;
    obj.mem[x]=A;
}
void CPU::stax_d()
{
    uint16_t x=((uint16_t)D << 8) | E;
    obj.mem[x]=A;
}
void CPU::xchg()
{
    uint8_t W=H;
    uint8_t Z=L;
    H=D;
    L=E;
    D=W;
    E=Z;
}

#endif