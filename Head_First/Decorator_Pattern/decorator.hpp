#ifndef _DECORATOR_HPP_
#define _DECORATOR_HPP_

#include <iostream>
#include <string>

class Beverage
{
    public:
        virtual std::string getDescript() = 0;
        virtual float cost() = 0;
        virtual ~Beverage(){};
};

class Espresso: public Beverage
{
    public:
        Espresso(){}
        std::string getDescript()
        {
            return "Espresso";
        }
        float cost()
        {
            return 1.99;
        }
        ~Espresso()
        {
            std::cout <<"~Espresso()\n";
        }
};

class HouseBlend: public Beverage
{
    public:
        HouseBlend(){}
        std::string getDescript()
        {
            return "HouseBlend";
        }
        float cost()
        {
            return 0.89;
        }
        ~HouseBlend()
        {
            std::cout <<"~HouseBlend()\n";
        }
};

class DarkRoast: public Beverage
{
    public:
        DarkRoast(){}
        std::string getDescript()
        {
            return "DarkRoast";
        }
        float cost()
        {
            return 0.99;
        }
        ~DarkRoast()
        {
            std::cout <<"~DarkRoast()\n";
        }
};

class Decaf: public Beverage
{
    public:
        Decaf(){}
        std::string getDescript()
        {
            return "Decaf";
        }
        float cost()
        {
            return 1.05;
        }
        ~Decaf()
        {
            std::cout <<"~Decaf()\n";
        }
};

class CondimentDecorator: public Beverage
{
    public:
        virtual std::string getDescript() = 0;
        virtual ~CondimentDecorator(){};
};


class Mocha: public CondimentDecorator
{
    public:
        Mocha(Beverage * p)
        {
            this->beverage = p;
        }

        std::string getDescript()
        {
            return this->beverage->getDescript() + ", Mocha";
        }

        float cost()
        {
            return 0.2 + this->beverage->cost();
        }

        ~Mocha()
        {
            
            {
                std::cout << "Mocha\n";
                // std::cout <<"in\n";
                delete this->beverage;
                // std::cout << "out\n";
                // if(this->beverage)
                //     delete this->beverage;
                // std::cout << "delete\n";
            }        
        }
    private:
        Beverage * beverage;
};


class Milk: public CondimentDecorator
{
    public:
        Milk(Beverage * p)
        {
            this->beverage = p;
        }

        std::string getDescript()
        {
            return this->beverage->getDescript() + ", Milk";
        }

        float cost()
        {
            return 0.2 + this->beverage->cost();
        }

        ~Milk()
        {
            
            {
                std::cout << "Milk\n";
                // std::cout <<"in\n";
                //this->beverage->~Beverage();
                delete this->beverage;
                // std::cout << "out\n";
                //析构里面再调析构就崩了
                /*************************/
                // if(this->beverage)
                //     delete this->beverage;
                /*************************/
                // std::cout << "delete\n";
            }        
        }
    private:
        Beverage * beverage;
};
#endif