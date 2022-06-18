#pragma once
#include <iostream>

class Duck
{
    public:
        virtual void quack() = 0;
        virtual void fly() = 0;
        virtual ~Duck(){}
};

class Turkey
{
    public:
        virtual void gobble() = 0;
        virtual void fly() = 0;\
        virtual ~Turkey(){}
};

class MallarDuck: public Duck
{
    public:
        void quack()
        {
            std::cout << "MallarDuck\n";
        }
        void fly()
        {
            std::cout << "MallarDuck fly\n";
        }
        ~MallarDuck()
        {
            std::cout << "~MallarDuck\n";
        }
};

class WildTurke: public Turkey
{
    void gobble()
    {
        std::cout << "WildTurke\n";
    }
    void fly()
    {
        std::cout << "WildTurke fly\n";
    }
    ~WildTurke()
    {
        std::cout << "~WildTurke\n";
    }
};

class TurkeyAdapter: public Duck
{
    public:
        TurkeyAdapter(Turkey* t): tur(t) {}
        void quack()
        {
            this->tur->gobble();
        }
        void fly()
        {
            this->tur->fly();
        }
        ~TurkeyAdapter(){
            std::cout << "~TurkeyAdapter\n";
            if (this->tur)
                delete this->tur;
        }
    private:
        Turkey* tur;
};

static void testDuck(Duck * ptr)
{
    ptr->fly();
    ptr->quack();
}