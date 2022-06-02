#include <iostream>
#include <typeinfo>
#include<vector>
#include<string>

class MyIterator
{
    int i;
public:
    MyIterator(int num):i(num){};
    int operator*()
    {
        return i;
    };
    MyIterator& operator++()
    {
        i++;
        return *this;
    };
    bool operator!=(MyIterator & in)
    {
        return (in.i != i);
    };
};

class Myclass
{
    int first;
    int second;
    public:
    Myclass(int fir, int sec):first(fir),second(sec){};
    MyIterator begin(){
        return MyIterator(first);
    };
    MyIterator end(){
        return MyIterator(second);
    };
};

int main(int, char**) {

    // Myclass data{1,4};   
    // for(auto index:data)
    // {
    //     std::cout << index << "\n";
    // }

    MyIterator ind{1};
    std::cout << (*ind) << std::endl;//<<std::end;
    std::cout << (*(++++ind)) <<std::endl;

    std::cout<< (*ind)<<std::endl;
    return 0;
}
