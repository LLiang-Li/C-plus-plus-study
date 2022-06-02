#include"Header.h"

std::once_flag callflag;

static void once_print()
{
    std::cout << '!';
}

static void print(size_t x)
{
    std::call_once(callflag, once_print);
    std::cout << x;
}

int mai7n()
{

    std::vector<std::thread> v;

    for (size_t i = 0; i < 10; ++i){ v.emplace_back(print, i);}

    for (auto &i : v)
    {
        i.join();
    }

    std::cout <<'\n';
    return 0;
}