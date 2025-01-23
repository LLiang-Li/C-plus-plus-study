#include <iostream>
#include <vector>

template<typename T>
const typename T::type& f(const T&) {
  static const typename T::type data = 0;
    return data;
}

struct X{
    using type = int;
};

template<typename T>
void foo(const std::vector<T>& v){
    // std::vector<T>::const_iterator 是待决名，
    typename std::vector<T>::const_iterator it = v.begin();

    // 下列内容因为没有 'typename' 而会被解析成
    // 类型待决的成员变量 'const_iterator' 和某变量 'p' 的乘法。
    // 因为在此处有一个可见的全局 'p'，所以此模板定义能编译。
    typename std::vector<T>::const_iterator* p;

    typedef typename std::vector<T>::const_iterator iter_t;
    iter_t* p2; // iter_t 是待决名，但已知它是类型名
}

template<typename T>
struct S{
    template<typename U>
    void foo() {}
};

template<typename T>
void bar(){
    S<T> s;
    // s.foo<T>();          // 错误：< 被解析为小于运算符
    T::template foo<T>();
    s.template foo<T>(); // OK
}

int main(int argc, char** argv){
  X x;
  std::cout << f(x) << std::endl;
  std::cout << "lige" <<std::endl;
  return 0;
}