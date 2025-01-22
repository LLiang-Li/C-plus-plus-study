#include <iostream>
template<typename T>
void test(T) { std::puts("template"); }

void test(int) { std::puts("int"); }

int main(int argc, char** argv){
  test(1);        // 匹配到test(int)
  test(1.2);      // 匹配到模板
  test("1");      // 匹配到模板
  return 0;
}