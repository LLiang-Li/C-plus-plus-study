#include <iostream>
using lref = int&;
using rref = int&&;
using namespace std::string_literals;

template<typename Ty>
constexpr Ty && forward(Ty & Arg) noexcept {
   return static_cast<Ty&&>(Arg);
}

int n;
lref&  r1 = n; // r1 的类型是 int&
lref&& r2 = n; // r2 的类型是 int&
rref&  r3 = n; // r3 的类型是 int&
rref&& r4 = 1; // r4 的类型是 int&&
int main(int argc, char** argv){
  int a = 0;
  ::forward<int>(a);
  ::forward<int&>(a);
  ::forward<int&&>(a);
  std::cout << typeid(int).name() << std::endl;
  return 0;
}