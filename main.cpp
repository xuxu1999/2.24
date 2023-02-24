#include<iostream>
//#include<ctime>
#include"Date.h"
using namespace std;
Date *getInterface(int nType)
{
    Date *pDate = new Date();
    if(nType==1){
        pDate = new NextDate();
    }else{
        pDate = new PreviousDate();
    }
    return pDate;
}
int main()
{
    
    return 0;
}