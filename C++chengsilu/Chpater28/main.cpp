#include <iostream>
#include "print_int.hpp"

int main(int, char**) {
    Mycout x = set_val(10);
    std::cout << x <<1 <<x;
    //std::cout << "Hello, world!\n";
}
