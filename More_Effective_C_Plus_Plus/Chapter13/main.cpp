#include <iostream>
#include <exception>

void someFunction()
{
    throw std::runtime_error("123");
}

int main(int, char**) {
    try
    {
        someFunction();
    }
    catch(const std::exception e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
