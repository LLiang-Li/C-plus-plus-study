#include"test_function_template.h"

template<typename T>
void f_t(T) { std::cout << typeid(T).name() << '\n'; }

template void f_t<int>(int); // ��ʽʵ�������� ʵ���� f_t<int>(int)
template void f_t<>(char);   // ��ʽʵ�������� ʵ���� f_t<char>(char)���Ƶ���ģ��ʵ��
template void f_t(double);   // ��ʽʵ�������� ʵ���� f_t<double>(double)���Ƶ���ģ��ʵ��