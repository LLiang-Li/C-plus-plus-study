#include <iostream>
template<typename T>
void test(T) { std::puts("template"); }

void test(int) { std::puts("int"); }

int main(int argc, char** argv){
  test(1);        // ƥ�䵽test(int)
  test(1.2);      // ƥ�䵽ģ��
  test("1");      // ƥ�䵽ģ��
  return 0;
}