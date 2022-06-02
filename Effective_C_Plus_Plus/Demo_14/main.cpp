#include <iostream>
#include <thread>
#include <memory>
#include <mutex>
#include <vector>

std::mutex cre_mutex;

template <typename T>
struct pcout
{
    void operator<<(T val)
    {
        cre_mutex.lock();
        std::cout << val;
        cre_mutex.unlock();
    };
};

std::ostream& operator<<(std::ostream &os, std::vector<int> val)
{
    for(auto i : val)
    {
        std::cout << i;
    }
    std::cout <<std::endl;
    return os;
}


int main(int, char**) {

    auto fun1([](auto a){pcout<std::vector<int>>{} <<a;});

    std::vector<int> a{1,2,3,4,5,6,7,8,9,0,11,12,13,14};
    std::vector<int> a2{1,2,3,4,5,6,7,8,9,0,11,12,13,14};

    std::thread t1{fun1,a};
    std::thread t2{fun1,a2};

    t1.join();
    t2.join();
    
    std::cout <<"Main\n";

    return 0;
    
}
