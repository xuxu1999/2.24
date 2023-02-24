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

#endif
