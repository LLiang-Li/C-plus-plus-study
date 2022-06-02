#include <iostream>
#include<vector>
#include<functional>

static int add(int a, int b)
{
    return (a+b);
}

constexpr int scale(int cnt){return 5*cnt;}

int main_(int, char**) 
{
    // 使用迭代器遍历元素
    // std::vector<std::vector<int>> a{{1,2,3},{3,4,5,6},{7,8,9}};
    // for(auto i : a)
    // {
    //     for (auto j:i)
    //     {
    //         std::cout << j <<" ,";
    //     }
    //     std::cout << std::endl;
    // }

    //借助funtional头文件定义函数指针

    // std::function<int(int,int)> na{add};
    // std::cout << na(1,2);

    //constxpr
    constexpr int a = 10;
    const int a1 =10;
    int b[a];
    int b1[a1];

    int d = scale(1);
    int c = 1;
    scale(c);
}
