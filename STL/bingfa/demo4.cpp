#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>


using namespace std::literals::chrono_literals;

std::shared_timed_mutex shared_mut;

using shrd_lck = std::shared_lock<std::shared_timed_mutex>;
using uniq_lck = std::unique_lock<std::shared_timed_mutex>;

static void print_exclusive()
{
    uniq_lck l {shared_mut, std::defer_lock};
    if (l.try_lock()) {
    std::cout << "Got exclusive lock.\n";
    } else {
    std::cout << "Unable to lock exclusively.\n";
    }
}

static void exclusive_throw()
{
    uniq_lck l {shared_mut};
    throw 123;
}


int main4()
{
    print_exclusive();
    {
        shrd_lck sl1 {shared_mut};
        std::cout << "shared lock once.\n";

        {
            shrd_lck sl2 {shared_mut};
            std::cout << "shared lock twice.\n";
            print_exclusive();
        }

        std::cout << "shared lock once again.\n";
        print_exclusive();
    }
    std::cout << "lock is free.\n";

    try {
        exclusive_throw();
        } 
    catch (int e) {
        std::cout << "Got exception " << e << '\n';
    }
        print_exclusive();


    return 0;
}