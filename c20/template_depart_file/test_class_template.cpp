#include "test_class_template.h"

template<typename T>
void N::X<T>::f(){
    std::cout << "f: " << typeid(T).name() << "a: " << this->a << '\n';
}

template<typename T>
void N::X<T>::f2() {
    std::cout << "f2: " << typeid(T).name() << "a: " << this->a << '\n';
}

template void N::X<int>::f();    // ��ʽʵ�������� ��Ա�������ⲻ����ʽʵ������ģ��

template<typename T>
void N::X2<T>::f() {
    std::cout << "X2 f: " << typeid(T).name() << "a: " << this->a << '\n';
}

template<typename T>
void N::X2<T>::f2() {
    std::cout << "X2 f2: " << typeid(T).name() << "a: " << this->a << '\n';
}

template struct N::X2<int>;      // ��ģ����ʽʵ��������