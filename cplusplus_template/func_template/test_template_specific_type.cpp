#include <iostream>

template<std::size_t N>
void f() { std::cout << N << '\n'; }

int main(int argc, char** argv){
  f<100>();
  return 0;
}