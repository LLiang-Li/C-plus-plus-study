#include "Compound.hpp"

int main(int, char**) {
#ifndef _A
    // /****
    //  * 
    //  * 
    //  * ***/
    CounterDuckFacroy* fac = new CounterDuckFacroy;
    Quackbale* mallduck = fac->createMallardDuck();
    Quackbale* redduck = fac->createRedheadDuck();
    Quackbale* duckcall = fac->createDuckCall();
    Quackbale* rubbduck = fac->createRubberdDuck();
    Quackbale* gooseduck =new GooseAdapter(new Goose);

    mallduck->quack();
    redduck->quack();
    duckcall->quack();
    rubbduck->quack();
    gooseduck->quack();
    std::cout << QucakCounter::getQuacks() ;

    delete fac;
    delete mallduck;
    delete redduck;
    delete duckcall;
    delete rubbduck;
    delete gooseduck;

#else
    MallardDuck_ob* mallrarduck = new MallardDuck_ob;
    MallardDuck_ob* mallrarduck1 = new MallardDuck_ob;
    Quackologist* ob1 = new Quackologist("Ob1");
    Quackologist* ob2 = new Quackologist("Ob2");
    mallrarduck->resisterObserver(ob1);
    mallrarduck->resisterObserver(ob2);
    mallrarduck1->resisterObserver(ob2);
    mallrarduck->quack();
    mallrarduck1->quack();
    delete mallrarduck;
    delete mallrarduck1;
    delete ob1;
    delete ob2;
#endif

}
