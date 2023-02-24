#include<iostream>
#include"IConfig.h"
using namespace std;
//多态，多种形态
/* Date *getInterface(int nType)
{
    Date *pDate = nullptr;
    if (nType == 1)
    {
        pDate = new NextDate();
    }
    else
    {
        pDate = new PreviousDate();
    }
    return pDate;
} */
int main()
{
    
    
    PreviousDay d(2023, 2, 23);
    
    cout<< d.GetResult();
    return 0;
}