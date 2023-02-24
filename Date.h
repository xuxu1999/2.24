#ifndef DATE_H
#define DATE_H
//
// Created by xuxu on 2023/2/23.
//
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
    bool isLeapYear();

    bool isLegalDate();

protected:
    int m_year;
    int m_month;
    int m_day;
};

class PreviousDate : public Date
{
public:
    //PreviousDate(){};
    PreviousDate(int year, int month, int day):m_year(year),m_month(month),m_day(day);
    string getPreviousDate();
};

class NextDate : public Date
{
public:
    //using Date::Date();
    NextDate(int year, int month, int day) : m_year(year), m_month(month), m_day(day);
    string getNextDate();
    
};
#endif