#ifndef _WIDGET_
#define _WIDGET_

#include <iostream>
#include <string>
#include <exception>

class Widget
{
    public:
        Widget(std::string str = "NULL"): Str(str) {}
        friend std::ostream& operator<<(std::ostream &os, const Widget &rhs);
        friend std::istream& operator>>(std::istream &os, Widget &rhs);
    private:
        std::string Str;
};

std::ostream& operator<<(std::ostream &os, const Widget &rhs)
{
    os << rhs.Str << '\n';
    return os;
}

std::istream& operator>>(std::istream &os, Widget &rhs)
{
    os >> rhs.Str;
    return os;
}
#endif