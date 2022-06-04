#ifndef _PRINT_INT_
#define _PRINT_INT_
#include<iostream>

class Mycout
{
    public:
        Mycout(std::ostream&(*g)(std::ostream&, int), int v): f(g),val(v) {}
        
        std::ostream& operator()(std::ostream &o)const
        {
            return (*f)(o, val);
        }
        
    private:
        int val;
        std::ostream&(*f)(std::ostream&, int);       
};

std::ostream& operator<<(std::ostream &os, const Mycout im)
{
    return im(os);
}

std::ostream& set_val(std::ostream &os, int val)
{
    return os << val<<", ";
}

Mycout set_val(int val)
{
    return Mycout( (std::ostream&(*)(std::ostream&, int)) set_val, val);
}

#endif