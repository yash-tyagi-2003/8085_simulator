#include<iostream>
using namespace std;
#include "8085_processor.h"

int main()
{
    vector<string> s;
    cout<<"\n\n\t\t\t\tWelcome to 8085 Emulator\nEnter the Aim of Program : ";
    string aim;
    getline(cin,aim);
    uint16_t x;
    cout<<"\n\nEnter Starting Address : ";
    cin>>hex>>x;
    cin.ignore();
    cout<<"\n\nEnter Program :-\n\n";
    string temp;
    uint16_t t=x;
    while(temp!="HLT")
    {
        cout<<hex<<t<<" : ";
        getline(cin,temp);
        t+=add::count(temp);
        s.push_back(temp);
    }
    s.pop_back();
    char memper;
    CPU obj(s,x);
    obj.initialize_instruction_table();
    cout << "\n\nMenu:\n";
    cout << "1. Initialize memory\n";
    cout << "2. Set breakpoint\n";
    cout << "3. Make subroutine\n";
    cout << "4. Continue to Execute\n";
    cout << "5. Exit\n\n";
    int choice;
    do
    {
        cout<<"\nEnter Further Choice : ";
        cin >> choice;
    switch (choice) {
            case 1:
                obj.obj.memory_initializer();
                break;
            case 2:
                uint16_t breakpoint;
                do
                {
                    cout << "\nEnter breakpoint address: ";
                    cin >> hex >> breakpoint;
                    obj.bp.push(breakpoint);
                    cout<<"\nWant to add more Breakpoints?\n";
                    cin>>memper;
                } while (memper!='N');
                break;
            case 3:
                do
                {
                    obj.subr_init();
                    cout<<"\nWant to make more subroutine?\n";
                    cin>>memper;
                } while (memper=='Y');
                break;
            case 4:break;
            case 5:return 0;
            default:cout<<"Enter a Valid Choice\n";
        }
    } while (choice!=4);
    
    obj.execute();
    do
    {
        cout << "\n\nProgram has Executed Successfully : \n";
        cout << "1. Display memory\n";
        cout << "2. Display CPU state\n";
        cout << "3. Exit\n\n";
        cin>>choice;
        switch(choice)
        {
            case 1:obj.obj.memory_display();
            break;
            case 2:obj.CPU_state();
            break;
            case 3:cout<<"\n\t\t\t\tThank you for using the 8085 Simulator\n\n";
            break;
            default:cout<<"Enter a Valid Choice\n";
        }
    } while (choice!=3);
}