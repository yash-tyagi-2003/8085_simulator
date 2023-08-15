#ifndef arith
#define arith
#include "setup.h"

bool CPU::parity_check(uint8_t value) {
    bool result = false;
    for(int i = 0; i < 8; i++) {
        if(value & 1) {
            result = !result;
        }
        value >>= 1;
    }
    return result;
}
void CPU::add_c()
{
    uint16_t result = (uint16_t)A + (uint16_t)C;
    A = (uint8_t)result;
    add_req(&C,result);
}
void CPU::add_d()
{
    uint16_t result = (uint16_t)A + (uint16_t)D;
    A = (uint8_t)result;
    add_req(&D,result);
}
void CPU::add_a()
{
    uint16_t result = (uint16_t)A + (uint16_t)A;
    A = (uint8_t)result;
    add_req(&A,result);
}
void CPU::add_b()
{
    uint16_t result = (uint16_t)A + (uint16_t)B;
    A = (uint8_t)result;
    add_req(&B,result);
}
void CPU::add_e()
{
    uint16_t result = (uint16_t)A + (uint16_t)E;
    A = (uint8_t)result;
    add_req(&E,result);
}
void CPU::add_h()
{
    uint16_t result = (uint16_t)A + (uint16_t)H;
    A = (uint8_t)result;
    add_req(&H,result);
}
void CPU::add_l()
{
    uint16_t result = (uint16_t)A + (uint16_t)L;
    A = (uint8_t)result;
    add_req(&L,result);
}
void CPU::daa()
{
    uint8_t lower_nibble = A & 0x0F;
    uint8_t upper_nibble = A >> 4;
    if (lower_nibble > 9 || aux_carry) {
        A += 0x06;
        aux_carry = (lower_nibble + 6) & 0x10;
    }
    if (upper_nibble > 9 || carry) {
        A += 0x60;
        carry = 1;
    }
    zero=(A==0);
    sign=A & 0x80;
    parity=parity_check(A);
}
void CPU::dad_b()
{
    uint16_t result = (uint16_t)C + (uint16_t)L;
    L=(uint8_t)result;
    result=(uint16_t)B + (uint16_t)H + (result>0xFF);
    H=(uint8_t)result;
    carry=result>0xFF;
}
void CPU::dad_d()
{
    uint16_t result = (uint16_t)E + (uint16_t)L;
    L=(uint8_t)result;
    result=(uint16_t)D + (uint16_t)H + (result>0xFF);
    H=(uint8_t)result;
    carry=result>0xFF;
}
void CPU::dad_h()
{
    uint16_t result = (uint16_t)L + (uint16_t)L;
    L=(uint8_t)result;
    result=(uint16_t)H + (uint16_t)H + (result>0xFF);
    H=(uint8_t)result;
    carry=result>0xFF;
}
void CPU::dad_sp()
{
    uint16_t result = SP & 0x00FF + (uint16_t)L;
    L=(uint8_t)result;
    result=SP & 0xFF00 + (uint16_t)H + (result>0xFF);
    H=(uint8_t)result;
    carry=result>0xFF;
}
void CPU::adc_c()
{
    uint16_t result = (uint16_t)A + (uint16_t)C+(int)carry;
    A = (uint8_t)result;
    add_req(&C,result);
}
void CPU::adc_d()
{
    uint16_t result = (uint16_t)A + (uint16_t)D+(int)carry;
    A = (uint8_t)result;
    add_req(&D,result);
}
void CPU::adc_a()
{
    uint16_t result = (uint16_t)A + (uint16_t)A+carry;
    A = (uint8_t)result;
    add_req(&A,result);
}
void CPU::adc_b()
{
    uint16_t result = (uint16_t)A + (uint16_t)B+carry;
    A = (uint8_t)result;
    add_req(&B,result);
}
void CPU::adc_e()
{
    uint16_t result = (uint16_t)A + (uint16_t)E+carry;
    A = (uint8_t)result;
    add_req(&E,result);
}
void CPU::adc_h()
{
    uint16_t result = (uint16_t)A + (uint16_t)H+carry;
    A = (uint8_t)result;
    add_req(&H,result);
}
void CPU::adc_l()
{
    uint16_t result = (uint16_t)A + (uint16_t)L+carry;
    A = (uint8_t)result;
    add_req(&L,result);
}
void CPU::sub_c()
{
    A-=C;
    sub_req(&C);
}
void CPU::sub_d()
{
    A-=D;
    sub_req(&D);
}
void CPU::sub_a()
{
    A-=A;
    sub_req(&A);
}
void CPU::sub_b()
{
    A-=B;
    sub_req(&B);
}
void CPU::sub_e()
{
    A-=E;
    sub_req(&E);
}
void CPU::sub_h()
{
    A-=H;
    sub_req(&H);
}
void CPU::sub_l()
{
    A-=L;
    sub_req(&L);
}
void CPU::sbb_c()
{
    uint16_t result = A - C - carry;
    A = result & 0xFF;
    sub_req(&C);
}
void CPU::sbb_d()
{
    uint16_t result = A - D - carry;
    A = result & 0xFF;
    sub_req(&D);
}
void CPU::sbb_a()
{
    uint16_t result = A - A - carry;
    A = result & 0xFF;
    sub_req(&A);
}
void CPU::sbb_b()
{
    uint16_t result = A - B - carry;
    A = result & 0xFF;
    sub_req(&B);
}
void CPU::sbb_e()
{
    uint16_t result = A - E - carry;
    A = result & 0xFF;
    sub_req(&E);
}
void CPU::sbb_h()
{
    uint16_t result = A - H - carry;
    A = result & 0xFF;
    sub_req(&H);
}
void CPU::sbb_l()
{
    uint16_t result = A - L - carry;
    A = result & 0xFF;
    sub_req(&L);
}
void CPU::aci()
{
    uint8_t temp=obj.mem[PC];
    uint16_t result = (uint16_t)A + (uint16_t)temp +carry;
    A = (uint8_t)result;
    add_req(&temp,result);
    PC++;
}
void CPU::sbi()
{
    uint8_t temp=obj.mem[PC];
    uint16_t result = A - obj.mem[PC] - carry;
    A = result & 0xFF;
    sub_req(&temp);
    PC++;
}
void CPU::adi()
{
}
void CPU::sui()
{
}
void CPU::adc_m()
{
    uint16_t x=((uint16_t)H << 8) | L;
    uint8_t temp=obj.mem[x];
    uint16_t result = (uint16_t)A + (uint16_t)temp +carry;
    A = (uint8_t)result;
    add_req(&temp,result);
}
void CPU::sub_m()
{
    uint16_t x=((uint16_t)H << 8) | L;
    uint8_t temp=obj.mem[x];
    uint16_t result = A - temp;
    A = result & 0xFF;
    sub_req(&temp);
}
void CPU::sbb_m()
{
    uint16_t x=((uint16_t)H << 8) | L;
    uint8_t temp=obj.mem[x];
    uint16_t result = A - temp - carry;
    A = result & 0xFF;
    sub_req(&temp);
}
void CPU::add_m()
{
    uint16_t x=((uint16_t)H << 8) | L;
    uint8_t temp=obj.mem[x];
    uint16_t result = (uint16_t)A + (uint16_t)temp;
    A = (uint8_t)result;
    add_req(&temp,result);
}
void CPU::add_req(uint8_t *flag,uint16_t result)
{
    zero = (A == 0);
    sign = (A & 0x80);
    carry = (result > 0xFF);
    parity = parity_check(A);
    aux_carry = ((A & 0x0F) + (*flag & 0x0F) > 0x0F);
}
void CPU::sub_req(uint8_t *flag)
{
    zero=(A==0);
    carry=A<*flag;
    aux_carry = (A & 0x08) < (*flag & 0x08);
    parity=parity_check(A);
    sign = A & 0x80;
}

#endif