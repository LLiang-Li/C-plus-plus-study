#include <iostream>
#include<string>

std::string s1(auto &&str)
{
    return std::string("123");
}

std::string s2(auto &&str)
{
    return std::string("123");
}



int main0(int, char**) {
    std::cout << "Hello, world!\n";

    std::string ss{"123"};
    s2(s1("SS"));

    return 0;
}
