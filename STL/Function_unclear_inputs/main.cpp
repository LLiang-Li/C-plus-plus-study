#include <iostream>

template<typename ... Ts>
auto sum(Ts ... ts)
{
    return (ts + ...);
};


int main(int num, char** str ) {
    std::cout << sum(1,2,3,4,5);
    return 0;
}
