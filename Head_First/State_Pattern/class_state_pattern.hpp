#pragma once
#include <iostream>
#include <string>

class GumballMachine;

class State
{
    public:
        ~State(){}
        virtual void insertQuarter() = 0;
        virtual void ejectQuarter() = 0;
        virtual void turnCrank() = 0;
        virtual void dispense() = 0;
        virtual operator std::string() = 0;
};

class HasQuarterState: public State
{
    GumballMachine* gumballMachine;
    public:
        HasQuarterState(GumballMachine*);
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
        operator std::string()
        {
            return "waiting for turn of crank\n";
        }
};

class NoQuarterState: public State
{
    GumballMachine* gumballMachine;
    public:
        NoQuarterState(GumballMachine*);
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
        operator std::string()
        {
            return "waiting for quarter\n";
        }
};

class SoldOutState: public State
{
    GumballMachine* gumballMachine;
    public:
        SoldOutState(GumballMachine*);
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
        operator std::string()
        {
            return "sold out\n";
        }
};

class SoldState:public State
{
    GumballMachine* gumballMachine;
    public:
        SoldState(GumballMachine*);
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
        operator std::string()
        {
            return "dispensing a gumball\n";
        }
};

class GumballMachine 
{
	State* soldOutState;
	State* noQuarterState;
	State* hasQuarterState;
	State* soldState;
    State* state;
    int count;

    public:
        GumballMachine(int);
        ~GumballMachine();
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void setState(State* state);
        void releaseBall();
        int getCount();
        void refill(int count);
        State* getState();
        State* getSoldOutState();
        State* getNoQuarterState();
        State* getHasQuarterState();
        State* getSoldState();
        operator std::string();
};

/***************************
***
****************************/
HasQuarterState::HasQuarterState(GumballMachine* g): gumballMachine(g){}

void HasQuarterState::insertQuarter()
{
    std::cout << "You can't insert another quarter\n";
}

void HasQuarterState::ejectQuarter()
{
    std::cout << "Quarter returned\n";
    this->gumballMachine->setState(this->gumballMachine->getNoQuarterState());
}
void HasQuarterState::turnCrank()
{
    std::cout << "You turned...\n";
    this->gumballMachine->setState(this->gumballMachine->getSoldState());
}

void HasQuarterState::dispense()
{
    std::cout << "No gumball dispensed\n";
}


NoQuarterState::NoQuarterState(GumballMachine* g):gumballMachine(g){}
void NoQuarterState::insertQuarter()
{
    std::cout << "You inserted a quarter\n";
    this->gumballMachine->setState(this->gumballMachine->getHasQuarterState());
}
void NoQuarterState::ejectQuarter()
{
    std::cout << "You haven't inserted a quarter\n";
}
void NoQuarterState::turnCrank()
{
    std::cout << "You turned, but there's no quarter\n";
}
void NoQuarterState::dispense()
{
    std::cout << "You need to pay first\n";
}

SoldOutState::SoldOutState(GumballMachine* g):gumballMachine(g) {}
void SoldOutState::insertQuarter()
{
    std::cout << "You can't insert a quarter, the machine is sold out\n";
}
void SoldOutState::ejectQuarter()
{
    std::cout << "You can't eject, you haven't inserted a quarter yet\n";
}
void SoldOutState::turnCrank()
{
    std::cout << "You turned, but there are no gumballs\n";
}
void SoldOutState::dispense()
{   
    std::cout << "No gumball dispensed";
}


SoldState::SoldState(GumballMachine* g): gumballMachine(g) {}
void SoldState::insertQuarter()
{
    std::cout << "Please wait, we're already giving you a gumball\n";
}
void SoldState::ejectQuarter()
{
    std::cout << "Sorry, you already turned the crank\n";
}
void SoldState::turnCrank()
{
    std::cout << "Turning twice doesn't get you another gumball!\n";
}
void SoldState::dispense()
{
    this->gumballMachine->releaseBall();
    if(this->gumballMachine->getCount() > 0)
    {
        this->gumballMachine->setState(this->gumballMachine->getNoQuarterState());
    }
    else
    {
        std::cout << "Oops, out of gumballs!";
        this->gumballMachine->setState(this->gumballMachine->getSoldOutState());
    }
}


/***********************/
GumballMachine::GumballMachine(int c): soldOutState(new SoldOutState(this)),
                                       noQuarterState(new NoQuarterState(this)),
                                       hasQuarterState(new HasQuarterState(this)),
                                       soldState(new SoldState(this)),
                                       count(c),
                                       state(soldOutState)
{
    
    if(c > 0)
        this->state = noQuarterState;
}
void GumballMachine::insertQuarter()
{
    this->state->insertQuarter();
}

void GumballMachine::ejectQuarter()
{
    this->state->ejectQuarter();
}
void GumballMachine::turnCrank()
{
    this->state->turnCrank();
    this->state->dispense();
}
void GumballMachine::setState(State* stat)
{
    this->state = stat;
}
void GumballMachine::releaseBall()
{
    std::cout << "A gumball comes rolling out the slot...\n";
    if (this->count != 0) {
			count--;
	}
}
int GumballMachine::getCount()
{
    return this->count;
}
void GumballMachine::refill(int Count)
{
    this->count = Count;
    this->setState(this->noQuarterState);
}
State* GumballMachine::getState()
{
    return this->state;
}
State* GumballMachine::getSoldOutState()
{
    return this->soldOutState;
}
State* GumballMachine::getNoQuarterState()
{
    return this->noQuarterState;
}
State* GumballMachine::getHasQuarterState()
{
    return this->hasQuarterState;
}
State* GumballMachine::getSoldState()
{
    return this->soldState;
}
GumballMachine::operator std::string()
{
    std::string s("\nMighty Gumball, Inc.");
    s += "\nC++-enabled Standing Gumball Model #2004\n";
    s = s + "Inventory: " + std::to_string(this->count) + " gumball";
    if (this->count != 1) {
        s += "s";
    }
    s += "\nMachine is ";
    s += std::string(*this->state);
    s += "\n";
    return s;
}

GumballMachine::~GumballMachine()
{
    delete this->hasQuarterState;
    delete this->noQuarterState;
    delete this->soldOutState;
    delete this->soldState;
}