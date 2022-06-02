#include<iostream>
#include<map>
#include<iterator>
#include<string>

template<typename T>
struct ls{
    std::map<T, ls> L;
};

int main2()
{
    std::map<int,int> a{std::pair<int,int>(1,1)};
    
    return 0;
}