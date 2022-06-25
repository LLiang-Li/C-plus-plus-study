#define Part false

#if Part
#include "state_pattern.hpp"
#else
#include "class_state_pattern.hpp"
#endif

int main(int, char**) {
    #if Part
    /******************************
    *#include "state_pattern.hpp"
    *
    ******************************/
    GumballMachine* s = new GumballMachine(5);
    std::cout << std::string(*s);
    s->insertQuarter();
    s->turnCrank();
    std::cout << std::string(*s);
    std::cout << "--------------------------------\n";
    delete s;
    #else
    /******************************
    *#include "class_state_pattern.hpp"
    *
    ******************************/

    GumballMachine* gumballMachine = new GumballMachine(5);

    std::cout << std::string(*gumballMachine);

    std::cout << "-------------------\n";
    gumballMachine->insertQuarter();
	gumballMachine->turnCrank();
    std::cout << std::string(*gumballMachine);
    std::cout << "-------------------\n";
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    std::cout << std::string(*gumballMachine);
    delete gumballMachine;
    #endif
}
