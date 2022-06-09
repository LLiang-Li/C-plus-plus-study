#include "decorator.hpp"

int main(int, char**) {
    Beverage* b = new Espresso();
    b = new Mocha(b);
    std::cout << b->getDescript()<<" $:"<<b->cost()<<'\n';
    delete b;
    std::cout << "------------------\n";
    Beverage* c = new HouseBlend();
    c = new Mocha(c);
    c = new Milk(c);
    c = new Mocha(c);
    std::cout << c->getDescript()<<" $:"<<c->cost()<<'\n';
    delete c;

}
