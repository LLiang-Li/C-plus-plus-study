#include"Header.h"

using namespace std::literals::chrono_literals;

std::queue<size_t> q1;

std::mutex mut;
std::condition_variable cv;
bool finished{false};

static void produces(size_t items)
{
    for (size_t i{0}; i < items; ++i)
    {
        std::this_thread::sleep_for(100ms);
        {
            std::lock_guard<std::mutex> lk{mut};
            q1.push(i);
        }
        cv.notify_all();
    }
    {
        std::lock_guard<std::mutex> lk{mut};
        finished = true;
    }
    cv.notify_all();
}

static void consumer()
{
    while (!finished)
    {
        std::unique_lock<std::mutex> l{mut};
        
        cv.wait(l,[]{return !q1.empty()|| finished;});
        while (!q1.empty()) {
            std::cout << "Got " << q1.front()
            << " from queue.\n";
            q1.pop();
        }
    }
    
}


int main9()
{

    std::thread t1 {produces, 10};
    std::thread t2 {consumer};
    t1.join();
    t2.join();
    std::cout << "finished!\n";
    return 0;
}