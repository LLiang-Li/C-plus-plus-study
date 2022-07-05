#include <iostream>
#include <string>

void printDouble(const double & val)
{
    std::cout << val << '\n'; 
}

void printdouble(const double * val)
{
    if (val != NULL)
        std::cout << *val<< '\n';  
}

int main(int, char**) {
    char *pc= 0;
    char & rc = *pc;

    printDouble(2.34);
    double a = 10.2;
    printdouble(&a);
}
