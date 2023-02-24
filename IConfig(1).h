#include <string>
class Date
{
public:
	bool Input(int year, int month, int day);
	virtual void Calculate() = 0;
	std::string GetResult() const;//理解这个const的含义
protected:
    int  m_dayArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool IsLegal(int y, int m, int d);//判断日期是否合法

private:
    bool IsLeapYear(int y);//判断闰年s

protected:
    int m_year = 0;
    int m_month = 0;
    int m_day = 0;
};

std::string Date::GetResult() const//理解这个const的含义
{
    char szDate[32];
    sprintf_s(szDate, "%d年%d月%d日", m_year, m_month, m_day);
    return szDate;
}

bool Date::Input(int year, int month, int day)
{
    if (IsLeapYear(year)) {
        m_dayArray[1] = 29;
    }
    if (!IsLegal(year, month, day)) {
        return false;
    }
    m_year = year;
    m_month = month;
    m_day = day;
    return true;
}

//年月日是否合法
bool Date::IsLegal(int y, int m, int d)
{
    if (y <= 0 || m <= 0 || d <= 0) {
        return false;
    }
    if (d > 31 || m > 12) {
        return false;
    }
    if (d > m_dayArray[m - 1]) {
        return false;
    }
    return true;
}

//是否是闰年
bool Date::IsLeapYear(int y)
{
    if (y % 4 != 0) {
        return false;
    }
    if (y % 100 == 0 && y % 400 != 0) {
        return false;
    }
    return true;
}

class NextDay : public Date
{
public:
    virtual void Calculate() override;
};

void NextDay::Calculate()
{
    if (IsLegal(m_year, m_month, m_day + 1)) {
        m_day++;
        return;
    }
    if (IsLegal(m_year, m_month + 1, 1)) {
        m_month++;
        m_day = 1;
        return;
    }
    m_year++;
    m_month = 1;
    m_day = 1;
}

class PreviousDay : public Date
{
public:
    virtual void Calculate() override;
};

void PreviousDay::Calculate()
{
    if (IsLegal(m_year, m_month, m_day - 1)) {
        m_day--;
        return;
    }

    if (m_month ==1 ) {
        m_year--;
        m_month = 12;
        m_day = 31;
        return;
    }
    m_month--;
    m_day = m_dayArray[m_month-1];
}