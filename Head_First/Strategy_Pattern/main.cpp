#include <iostream>
#include "duck_class.hpp"

class MallarDuck: public Duck
{
    public:
        MallarDuck():Duck(new FlyWithWings, new Quack){}
        void display()
        {
            std::cout << "I'am a Maller Duck!\n";
        }
};


int main(int, char**) {
    MallarDuck * md = new MallarDuck;
    md->display();
    md->performFly();
    md->swim();
    md->performQuack();
    md->setFly(new FlyNoway);
    md->setQuack(new Squrak);
    md->performFly();
    md->performQuack();
    delete md;

}
