#include <iostream>

template<class T>
struct A{
    A(T a, T b){};
};

template<typename T>
struct Test{
    Test(T v) :t{ v } {}
private:
    T t;
};

Test(int) -> Test<std::size_t>;

template<class Ty, std::size_t size>
struct array {
    Ty arr[size];
};

template<typename T, typename ...Args>
array(T t,Args...) -> array<T, sizeof...(Args) + 1>;

template<typename T = int>
struct X {};

struct Test1{
    static inline X x3;   // gcc OK
};

template<class T, std::size_t N = 10>
struct Arr
{
    T arr[N];
};


int main(int argc, char** argv){
  Test t(1);
  ::array arr{1,2,3,4,5};
  Arr<int,20> x;
  std::cout << sizeof(x)/sizeof(int);
  return 0;
}