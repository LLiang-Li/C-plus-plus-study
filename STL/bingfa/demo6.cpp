#include"Header.h"

struct  pcout : public std::stringstream
{
    static inline std::mutex cout_mutex;
    ~pcout(){
        std::lock_guard<std::mutex> l{cout_mutex};
        std::cout << std::stringstream::rdbuf();
        std::cout.flush();
    };
};

static void print_cout(int id)
{
    std::cout << "cout hello from " << id << '\n';
}
static void print_pcout(int id)
{
    pcout{} << "pcout hello from " << id << '\n';
}



int main6()
{

    std::vector<std::thread> v;

    for (auto i = 0; i<10; i++)
    {
        v.emplace_back(print_cout, i);
    }

    for (auto& i : v)
    {
        i.join();
    }

    std::cout <<"-------------------"<<std::endl;

    v.clear();

    for (auto i = 0; i<10; i++)
    {
        v.emplace_back(print_pcout, i);
    }

    for (auto& i : v)
    {
        i.join();
    }

    return 0;
}