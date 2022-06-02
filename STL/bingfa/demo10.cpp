#include "Header.h"

using namespace std::literals::chrono_literals;

struct  pcout : public std::stringstream
{
    static inline std::mutex cout_mutex;
    ~pcout(){
        std::lock_guard<std::mutex> l{cout_mutex};
        std::cout << std::stringstream::rdbuf();
        std::cout.flush();
    };
};

std::queue<size_t> q;
std::mutex  q_mutex;

bool production_stopped {false};

std::condition_variable go_produce;
std::condition_variable go_consume;

static void produce(size_t id, size_t items, size_t stock)
{
    for (size_t i = 0; i < items; i++)
    {
        std::unique_lock<std::mutex> lock{q_mutex};
        go_produce.wait(lock, [&]{return q.size() < stock;});
        q.push(id*100 + i);
        pcout{} << " Producer " << id << " --> item "
                << std::setw(3) << q.back() << '\n';
        go_consume.notify_all();
        std::this_thread::sleep_for(90ms);   
    }
    pcout{} << "EXIT: Producer " << id << '\n';
}

static void consumer(size_t id)
{
    while ((!production_stopped || !q.empty()))
    {
        std::unique_lock<std::mutex> lock(q_mutex);
        if(go_consume.wait_for(lock, 1s, []{return !q.empty();}))
        {
            pcout{} << " item "
                    << std::setw(3) << q.front()
                    << " --> Consumer "
                    << id << '\n';
                    q.pop();
            go_produce.notify_all();
            std::this_thread::sleep_for(130ms);
        }
        
    }
    pcout{} << "EXIT: Producer " << id << '\n';
}

int main10()
{
    std::vector<std::thread> workers;
    std::vector<std::thread> consumers;

    for (size_t i = 0; i < 3; ++i) {
        workers.emplace_back(produce, i, 15, 5);
    }
    for (size_t i = 0; i < 5; ++i) {
        consumers.emplace_back(consumer, i);
    }
    for (auto &t : workers) { t.join(); }
    production_stopped = true;
    for (auto &t : consumers) { t.join(); }


    return 0;
}