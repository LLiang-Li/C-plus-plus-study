#include <iostream>
#include <algorithm>
#include <vector>
// #include <tuple>

#define _BOOST_FOR_EACH_
#undef _BOOST_FOR_EACH_
#ifdef _BOOST_FOR_EACH_
#include <boost/foreach.hpp>
#endif

#define _MIN_MAX_
#ifdef _MIN_MAX_
#include <boost/algorithm/minmax.hpp>
#endif


int main(int argc, char ** argv)
{
  std::cout << "Input Numbers: " << argc << std::endl;
  std::cout << "File Full Path and Name:" << argv[0] << std::endl;
#ifdef _BOOST_FOR_EACH_
  std::vector<int> v{1,2,3,4,5};
  BOOST_FOREACH(auto x, v)
  {
    std::cout << x << ' ';
  }
  std::cout << std::endl;
#endif

#ifdef _MIN_MAX_
  auto mm = boost::minmax<int>(1,2);
  std::cout << boost::get<0>(mm) << "  " << boost::get<0>(mm);

#endif
  return 0;
}