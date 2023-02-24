#ifndef STRING_H_
#define STRING_H_
#include<string>
// String 类的实现
class String
{
private:
    /* data */
    char *m_str;

public:
    // String(/* args */);
    // 构造
    String(const char *str = 0);
    //拷贝构造
    String(const String &str);
    //拷贝赋值
    String &operator=(const String &str);
    char *getCstr() const;
    ~String();
};

String::String(const char *str)
{
    //动态分配内存
    if(str){
        m_str = new char[strlen(str) + 1];
        strcpy(m_str, str);
    }else{//空串
        m_str = new char[1];
        *m_str = '\0';
    }
}
String::String(const String& str){
    m_str = new char[strlen(str.m_str) + 1];
    strcpy(m_str, str.m_str);
}

String& String::operator=(const String& str){
    if(this==&str){
        return *this;
    }
    delete[] m_str;
    m_str = new char[strlen(str.m_str) + 1];
    strcpy(m_str, str.m_str);
    return *this;
}
char * String::getCstr() const{
    return m_str;
}

String::~String()
{
    delete[] m_str;
}

#endif