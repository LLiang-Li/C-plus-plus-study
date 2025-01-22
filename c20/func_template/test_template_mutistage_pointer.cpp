#include <iostream>
#include <thread>

template<typename T>
using AddPointer = T*;

template<typename T, size_t Size>
struct SuperPointer: SuperPointer<AddPointer<T>, Size - 1> {};

template<typename T>
struct SuperPointer<T, 0> {using type = T;};


int main(int, char**){
    SuperPointer<int, 3>::type s;

    int*p = new int(10);
    int **p1 = &p;
    s = &p1;

    std::cout << ***s <<std::endl;
    delete p;
    return 0;
}