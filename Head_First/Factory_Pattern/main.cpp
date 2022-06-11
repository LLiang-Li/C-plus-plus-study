#include "Abstract_factory.hpp"

class base
{
    public: 
    base()
    {
        std::cout << "base()\n";
    }
    virtual ~base()
    {
        std::cout << "~base()\n";
    }
};

class child:public base{
    public:
        child()
        {
            std::cout << "child()\n";
        }
        ~child()
        {
            std::cout << "~child()\n";
        }
};

int main(int, char**) {

    //child chi;


    /*
    * Factory.hpp
    */
    // PizzaStore a;
    // a.orderPizza("CheesePizza");
    // a.orderPizza("");

    /*
    *Abstract_factory.hpp
    */
    NYPizzaStore ab;
    ab.orderPizza("CheesePizza");
    ab.orderPizza("VegglePizza");
    ab.orderPizza("ClamPizza");
    ab.orderPizza("PepperoniPizza");
    ab.orderPizza("");

    std::cout << "----------------------------\n";

    NYPizzaStore* abs = new NYPizzaStore;
    abs->orderPizza("CheesePizza");
    abs->orderPizza(" ");
    delete abs;
    std::cout << "----------------------------\n";
    NYPizzaStore{}.orderPizza("CheesePizza");
    NYPizzaStore{}.orderPizza("VegglePizza");
    NYPizzaStore{}.orderPizza("CheeePizza");
     std::cout << "----------------------------\n";
}
