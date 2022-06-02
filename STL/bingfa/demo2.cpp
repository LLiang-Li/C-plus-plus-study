
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

using namespace std::literals::chrono_literals;

int main2()
{
    std::cout << "Go to sleep for 5 second" "and 300 million second. \n";
    
    std::this_thread::sleep_for(5s + 300ms);
    std::cout << "Going to sleep for another 3 seconds.\n";
    std::this_thread::sleep_until(std::chrono::high_resolution_clock::now() + 3s);

    std::cout << "That's it.\n";

    return 0;
}