#include <iostream>

template<typename...Args>
void print(const Args&...args){
   int _[]{ (std::cout << args << ' ' ,0)... };
}

template<typename...Args>
void print1(const Args&...args) {
    ((std::cout << args << ' '), ...);
}

template<typename...Args>
void print2(const Args&...args) {
    (...,(std::cout << args << ' '));
}

template<typename... Args>
void print3(Args&&... args){
    (std::cout << ... << args) << '\n';
}


template<int...I>
constexpr int v_right = (I - ...);  // 一元右折叠

template<int...I>
constexpr int v_left = (... - I);   // 一元左折叠

int main(int argc, char** argv){
  print("luse", 1, 1.2);
  std::cout << std::endl;
  print1("luse", 1, 1.2);
  std::cout << std::endl;
  print2("luse", 1, 1.2);
  std::cout << std::endl;
  print3("luse", 1, 1.2); // luse11.2
  std::cout << std::endl;
  std::cout << v_right<4, 5, 6> << '\n';  //(4-(5-6)) 5
  std::cout << v_left<4, 5, 6> << '\n';   //((4-5)-6) -7
  return 0;
}