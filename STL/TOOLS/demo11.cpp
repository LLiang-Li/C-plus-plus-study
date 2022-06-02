#include"headers.h"

class Foo
{
    std::string name;
    Foo(std::string n):name(n){std::cout << this->name << '\n';}
    ~Foo(){std::cout << "DTOR" << this->name <<'\n';}

    public:
    static Foo* create_foo(std::string s)
    {
        return new Foo(std::move(s));
    }
    static void destory_foo(Foo* p){delete p;}
};

static std::shared_ptr<Foo> make_shared_foo(std::string s)
{
return {Foo::create_foo(move(s)),Foo::destory_foo};
}

static std::unique_ptr<Foo, void (*)(Foo*)> make_unique_foo(std::string s)
{
return {Foo::create_foo(move(s)), Foo::destory_foo};
}

int main11()
{
    auto ps (make_shared_foo("shared Foo instance"));
    auto pu (make_unique_foo("unique Foo instance"));
    return 0;
}