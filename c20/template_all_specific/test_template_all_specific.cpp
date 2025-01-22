#include<iostream>

template<typename T,typename T2>
auto f(const T& a, const T2& b)  {
    return a + b;
}

template<>
auto f/*<double, int>*/(const double& a, const int& b){
    return a - b;
}

template<typename T> // ��ģ��
struct is_void{
    static constexpr bool value = false;
};
template<>           // �� T = void ����ʽ�ػ�
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


template<typename T> // ��ģ��
void ff(const T&){}

template<> // ���� f<int> ����ʽ�ػ�����ʽʵ����֮�����
void ff<int>(const int&){}

void ff2(){
    ff(1);  // ʹ��ģ�� f() ��ʽʵ���� f<int>
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