#ifndef subr
#define subr
#include "setup.h"
#include "add.h"

void CPU::subr_init()
{
    vector<string> s;
    uint16_t start;
    cout<<"\n\nEnter Starting Address of Subroutine: ";
    cin>>hex>>start;
    cin.ignore();
    cout<<"\n\nEnter Program for Subroutine :-\n\n";
    string temp;
    uint16_t t=start;
    while(temp!="RET")
    {
        cout<<hex<<t<<" : ";
        getline(cin,temp);
        t+=add::count(temp);
        s.push_back(temp);
    }
    obj.x=start;
    obj.fins(s);
}
void CPU::call()
{
    obj.mem[SP-1]=((PC+2) >> 8) & 0xFF;
    obj.mem[SP-2]=(PC+2) & 0xFF;
    SP-=2;
    PC=((uint16_t)obj.mem[PC] << 8) | obj.mem[PC+1];
}
void CPU::cc()
{
    if(carry)
    call();
    else
    PC+=2;
}
void CPU::cnc()
{
    if(!carry)
    call();
    else
    PC+=2;
}
void CPU::cz()
{
    if(zero)
    call();
    else
    PC+=2;
}
void CPU::cnz()
{
    if(!zero)
    call();
    else
    PC+=2;
}
void CPU::cm()
{
    if(sign)
    call();
    else
    PC+=2;
}
void CPU::cp()
{
    if(!sign)
    call();
    else
    PC+=2;
}
void CPU::cpe()
{
    if(parity)
    call();
    else
    PC+=2;
}
void CPU::cpo()
{
    if(!parity)
    call();
    else
    PC+=2;
}
void CPU::ret()
{
    uint16_t x=(uint16_t)obj.mem[SP+1]<<8 | obj.mem[SP];
    SP+=2;
    PC=x;
}
void CPU::rc()
{
    if(carry)
    ret();
    else
    PC+=2;
}
void CPU::rnc()
{
    if(!carry)
    ret();
    else
    PC+=2;
}
void CPU::rz()
{
    if(zero)
    ret();
    else
    PC+=2;
}
void CPU::rnz()
{
    if(!zero)
    ret();
    else
    PC+=2;
}
void CPU::rp()
{
    if(!sign)
    ret();
    else
    PC+=2;
}
void CPU::rm()
{
    if(sign)
    ret();
    else
    PC+=2;
}
void CPU::rpe()
{
    if(parity)
    ret();
    else
    PC+=2;
}
void CPU::rpo()
{
    if(!parity)
    ret();
    else
    PC+=2;
}

#endif