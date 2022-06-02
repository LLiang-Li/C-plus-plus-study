#include"headers.h"


class Foo
{
    public:
    int value;

    Foo(int i):value(i){};
    ~Foo(){std::cout << "DTOR FOO :" << this->value << '\n';}
};

void weak_ptr_info(const std::weak_ptr<Foo> &p)
{
    std::cout << "-------------"<<std::boolalpha
    << "\nexpired: " << p.expired()
    << "\nuse_count: " << p.use_count()
    << "\ncontent: ";

    if(const auto sp(p.lock()); sp)
    {
        std::cout << sp->value <<'\n';
    }
    else
    {
        std::cout <<"<null>" <<std::endl;
    }

}

int main10()
{

    std::weak_ptr<Foo> weak_foo;
    weak_ptr_info(weak_foo);

    {
        auto shared_foo (std::make_shared<Foo>(1337));
        weak_foo = shared_foo;
        weak_ptr_info(weak_foo);
    }
    weak_ptr_info(weak_foo);
    return 0;
}