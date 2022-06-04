#include <iostream>

class base
{
    public:
        virtual ~base(){};
        virtual void a() = 0;
};

class child: public base{
    public:
        child(){}
        ~child(){}
        void a(){std::cout << "a\n";}
};

class A
{
    
};

base & operator << (base &w, const A & v)
{
    w.a();
    return w;
}


int main(int, char**) {
    A b;
    child c;
    c << b;
}
