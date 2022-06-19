#include "Ada_pattern.hpp"

int main(int, char**) {
    MallarDuck* du = new MallarDuck;

    WildTurke* t = new WildTurke;

    TurkeyAdapter* ru = new TurkeyAdapter(t);

    du->fly();
    du->quack();
    
    std::cout <<"-----------------------\n";

    testDuck(ru);

    delete ru;
    delete du;
};