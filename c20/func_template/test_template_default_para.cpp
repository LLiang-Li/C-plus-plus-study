#include <iostream>
#include <string>

using namespace std::string_literals;

template<typename T1,typename T2,typename RT =
    decltype(true ? T1{} : T2{}) >

RT max(const T1& a, const T2& b) { // RT ÊÇ std::string
    return a > b ? a : b;
}

template<typename T,typename T2>
auto max1(const T& a, const T2& b) -> decltype(true ? a : b){
    return a > b ? a : b;
}

decltype(auto) max2(const auto& a, const auto& b)  {
    return a > b ? a : b;
}

int main(int argc, char** argv){
  auto ret = ::max<std::string, std::string>("1"s, "2");
  std::cout << ret << std::endl;
  auto ret1 = ::max1(std::string("1"), "2");
  std::cout << ret1 << std::endl;
  auto ret2 = ::max2(std::string("1"), "2");
  std::cout << ret2 << std::endl;

  return 0;
}