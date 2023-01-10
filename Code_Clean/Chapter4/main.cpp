#include <iostream>
#include <assert.h>

int main(int argc, char ** argv)
{
  std::cout << "Input Number: " << std::endl;
  std::cout << __FILE__ << std::endl;
//   static_assert(atoi(argv[1]));
  int* p = new int[10];
  int a[10];
  char *s = "Hello";
  std::cout << sizeof(*p)/sizeof(int) << std::endl;
  std::cout << sizeof(&a) << std::endl;
  std::cout << sizeof(s) << std::endl;
  delete []p;
  return 0;
}