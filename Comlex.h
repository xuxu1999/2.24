//
// Created by xuxu on 2023/2/24.
//

#ifndef COMPLEX_H
#define COMPLEX_H
// 实现复数类
#include<iostream>
class Complex
{
public:
    // 初始化
    Complex(double r, double i);
    // 拷贝构造
    Complex(const Complex &);

    Complex &operator+=(const Complex &);
    Complex &operator-=(const Complex &);
    //ostream *operator<<(const Complex &);
    void print(const Complex &);

private:
    double re, im; // 实部、虚部
};


Complex::Complex(double r, double i)
{
    re = r;
    im = i;
}
Complex::Complex(const Complex& c)
{
    re = c.re;
    im = c.im;
}

Complex& Complex::operator+=(const Complex& c)
{
    re += c.re;
    im += c.im;
    return *this;
}

Complex& Complex::operator-=(const Complex& c)
{
    re -= c.re;
    im -= c.im;
    return *this;
}
void Complex::print(const Complex& c)
{
    cout << c.re << "+" << c.im << endl;
}

ostream* Complex::operator<<(const Complex& c)
{
    cout << c.re << "+" << c.im << endl;
}
#endif
