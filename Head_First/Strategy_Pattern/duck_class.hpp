#ifndef _DUCK_CLASS_
#define _DUCK_CLASS_

#include <iostream>

class FlyBehavior
{
    public:
        virtual void fly() = 0;
};

class QuackBehavior
{
    public:
        virtual void quack() = 0;
};

class Duck
{
    public:
        Duck(FlyBehavior* f, QuackBehavior* q): flyBehavior(f), quackBehavior(q){}
        void swim()
        {   
            std::cout << "Swimming\n";
        }

        virtual void display() = 0;

        void performQuack()
        {
            quackBehavior->quack();
        }

        void performFly()
        {
            flyBehavior->fly();
        }

        void setFly(FlyBehavior* f)
        {
            if(this->flyBehavior)
                delete this->flyBehavior;
            this->flyBehavior = f;
        }

        void setQuack(QuackBehavior* f)
        {
            if(this->quackBehavior)
                delete this->quackBehavior;
            this->quackBehavior = f;
        }
        
        virtual ~Duck()
        {
            if (flyBehavior)
                delete flyBehavior;
            if (quackBehavior)
                delete quackBehavior;
        }

    private:
        FlyBehavior* flyBehavior;
        QuackBehavior* quackBehavior;
};

class FlyWithWings: public FlyBehavior
{
    public:
        void fly()
        {
            std::cout <<"fly\n";
        }   
};

class FlyNoway: public FlyBehavior
{
    public:
        void fly()
        {
            std::cout <<"Can't fly\n";
        }
};

class Quack: public QuackBehavior
{
    public:
        void quack()
        {
            std::cout<<"gaugua\n";
        }
};

class Squrak: public QuackBehavior
{
    public:
        void quack()
        {
            std::cout<<"zhizhijiao\n";
        }
};

class MuteQuack: public QuackBehavior
{
    public:
        void quack()
        {
            std::cout<<" \n";
        }
};

#endif