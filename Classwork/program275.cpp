#include<iostream>
using namespace std;

template<class T, class W>
void CountFrequency(T No1, W No2)
{
    cout<<No1;
    cout<<No2;
}

int main()
{
    int iValue = 10;
    float fValue = 1.11;

    CountFrequency(iValue, fValue);
    
    return 0;
}