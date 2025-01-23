#include <iostream>
#include <tuple>

template<typename T>
struct Class_template{
    void f(T) {}
};

struct Test{
    template<typename...Args>
    void f(Args&&...args){}
};

template<typename T>
struct Class_template1{
    template<typename... Args>
    void f(Args&&...args) {}
};

template<typename ...Args>
struct X {
    X(Args...args) :value{ args... } {} // ����չ��
    std::tuple<Args...>value;           // �����βΰ�չ��
};

int main(int argc, char** argv){
  X x{ 1,"2",'3',4. };
  std::cout << std::get<0>(x.value);
  return 0;
}