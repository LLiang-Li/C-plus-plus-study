#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>
#include <boost/bimap.hpp>
#include <boost/circular_buffer.hpp>
#include <boost/any.hpp>
#include <boost/variant.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <iostream>
#include <unordered_set>
#include <string>
#include <exception>

int main(int, char**) {
#if 0
  boost::unordered_set<int> s{5, 5, 3, 2, 1,2,45,67,23,45,634,546,4,546,56,34,432,3454,3};
  for(const auto& x : s)
  {
    std::cout << x << " ";
  }
  std::cout << '\n';
  std::cout << s.bucket_count();

#endif

#if 0
  boost::unordered_map<int, std::string> mu{{1,"123"},{2,"234"}};
  std::cout << mu[1] << '\n';
  mu.emplace(3,"234");
  std::cout << mu[3] << '\n';
#endif

#if 0
  boost::bimap<int, std::string> bm;
  bm.left.insert({1,"111"});
  bm.left.insert({2,"222"});
  bm.left.insert({1,"222"});
  for(const auto & x : bm.left)
    std::cout << x.first << " : " << x.second << '\n';
#endif

#if 0
  boost::circular_buffer<int>  s(5);
  std::cout << "size: " << s.size() << '\n';
  s.resize(5);
  std::cout << "size: " << s.size() << '\n'; 
  for(int i = 0; i < 5; i++)
    std::cout << s[i] << " ";
  std::cout << '\n';
  s.push_back(1);
  
  //s.insert(s.begin(),3);
  for(auto x : s)
    std::cout << x << " "; std::cout << '\n';
  s.push_back(2);
  for(auto i = s.begin(); i < s.end(); ++i)
    std::cout << *i << " ";
  std::cout << '\n';
//   s.insert(s.begin(),3);
  s.pop_back();
  std::cout << "size: " << s.size() << '\n'; 
  for(auto i = s.begin(); i < s.end(); ++i)
    std::cout << *i << " ";
  for(int i = 0; i < 5; i++)
    std::cout << s[i];
  std::cout << '\n';
  std::cout << s.size();
#endif

#if 0
  boost::any a;
  a = 10;
  std::cout << boost::any_cast<int>(a) << '\n';
  a = 10.2;
  std::cout << boost::any_cast<double>(a) << '\n';
#endif

#if 0
  boost::variant<short,int,long> boost_variant(10);
  //std::cout << boost::get<short>(boost_variant) << '\n';
  std::cout << boost::get<int>(boost_variant) << '\n';
  //std::cout << boost::get<long>(boost_variant) << '\n';
#endif

#if 1
  boost::property_tree::ptree pt;
  try{
    /*XML read*/
    boost::property_tree::read_xml("../conf.xml", pt);
    std::cout << pt.get<std::string>("conf.theme") << std::endl;
    std::cout << pt.get("conf.no_prop", 100) << std::endl;
    std::cout << pt.get<long>("conf.gui") << std::endl;
    auto child = pt.get_child("conf.urls");
    // std::cout << pt.get_value<std::string>() << std::endl;
    for(auto& x : child)
    {
      auto ss = x.second;
      std::cout << "Frist: " << x.first << "; Second: " << x.second.get_value<std::string>() << std::endl;
    }
    /*XML write*/
    boost::property_tree::write_xml(std::cout, pt);
    pt.put("conf.theme", "MAtrix Reload");
    pt.put("clock_style", 12);
    pt.add("conf.urls.url", "https:://ww.360.com");

    boost::property_tree::write_xml(std::cout, pt);
    boost::property_tree::write_xml("new.xml", pt);
  }
  catch(std::exception& e)
  {
    std::cout << e.what();
  }
  
#endif

  return 0;
}
