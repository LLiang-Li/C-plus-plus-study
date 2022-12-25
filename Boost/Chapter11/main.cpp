#include <iostream>

// #define _BOOST_BIND_
#ifdef _BOOST_BIND_
#define BOOST_BIND_GLOBAL_PLACEHOLDERS
#include <boost/bind.hpp>

int g(int a, int b, int c)
{
  return a + b + c;
}

template<typename T>
struct large{
  using result_type = bool;
  bool operator()(const T& r, const T& l) const
  {
    return r > l;
  }
};
#endif

// #define __BOOST_FUNCTION_
#ifdef __BOOST_FUNCTION_
#include <boost/function.hpp>
#endif

#define _BOOST_SIGNALS_
#ifdef _BOOST_SIGNALS_
#include <boost/signals2.hpp>
void slots1()
{
  std::cout << "slot1 called\n";
}

void slots2()
{
  std::cout << "slot2 called\n";
}
#endif

int main(int argc, char** argv)
{
  std::cout << "Input Numbers: " << argc << std::endl;
  std::cout << "File Name with Path: " << argv[0] << std::endl;
#ifdef _BOOST_BIND_
  std::cout << "g(a,2,c) " << boost::bind(g,_1,2,_2)(1,3) << std::endl;
  std::cout << "g(a,2,c) " << boost::bind(g,_1,2,_1)(1,2,3) << std::endl;
  std::cout << "std::greater<int>() " << boost::bind(std::greater<int>(), _1, 10)(21) << std::endl;
  std::cout << "std::greater<int>() " << boost::bind(large<int>(), _1, 10)(atoi(argv[1])) << std::endl;
#endif

#ifdef __BOOST_FUNCTION_
  boost::function<int(int, int)> s;
  s = [](int a, int b) -> int{return (a + b);};
  std::cout << s(1,2) << std::endl;
#endif

#ifdef _BOOST_SIGNALS_
  boost::signals2::signal<void()> sig;
  sig.connect(&slots1);
  sig.connect(&slots2);
  sig();
#endif
  
  return 0;
}