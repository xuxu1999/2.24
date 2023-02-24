#include"Comlex.h"
#include<iostream>
using namespace std;
Complex::Complex(double r, double i)
{
    re = r;
    im = i;
}
Complex::Complex(const Complex &c)
{
    re = c.re;
    im = c.im;
}

Complex &Complex::operator+=(const Complex &c)
{
    re += c.re;
    im += c.im;
    return *this;
}

Complex &Complex::operator-=(const Complex &c)
{
    re -= c.re;
    im -= c.im;
    return *this;
}
void Complex::print(const Complex &c)
{
    cout << c.re << "+" << c.im << endl;
}

//ostream *Complex::operator<<(const Complex &c)
{
    cout << c.re << "+" << c.im << endl;
}