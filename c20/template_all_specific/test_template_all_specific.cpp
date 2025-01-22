#include<iostream>

template<typename T,typename T2>
auto f(const T& a, const T2& b)  {
    return a + b;
}

template<>
auto f/*<double, int>*/(const double& a, const int& b){
    return a - b;
}

template<typename T> // 主模板
struct is_void{
    static constexpr bool value = false;
};
template<>           // 对 T = void 的显式特化
struct is_void<void>{
    static constexpr bool value = true;
};

template<typename T>
constexpr bool is_void_v = is_void<T>::value;

template<typename T>
struct X{
    void f()const{
        puts("f");
    }
};

template<>
struct X<int>{
    void f()const{
        puts("X<int>");
    }
    void f2()const{}

    int n;
};


template<typename T> // 主模板
void ff(const T&){}

template<> // 错误 f<int> 的显式特化在隐式实例化之后出现
void ff<int>(const int&){}

void ff2(){
    ff(1);  // 使用模板 f() 隐式实例化 f<int>
}


int main(int argc, char** argv){



  std::cout << f(2, 1) << '\n';    // 3
  std::cout << f(2.1, 1) << '\n';  // 1.1

  std::cout <<std::boolalpha<< is_void<char>::value << '\n';    // false
  std::cout << std::boolalpha << is_void<void>::value << '\n';  // true
  std::cout <<std::boolalpha<< is_void_v<char> << '\n';    // false
  std::cout << std::boolalpha << is_void_v<void> << '\n';  // true

  std::cout << std::fixed;
  X<void> x;
  X<int> x_i;
  x.f();
  x_i.f();
  x_i.f2();
  return 0;
}