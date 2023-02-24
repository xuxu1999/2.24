//
// Created by xuxu on 2023/2/23.
//

#pragma once

#include <iostream>
#include <string>

using namespace std;

class Date
{

public:
    Date();

    Date(int year, int month, int day);
    //~Date();

    string getCurrentDate();

    string FormatDate() const;

protected:
    virtual bool isLeapYear();

    virtual bool isLegalDate();

protected:
    int m_year;
    int m_month;
    int m_day;
};

class PreviousDate:public Date
{
public:
    virtual string getPreviousDate();
};

class NextDate:public Date
{
public:
    virtual string getNextDate() ;
};
