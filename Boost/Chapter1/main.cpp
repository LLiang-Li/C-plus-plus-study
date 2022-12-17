#include<iostream>
#include<boost/version.hpp>
#include<boost/config.hpp>

int main()
{
  std::cout << BOOST_VERSION <<'\n';
  std::cout << BOOST_LIB_VERSION << '\n';
  std::cout << BOOST_PLATFORM << '\n';
  std::cout << BOOST_COMPILER << '\n';
  std::cout << BOOST_STDLIB << '\n';
}