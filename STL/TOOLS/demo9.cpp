#include"headers.h"

class Foo
{
    public:
        std::string name;
        Foo(std::string n):name(std::move(n))
        {
            std::cout << "CTOR:" << this->name <<'\n';
        };
        ~Foo()
        {
            std::cout << "DTOR" << this->name << '\n';
        };
};

void f(std::shared_ptr<Foo> sp)
{
    std::cout << "f:f: use counter at "<< sp.use_count() <<std::endl;
}

int main9()
{

    std::shared_ptr<Foo> fa;

    {
        std::cout << "Inner scope begin\n";
        std::shared_ptr<Foo> f1{new Foo{"foo"}};
        auto f2(std::make_shared<Foo>("bar"));

        std::cout << "f1's use couter at" << f1.use_count() << std::endl;
        fa = f1;
        std::cout << "f1's use couter at" << f1.use_count() << std::endl;
    }

    std::cout << "Back to outer scope\n";

    std::cout << "first f() call\n";
    f(fa);
    std::cout << "second f() call\n";
    f(std::move(fa));

    std::cout << "end of main()\n";
    
    return 0;
}