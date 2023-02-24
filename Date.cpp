//
// Created by xuxu on 2023/2/23.
//

#include "Date.h"
#include <iostream>
#include <time.h>

Date::Date(int year, int month, int day)
{
    this->m_year = year;
    this->m_month = month;
    this->m_day = day;
    if (!isLegalDate())
    {
        cerr << "日期不合法" << endl;
    }
}

string Date::getCurrentDate()
{
    tm *t = localtime(reinterpret_cast<const time_t *>(time(nullptr)));
    this->m_year = t->tm_year + 1900;
    this->m_month = t->tm_mon + 1;
    this->m_day = t->tm_mday;
    char szDate[32];
    sprintf_s(szDate, "%d年%d月%d日", m_year, m_month, m_day);
    return szDate;
}

string Date::FormatDate() const
{
    char szDate[32];
    sprintf_s(szDate, "%d年%d月%d日", m_year, m_month, m_day);
    return szDate;
}

bool Date::isLeapYear()
{
    if ((this->m_year % 4 == 0 && this->m_year % 100 != 0) || (this->m_year % 400 == 0))
    {
        return true;
    }
    return false;
}

bool Date::isLegalDate()
{
    int dateArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (this->m_year <= 0 || this->m_month <= 0 || this->m_day <= 0)
    {
        return false;
    }
    if (this->m_month > 12 || this->m_day > 31)
    {
        return false;
    }
    if (this->isLeapYear())
    {
        dateArray[1] = 29;
        if (this->m_day > dateArray[this->m_month - 1])
        {
            return false;
        }
    }
    if (this->m_day > dateArray[this->m_month - 1])
    {
        return false;
    }
    return true;
}


string PreviousDate::getPreviousDate(){
    if(isLegalDate()){
        if(isLeapYear()){
            int dateArray[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if(this->m_month==1){
                this->m_year--;
                this->m_month = 12;
                this->m_day = 31;
                char szDate[20];
                sprintf_s(szDate, "%d年%d月%d日\n", m_year, m_month, m_day);
                return szDate;
            }
            if(this->m_day==1){
                this->m_day = dateArray[this->m_month - 2];
                char szDate[20];
                sprintf_s(szDate, "%d年%d月%d日\n", m_year, m_month, m_day);
                return szDate;
            }
        }else{
            int dateArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (this->m_month == 1)
            {
                this->m_year--;
                this->m_month = 12;
                this->m_day = 31;
                char szDate[20];
                sprintf_s(szDate, "%d年%d月%d日\n", m_year, m_month, m_day);
                return szDate;
            }
            if (this->m_day == 1)
            {
                this->m_day = dateArray[this->m_month - 1 - 1];
                char szDate[20];
                sprintf_s(szDate, "%d年%d月%d日\n", m_year, m_month, m_day);
                return szDate;
            }
        }
        

    }
    return;
}



string NextDate::getNextDate(){
    if (isLegalDate())
    {
        if (isLeapYear())
        {
            int dateArray[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (this->m_month==12 && this->m_day==31)//12.31
            {
                this->m_year++;
                this->m_month = 1;
                this->m_day = 31;
                char szDate[20];
                sprintf_s(szDate, "%d年%d月%d日\n", m_year, m_month, m_day);
                return szDate;
            }
            if (this->m_day == dateArray[m_month-1])
            {
                this->m_month++;
                char szDate[20];
                sprintf_s(szDate, "%d年%d月%d日\n", m_year, m_month, m_day);
                return szDate;
            }
        }
        else
        {
            int dateArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (this->m_month == 12 && this->m_day == 31) // 12.31
            {
                this->m_year++;
                this->m_month = 1;
                this->m_day = 31;
                char szDate[20];
                sprintf_s(szDate, "%d年%d月%d日\n", m_year, m_month, m_day);
                return szDate;
            }
            if (this->m_day == dateArray[m_month - 1])
            {
                this->m_month++;
                char szDate[20];
                sprintf_s(szDate, "%d年%d月%d日\n", m_year, m_month, m_day);
                return szDate;
            }
        }
    }
    return;
}