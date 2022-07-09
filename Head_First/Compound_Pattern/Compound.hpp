#pragma once
#include <iostream>
#include <vector>
#include <string>

#define NAME(str) #str

#define _A

#ifndef _A

class Quackbale
{
    public:
        virtual void quack() = 0;
        virtual ~Quackbale(){}
};

class MallardDuck: public Quackbale
{
    public:
        void quack()
        {
            std::cout << "Quack!\n";
        }
};

class RedheadDuck: public Quackbale
{
    public:
        void quack()
        {
            std::cout << "Quack!\n";
        }
};

class DuckCall: public Quackbale
{
    public:
        void quack()
        {
            std::cout << "Kwak\n";
        }
};

class RubberCall: public Quackbale
{
    public:
        void quack()
        {
            std::cout << "Squeak\n";
        }
};

class Goose
{
    public:
        void honk()
        {
            std::cout << "Honk\n";
        }
};

class GooseAdapter: public Quackbale
{
    public:
        GooseAdapter(Goose* g):goo(g) {}
        void quack()
        {
            this->goo->honk();
        }
        ~GooseAdapter()
        {
            if (goo)
                delete goo;
        }
    private:
        Goose* goo;

};

/*
*
* Decorator
*
**/

class QucakCounter: public Quackbale
{
    public:
        QucakCounter(Quackbale* duck):quac(duck) {}
        void  quack()
        {
            this->quac->quack();
            this->NumOfQuack++;
        }
        static int getQuacks()
        {
            return NumOfQuack;
        }
        ~QucakCounter()
        {
            delete this->quac;
        }
    private:
        Quackbale* quac;
        static int NumOfQuack;
};

int QucakCounter::NumOfQuack = 0;

/*
*
*Factory
*/
class AbstractDuckFactory
{
    public:
        virtual Quackbale* createMallardDuck() = 0;
        virtual Quackbale* createRedheadDuck() = 0;
        virtual Quackbale* createDuckCall() = 0;
        virtual Quackbale* createRubberdDuck() = 0;
        ~AbstractDuckFactory(){}
};

class DuckFacroy: public AbstractDuckFactory
{
    public:
        Quackbale* createMallardDuck()
        {
            return new MallardDuck;
        }
        Quackbale* createRedheadDuck()
        {
            return new RedheadDuck;
        }
        Quackbale* createDuckCall()
        {
            return new DuckCall;
        }
        Quackbale* createRubberdDuck()
        {
            return new RubberCall;
        }
};

class CounterDuckFacroy: public AbstractDuckFactory
{
    public:
        Quackbale* createMallardDuck()
        {
            return new QucakCounter(new MallardDuck);
        }
        Quackbale* createRedheadDuck()
        {
            return new QucakCounter(new RedheadDuck);
        }
        Quackbale* createDuckCall()
        {
            return new QucakCounter(new DuckCall);
        }
        Quackbale* createRubberdDuck()
        {
            return new QucakCounter(new RubberCall);
        }
};

#else
/****
 * 
 * 
 * Observe
 * 
 * ****/
class QuackObservable;

class Observer
{
    public:
        virtual void update(QuackObservable *) = 0;
        virtual ~Observer(){}
};

class Quackologist: public Observer
{
    public:
        Quackologist(std::string name):ObName(name) {}
        void update(QuackObservable * duck)
        {
            std::cout << this->ObName <<": "<< NAME(duck) << std::endl;
        }
    private:
        std::string ObName;
};

class QuackObservable
{
    public:
        virtual void resisterObserver(Observer*) = 0;
        virtual void notifyObservers() = 0;
        virtual ~QuackObservable(){}
};

class Quackable: public QuackObservable
{
    public:
        virtual ~Quackable(){}
        virtual void quack() = 0;
};

class Observable: public QuackObservable
{
    public:
        Observable(QuackObservable* d):duck(d) {}

        void resisterObserver(Observer* ob)
        {
            this->obsers.push_back(ob);
        }
        void notifyObservers()
        {
            for(auto i:this->obsers)
            {
                i->update(duck);
            }
        }
        ~Observable()
        {
            // for(auto i : this->obsers)
            //     delete i;
        }
    private:
        std::vector<Observer*> obsers;
        QuackObservable* duck;
};

class MallardDuck_ob: public Quackable
{
    public:
        MallardDuck_ob()
        {
            this->obs = new Observable(this);
        }
        void quack()
        {
            std::cout << "Quack!\n";
            notifyObservers();
        }
        void resisterObserver(Observer* ob)
        {
            this->obs->resisterObserver(ob);
        }
        void notifyObservers()
        {
            this->obs->notifyObservers();
        }
        ~MallardDuck_ob()
        {
            delete obs;
        }
    private:
        Observable* obs;
};

#endif