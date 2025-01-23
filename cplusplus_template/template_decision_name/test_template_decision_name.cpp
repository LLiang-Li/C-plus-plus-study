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
    // std::vector<T>::const_iterator �Ǵ�������
    typename std::vector<T>::const_iterator it = v.begin();

    // ����������Ϊû�� 'typename' ���ᱻ������
    // ���ʹ����ĳ�Ա���� 'const_iterator' ��ĳ���� 'p' �ĳ˷���
    // ��Ϊ�ڴ˴���һ���ɼ���ȫ�� 'p'�����Դ�ģ�嶨���ܱ��롣
    typename std::vector<T>::const_iterator* p;

    typedef typename std::vector<T>::const_iterator iter_t;
    iter_t* p2; // iter_t �Ǵ�����������֪����������
}

template<typename T>
struct S{
    template<typename U>
    void foo() {}
};

template<typename T>
void bar(){
    S<T> s;
    // s.foo<T>();          // ����< ������ΪС�������
    T::template foo<T>();
    s.template foo<T>(); // OK
}

int main(int argc, char** argv){
  X x;
  std::cout << f(x) << std::endl;
  std::cout << "lige" <<std::endl;
  return 0;
}