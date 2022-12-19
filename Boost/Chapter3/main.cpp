#include <boost/smart_ptr.hpp>
#include <iostream>

struct posix_file
{
  posix_file(const char * file_name)
  {
    std::cout << "open file:" << file_name << '\n';
  }
  ~posix_file()
  {
    std::cout << "close file" << '\n';
  }
};



int main(int, char**) {  
  /*
  scope_ptr
  */
  {
    boost::scoped_ptr<int> uint_8(new int);
    *uint_8 = 100;
    std::cout << (*uint_8) << '\n';
    boost::scoped_ptr<posix_file> fp(new posix_file("C::/my"));

    //like std::unique_ptr
    std::unique_ptr<int> i8(new int(100));
  }

  /*
  shared_ptr
  */
  {
    boost::shared_ptr<int> int8(new int(100));
    int8 = boost::make_shared<int>(20);
    std::shared_ptr<int> s(new int);
  }
  
  /*
  weak_ptr
  协助shared_ptr,使用lock()获取shared_ptr
  */
  {
    boost::shared_ptr<int> shared_int(new int(100));
    boost::weak_ptr<int> int8(shared_int);
  }


  return 0;
}
