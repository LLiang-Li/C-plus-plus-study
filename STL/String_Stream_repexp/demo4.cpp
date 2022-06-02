#include<iostream>
#include<string>
#include<iterator>

int main4()
{
    std::string ss{"01234567"};
    std::cout << std::string(std::begin(ss),std::end(ss));
    return 0;
}