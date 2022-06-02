#include <iostream>

int main(int, char**) {
    int a = 10;
    int* b,*c;
    b = new int(2);
    c= b;
    std::cout << b<<'\n';
    if (b != NULL)
    {
        std::cout<<"b\n";
        delete b;
    }
    std::cout << b<<'\n';
    std::cout << c<<'\n';
    if (c != NULL)
    {
        std::cout<<"c\n";
        delete b;
    }
}
