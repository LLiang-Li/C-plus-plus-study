#include <iostream>

char * funct()
{
    return "1234";
}

int main(int, char**) {
    
    char a[]="12345";
    char *b;
    b= "12345";
    std::cout <<a<<'\n'<<b<<std::endl;
    std::cout <<&(a[0])<<'\n'<<&(b[0])<<std::endl;

    char *c;
    c = funct();
    std::cout <<c<<std::endl;
    std::cout <<c<<std::endl;
    std::cout <<c<<std::endl;
    std::cout <<c<<std::endl;
    std::cout <<c<<std::endl;
    std::cout <<c<<std::endl;
    std::cout <<c<<std::endl;

}
