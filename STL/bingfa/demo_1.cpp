#include"Header.h"

using namespace std::literals::chrono_literals;
std::mutex mux;

void f1()
{
    
    while (1)
    {
        std::lock_guard<std::mutex> l{mux};
        std::cout << "f1 Sleep 1s" <<std::endl;
        std::this_thread::sleep_for(1s);
    }
}



void f2()
{
    std::unique_lock<std::mutex> l{mux};

    int i = 10;
    while (i >= 0)
    {
        
        std::cout <<"f2"<<std::endl;
        //l.unlock();l.lock();
        i--;
    }
    while (1)
    {
        /* code */
    }
    
    

}

int main1_()
{
    std::thread l1{f1};
    std::thread l2{f2};

    l1.join();
    l2.join();

    return 0;

}