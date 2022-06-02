#include <iostream>

class base{
    public:
        base()
        {
            std::cout<<"base()\n";
        }
        virtual ~base()
        {
            std::cout <<"~base()\n";
        }
};

class child:public base{
    public:
        child(){
            std::cout <<"child()\n";
        }
        ~child()
        {
            std::cout << "~child()\n";
        }
};

class clc:public child
{
    public:
        clc()
        {
            std::cout <<"clc()\n";
        }
        ~clc()
        {
            std::cout <<"~clc()\n";
        }
};

int main0(int, char**) {
    std::cout <<"-----------------------------\n";
    base* cl = new clc;
    base a[10];
    delete cl;
    //std::cout << "Hello, world!\n";
    return 0;
}
