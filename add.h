#ifndef addressing
#define addressing
#include<iostream>
using namespace std;
#include<string>

class add
{
    public:
    static int count(string s)
    {
        size_t start_pos = s.find_first_of("0123456789");
        if (start_pos == string::npos) 
        return 1;
        int x=s.length()-start_pos;
        return (x==2?2:3);
    }
};

#endif