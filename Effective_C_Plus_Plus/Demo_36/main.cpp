#include <iostream>

class base
{
    public :
        virtual void b(){std::cout << "Base\n";};
};

class sub: public base
{
    public:
        
        void b(){std::cout <<"Sub\n";}
};

int main(int, char**) {
    std::cout << "Hello, world!\n";
    base b;
    sub s;
    base * S = &s;
    S->b();
    s.b();
}
