#pragma once
#include <iostream>
#include <string>

class GumballMachine
{
    public:
        GumballMachine(int cou);
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
        void refill(int numGumBalls);
        operator std::string();
    private:
        int state;
        int counter;
    public:
        static const int SOLD_OUT = 0;
        static const int NO_QUATER = 1;
        static const int HAS_QUARTER = 2;
        static const int SOLD = 3;
};


GumballMachine::GumballMachine(int cou):counter(cou)
{
    if(this->counter > 0)
        this->state = NO_QUATER;
}

void GumballMachine::insertQuarter()
{
    switch (this->state)
    {
    case HAS_QUARTER:
        std::cout << "You can't insert another quarter!\n";
        break;
    case NO_QUATER:
        this->state = HAS_QUARTER;
        std::cout << "You inserted a quarter\n";
        break;
    case SOLD_OUT:
        std::cout << "You cant't insert a quarter, the machine is sold out\n";
        break;
    case SOLD:
        std::cout << "Please wait, we are already giving you a gumball\n";
        break;
    default:
        break;
    }
}

void GumballMachine::ejectQuarter()
{
    switch (this->state)
    {
    case HAS_QUARTER:
        std::cout << "Quarter returned\n";
        this->state = NO_QUATER;
        break;
    case NO_QUATER:
        std::cout << "You haven't inserted a quarter\n";
        break;
    case SOLD:
        std::cout << "Sorry, you already turned the crank\n";
        break;
    case SOLD_OUT:
        std::cout << "You can't eject, you haven't inserted a quarter yet\n";
    default:
        break;
    }
}

void GumballMachine::turnCrank()
{
    switch (this->state)
    {
    case SOLD:
        std::cout << "Turning twice doesn't get you another gumball!\n";
        break;
    case NO_QUATER:
        std::cout << "You turned but there's no quarter\n";
        break;
    case SOLD_OUT:
        std::cout << "You turned, but there are no gumballs\n";
        break;
    case HAS_QUARTER:
        std::cout << "You turned...\n";
        this->state = SOLD;
        this->dispense();
        break;    
    default:
        break;
    }
}

void GumballMachine::dispense()
{
    switch (this->state)
    {
    case SOLD:
        std::cout << "A gumball comes rolling out the slot\n";
        this->counter -= 1;
        if (this->counter == 0)
        {
            std::cout << "Oops, out of gumballs!\n";
            this->state = SOLD_OUT;
        }
        else{
            this->state = NO_QUATER;
        }
        break;
    case NO_QUATER:
        std::cout << "You need to pay first\n";
        break;
    case SOLD_OUT:
        std::cout << "No gumball dispensed\n";
        break;
    case HAS_QUARTER:
        std::cout << "No gumball dispensed\n";
        break;
    default:
        break;
    }
}

void GumballMachine::refill(int numGumBalls)
{
    this->counter = numGumBalls;
    this->state = NO_QUATER;
}

GumballMachine::operator std::string()
{
    std::string s("\nMighty Gumball, Inc.");
    s += "\nC++-enabled Standing Gumball Model #2004\n";
    s = s + "Inventory: " + std::to_string(this->counter) + " gumball";
    if (this->counter != 1) {
        s += "s";
	}
    s += "\nMachine is ";
    switch (this->state)
    {
    case SOLD_OUT:
        s += "sold out";
        break;
    case NO_QUATER:
        s += "waiting for quarter";
        break;
    case HAS_QUARTER:
        s += "waiting for turn of crank";
        break;
    case SOLD:
        s += "delivering a gumball";
        break;
    default:
        break;
    }
    s += "\n\n";
    return s;
}