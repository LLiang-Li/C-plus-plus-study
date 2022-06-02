#include <iostream>

template<typename ...Ts>
void print(Ts&& ... t)
{
    //std::cout << (t + ...);
}

std::string s1(std::string &a)
{
    return std::string("1234");
}

std::string s(std::string &&a)
{
    return a;
}

int main(int, char**) {
    // std::cout << "Hello, world!\n";

    // print<double,int>(1,2);

    //std::cout <<s("12345")<<std::endl;
    std::string ss{"123"};
    std::cout <<s(s1(ss))<<std::endl;
    return 0;
}
