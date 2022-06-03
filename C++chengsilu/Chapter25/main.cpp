#include <iostream>
#include "STRING.hpp"
class fack
{
    public:
        fack(int a):x(a){}
        fack& operator=(int &va)
        {
            va = this->x;
            return *this;
        }
    private:
        int x;
};

int main(int, char**) {
    // int y = 0;
    // fack x(10);
    // std::cout << y <<'\n';
    // x = y;
    // std::cout << y <<'\n';  

    String s("Hello world!");
    String s1("Hello world!");
    s = s1;
    std::cout << s  << '\n';   
    std::cout << s1 << '\n';  
    std::cout << s+s1; 
    std::cin >> s;
    std::cout <<s;
}
