#pragma once
#include <iostream>
#include <string>
#include <cstring>

class Pizza
{
    friend class SimplePizzaFactory;
    public:
        virtual void prepare() = 0;
        virtual void bake() = 0;
        virtual void cut() = 0;
        virtual void box() = 0;
        virtual ~Pizza(){};
};

class CheesePizza: public Pizza
{
    friend class SimplePizzaFactory;
    void prepare()
    {
        std::cout <<"CheesePizza prepare\n";
    }
    void bake()
    {
        std::cout <<"CheesePizza bake\n";
    }
    void cut()
    {
        std::cout <<"CheesePizza cut\n";
    }
    void box()
    {
        std::cout <<"CheesePizza box\n";
    }
    ~CheesePizza()
    {
        std::cout << "CheesePizza finally\n";
    }
};

class VegglePizza: public Pizza
{
    friend class SimplePizzaFactory;
    void prepare()
    {
        std::cout <<"VegglePizza prepare\n";
    }
    void bake()
    {
        std::cout <<"VegglePizza bake\n";
    }
    void cut()
    {
        std::cout <<"VegglePizza cut\n";
    }
    void box()
    {
        std::cout <<"VegglePizza box\n";
    }
    ~VegglePizza()
    {
        std::cout << "VegglePizza finally\n";
    }
};

class ClamPizza: public Pizza
{
    friend class SimplePizzaFactory;
    void prepare()
    {
        std::cout <<"ClamPizza prepare\n";
    }
    void bake()
    {
        std::cout <<"ClamPizza bake\n";
    }
    void cut()
    {
        std::cout <<"ClamPizza cut\n";
    }
    void box()
    {
        std::cout <<"ClamPizza box\n";
    }
    ~ClamPizza()
    {
        std::cout << "ClamPizza finally!\n";
    }
};

class PepperoniPizza: public Pizza
{
    friend class SimplePizzaFactory;
    void prepare()
    {
        std::cout <<"PepperoniPizza prepare\n";
    }
    void bake()
    {
        std::cout <<"PepperoniPizza bake\n";
    }
    void cut()
    {
        std::cout <<"PepperoniPizza cut\n";
    }
    void box()
    {
        std::cout <<"PepperoniPizza box\n";
    }
    ~PepperoniPizza()
    {
        std::cout << "PepperoniPizza finally\n";
    }
};

class SimplePizzaFactory
{
    friend class PizzaStore;
    SimplePizzaFactory(){};
    Pizza* createPizza(const std::string &str)
    {
        if (str == "CheesePizza")
            return new CheesePizza;
        if (str == "VegglePizza")
            return new VegglePizza;
        if (str == "ClamPizza")
            return new ClamPizza;
        if (str == "PepperoniPizza")
            return new PepperoniPizza;

        throw "Error Type";
    }
    ~SimplePizzaFactory()
    {
        std::cout << "SimplePizzaFactory delete!\n";
    }

};

class PizzaStore
{
    public:
        PizzaStore():factory(new SimplePizzaFactory), obj(0) {}
        PizzaStore(Pizza* p):factory(0),obj(p) {}
        void orderPizza(const std::string & str)
        {
            try 
            {
                this->obj = this->factory->createPizza(str);
                this->obj->prepare();
                this->obj->bake();
                this->obj->cut();
                this->obj->box();
            }
            catch(char const *str)
            {    
                std::cout << str<<'\n';
                if(this->obj)
                {
                    this->obj->~Pizza();
                    this->obj = 0;
                }
            }
            
        }
        ~PizzaStore()
        {
            if(this->factory)
                this->factory->~SimplePizzaFactory();

            if(this->obj)
                this->obj->~Pizza();
        }

    private:
        SimplePizzaFactory* factory;
        Pizza* obj;
};

