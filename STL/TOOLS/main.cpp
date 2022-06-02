//#include"Headers/headers.h"
#include"headers.h"

struct Foo_ {
int value;
Foo_(int i) : value{i} {}
~Foo_() { std::cout << "DTOR Foo " << value << '\n'; }
};


int main0(int, char**) {
    std::cout << "Hello, world!\n";

    Foo_ * f = new Foo_(1);
    std::cout << f->value;
    delete f;
    return 0;
}
