#include <iostream>
#include "Picture.h"

int main()
{
    char *init[] = {"Pairs", "in the", "Spring"};
    Picture p(init, 3);
    std::cout << p<<std::endl;
    Picture q = frame(p);
    std::cout << q<<'\n';
    std::cout << (p|q)<<'\n';
    std::cout << (p&q)<<'\n';
    std::cout << ((p|q)|(p&q))<<'\n';
    return 0;
}