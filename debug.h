#ifndef deb
#define deb
#include "setup.h"

void CPU::debug(uint16_t addr)
{
    cout<<"Debug Console called at Address : "<<addr;
    cout << "Menu:\n";
    cout << "1. Display memory\n";
    cout << "2. Display CPU State\n";
    cout << "3. Skip to next instruction\n";
    cout << "4. Execute until the next breakpoint\n";
    cout << "5. Exit\n\n";
    int choice;
    do
    {
        cout<<"Enter Further Choice : ";
        cin >> choice;
        switch(choice)
        {
            case 1:obj.memory_display();
            break;
            case 2:CPU_state();
            break;
            case 3:PC++;
            break;
            case 4:return;
            case 5:return;
            default:cout<<"Not a Valid Choice.\n";
        }
    } while (choice<3);
}
void CPU::CPU_state()
{
    cout<<"\n\nCPU state is as follows :-\n\n";
    cout<<"A : "<<hex<< static_cast<int>(A)<<"\nB : "<<hex<< static_cast<int>(B)<<"\nC : "<<hex<< static_cast<int>(C)
    <<"\nD : "<<hex<< static_cast<int>(D)<<"\nE : "<<hex<< static_cast<int>(E)<<"\nH : "<<hex<< static_cast<int>(H)
    <<"\nL : "<<hex<< static_cast<int>(L)<<"\nCarry : "<<carry<<"\nAuxiliary Carry : "<<aux_carry<<"\nZero : "<<zero
    <<"\nParity : "<<parity<<"\nSign Flag : "<<sign;
}

#endif