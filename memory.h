#ifndef cpumemory
#define cpumemory
#include<iostream>
#include<map>
#include<string>
#include<cstdint>
using namespace std;
class memory
{
    public:
    uint8_t mem[0xFFFF]={0};
    uint16_t x;
    memory()
    {
    }
    void fins(vector<string> s)
    {
        map<string,uint8_t> opc={{"ADD B", 0x80},{"ADD C", 0x81},{"ADD D", 0x82},{"ADD E", 0x83},{"ADD H", 0x84},{"ADD L", 0x85},
        {"ADD M", 0x86},{"ADD A", 0x87},{"ADC B", 0x88},{"ADC C", 0x89},{"ADC D", 0x8A},{"ADC E", 0x8B},{"ADC H", 0x8C},
        {"ADC L", 0x8D},{"ADC M", 0x8E},{"ADC A", 0x8F},{"SUB B", 0x90},{"SUB C", 0x91},{"SUB D", 0x92},{"SUB E", 0x93},
        {"SUB H", 0x94},{"SUB L", 0x95},{"SUB M", 0x96},{"SUB A", 0x97},{"SBB B", 0x98},{"SBB C", 0x99},{"SBB D", 0x9A},
        {"SBB E", 0x9B},{"SBB H", 0x9C},{"SBB L", 0x9D},{"SBB M", 0x9E},{"SBB A", 0x9F},{"ANA B", 0xA0},{"ANA C", 0xA1},
        {"ANA D", 0xA2},{"ANA E", 0xA3},{"ANA H", 0xA4},{"ANA L", 0xA5},{"ANA M", 0xA6},{"ANA A", 0xA7},{"XRA B", 0xA8},
        {"XRA C", 0xA9},{"XRA D", 0xAA},{"XRA E", 0xAB},{"XRA H", 0xAC},{"XRA L", 0xAD},{"XRA M", 0xAE},{"XRA A", 0xAF},
        {"ORA B", 0xB0},{"ORA C", 0xB1},{"ORA D", 0xB2},{"ORA E", 0xB3},{"ORA H", 0xB4},{"ORA L", 0xB5},{"ORA M", 0xB6},
        {"ORA A", 0xB7},{"CMP B", 0xB8},{"CMP C", 0xB9},{"CMP D", 0xBA},{"CMP E", 0xBB},{"CMP H", 0xBC},{"CMP L", 0xBD},
        {"CMP M", 0xBE},{"CMP A", 0xBF},{"CMA", 0x2F},{"CMC", 0x3F},{"JMP", 0xC3},{"JZ", 0xC2},{"JNZ", 0xC4},{"JC", 0xDA},
        {"JNC", 0xD2},{"JP", 0xF2},{"JM", 0xFA},{"CALL", 0xCD},{"CZ", 0xC4},{"CNZ", 0xC2},{"CC", 0xD4},{"CNC", 0xD2},{"CP", 0xF4},
        {"CM", 0xFC},{"RET", 0xC9},{"RZ", 0xC8},{"RNZ", 0xC0},{"RC", 0xD8},{"RNC", 0xD0},{"RP", 0xF0},{"RM", 0xF8},{"MOV A, B", 0x78},
        {"MOV A, C", 0x79},{"MOV A, D", 0x7A},{"MOV A, E", 0x7B},{"MOV A, H", 0x7C},{"MOV A, L", 0x7D},{"MOV A, M", 0x7E},
        {"MOV B, A", 0x47},{"MOV B, C", 0x41},{"MOV B, D", 0x42},{"MOV B, E", 0x43},{"MOV B, H", 0x44},{"MOV B, L", 0x45},
        {"MOV B, M", 0x46},{"MOV C, A", 0x4F},{"MOV C, B", 0x48},{"MOV C, D", 0x4A},{"MOV C, E", 0x4B},{"MOV C, H", 0x4C},
        {"MOV C, L", 0x4D},{"MOV C, M", 0x4E},{"MOV D, A", 0x57},{"MOV D, B", 0x50},{"MOV D, C", 0x51},{"MOV D, E", 0x53},
        {"MOV D, H", 0x54},{"MOV D, L", 0x55},{"MOV D, M", 0x56},{"MOV E, A", 0x5F},{"MOV E, B", 0x58},{"MOV E, C", 0x59},
        {"MOV E, D", 0x5A},{"MOV E, H", 0x5C},{"MOV E, L", 0x5D},{"MOV E, M", 0x5E},{"MOV H, A", 0x67},{"MOV H, B", 0x60},
        {"MOV H, C", 0x61},{"MOV H, D", 0x62},{"MOV H, E", 0x63},{"MOV H, L", 0x65},{"MOV H, M", 0x66},{"MOV L, A", 0x6F},
        {"MOV L, B", 0x68},{"MOV L, C", 0x69},{"MOV L, D", 0x6A},{"MOV L, E", 0x6B},{"MOV L, H", 0x6C},{"MOV L, M", 0x6E},
        {"MOV M, A", 0x77},{"MOV M, B", 0x70},{"MOV M, C", 0x71},{"MOV M, D", 0x72},{"MOV M, E", 0x73},{"MOV M, H", 0x74},
        {"MOV M, L", 0x75},{"MVI B", 0x06},{"MVI C", 0x0E},{"MVI D", 0x16},{"MVI E", 0x1E},{"MVI H", 0x26},{"MVI L", 0x2E},
        {"MVI M", 0x36},{"MVI A", 0x3E},{"LHLD", 0x2A},{"SHLD", 0x22},{"LDA", 0x3A},{"STA", 0x32},{"LXI B", 0x01},
        {"LXI D", 0x11},{"LXI H", 0x21},{"LXI SP", 0x31},{"LDAX B", 0x0A},{"LDAX D", 0x1A},{"STAX B", 0x02},{"STAX D", 0x12},
        {"XCHG", 0xEB},{"RLC", 0x07},{"RRC", 0x0F},{"RAR", 0x1F},{"RAL", 0x17},{"ADI",0XC6},{"ACI",0XCE},{"SUI",0XD6},
        {"SBI",0XDE},{"ANI",0XE6},{"ORI",0XF6},{"XRI",0XEE},{"CPI",0XFE},{"INX B", 0x03},{"INX D", 0x13},{"INX H", 0x23},
        {"INX SP", 0x33},{"DCX B", 0x0B},{"DCX D", 0x1B},{"DCX H", 0x2B},{"DCX SP", 0x3B},{"INR A", 0x3C},{"INR B", 0x04},
        {"INR C", 0x0C},{"INR D", 0x14},{"INR E", 0x1C},{"INR H", 0x24},{"INR L", 0x2C},{"INR M", 0x34},{"DCR A", 0x3D},
        {"DCR B", 0x05},{"DCR C", 0x0D},{"DCR D", 0x15},{"DCR E", 0x1D},{"DCR H", 0x25},{"DCR L", 0x2D},{"DCR M", 0x35},
        {"CALL", 0xCD},{"CC", 0xDC},{"CNC", 0xD4},{"CZ", 0xCC},{"CNZ", 0xC4},{"CP", 0xF4},{"CM", 0xFC},
        {"CPE", 0xEC},{"CPO", 0xE4},{"RET", 0xC9},{"RC", 0xD8},{"RNC", 0xD0},{"RZ", 0xC8},{"RNZ", 0xC0},
        {"RP", 0xF0},{"RM", 0xF8},{"RPE", 0xE8},{"RPO", 0xE0},{"PUSH B", 0xC5},{"PUSH D", 0xD5},{"PUSH H", 0xE5},{"PUSH PSW", 0xF5},
        {"POP B", 0xC1},{"POP D", 0xD1},{"POP H", 0xE1},{"POP PSW", 0xF1},{"XTHL", 0xE3},{"PCHL", 0xE9},{"SPHL", 0xF9},
        {"DAA", 0x27},{"DAD B", 0x09},{"DAD D", 0x19},{"DAD H", 0x29},{"DAD SP", 0x39}};
        int l=s.size();
        int t=0;
        for(int i=0;i<l;i++)
        {
            t=s[i].find_last_of(" ");
            if (s[i].find("MVI")==0||s[i].find("ADI")==0||s[i].find("ACI")==0||s[i].find("SUI")==0||s[i].find("SBI")==0||
            s[i].find("ANI")==0||s[i].find("ORI")==0||s[i].find("XRI")==0||s[i].find("CPI")==0){
                if(opc.find(s[i].substr(0,t))!=opc.end())
                mem[x++]=(opc[s[i].substr(0,t)]);
                mem[x++]=static_cast<uint8_t>(std::stoul(s[i].substr(t), nullptr, 16));
            }
            else if (s[i].find("LXI")==0||s[i].find("LHLD")==0||s[i].find("SHLD")==0||s[i].find("STA")==0||s[i].find("LDA")==0
            ||s[i].find("JMP")==0||s[i].find("JZ")==0||s[i].find("JNZ")==0||s[i].find("JC")==0||s[i].find("JNC")==0||s[i].find("JM")==0
            ||s[i].find("JP")==0||s[i].find("CALL")==0||s[i].find("CC")==0||s[i].find("CNC")==0||s[i].find("CZ")==0||s[i].find("CNZ")==0
            ||s[i].find("CP")==0||s[i].find("CM")==0||s[i].find("CPE")==0||s[i].find("CPO")==0){
                if(opc.find(s[i].substr(0,t))!=opc.end())
                mem[x++]=(opc[s[i].substr(0,t)]);
                mem[x++]=static_cast<uint8_t>(std::stoul(s[i].substr(t,3), nullptr, 16));
                mem[x++]=static_cast<uint8_t>(std::stoul(s[i].substr(t+3), nullptr, 16));
            }
            else if(opc.find(s[i])!=opc.end())
            mem[x++]=(opc[s[i]]);
        }
    }
    void memory_initializer()
    {
        uint16_t adr;
        cout<<"Enter Memory Location to be initialiazed : ";
        cin>>hex>>adr;
        string ss;
        char ch;
        cout<<"Enter 8 bit Data Values and Press Esc to stop, C to Continue, and M to change Memory Location:-\n";
        do
        {
            cout<<hex<<adr<<" : ";
            cin>>ss;
            mem[adr]=static_cast<uint8_t>(std::stoul(ss, nullptr, 16));
            cin.ignore();
            cin>>ch;
            switch(ch)
            {
                case 'C':adr+=1;
                break;
                case 'M':cout<<"Enter New Memory Location : ";
                cin>>hex>>adr;
                break;
            }
        }while(ch!=27);
    }
    void memory_display()
    {
        char c;
        cout<<"Do you Want to Look into Memory?\n";
        cin>>c;
        if(c=='N')
        return;
        uint16_t adr;
        cout<<"Enter Memory Location to be Displayed : ";
        cin>>hex>>adr;
        char ch;
        cout<<"Enter 8 bit Data Values and Press Esc to stop, C to Continue, and M to change Memory Location:-\n";
        do
        {
            cout<<hex<<adr<<" : "<<std::hex << static_cast<int>(mem[adr])<<endl;
            cin>>ch;
            switch(ch)
            {
                case 'C':adr+=1;
                break;
                case 'M':cout<<"Enter New Memory Location : ";
                cin>>hex>>adr;
                break;
                default:adr+=1;
            }
        }while(ch!=27);
    }
};
#endif
