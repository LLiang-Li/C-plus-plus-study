#include <iostream>
#include <string>
#include <vector>

// #define _BOOST_SYSTEM_ERROR_
#ifdef _BOOST_SYSTEM_ERROR_
#define BOOST_ERROR_CODE_HEADER_ONLY
#include <boost/system/error_code.hpp>
#include <boost/system/system_error.hpp>
#endif

// #define _BOOST_CHRONO_
#ifdef _BOOST_CHRONO_
#define BOOST_ERROR_CODE_HEADER_ONLY
#define BOOST_CHRONO_HEADER_ONLY
#define BOOST_CHRONO_EXTENSIONS
#include <boost/chrono.hpp>

using day = boost::chrono::duration<double, boost::ratio<3600*24>>;
#endif

// #define _BOOST_FILESYSTEM_
#ifdef _BOOST_FILESYSTEM_
#include <boost/filesystem.hpp>
#endif

#define _PROGRAM_OPTION_
#ifdef _PROGRAM_OPTION_
#include <boost/program_options.hpp>
#endif

#ifdef _BOOST_SYSTEM_ERROR_
class my_category: public boost::system::error_category
{
 public:
  virtual const char * name() const BOOST_SYSTEM_NOEXCEPT
  {
    return "myapp_category";
  }
  virtual std::string message(int env) const
  {
    std::string msg;
    switch(env)
    {
      case 0:
        msg = "Ok"; break;
      default:
        msg = "some error";
    }
    return msg;
  }
};
#endif

int main(int argc, char ** argv)
{
  std::cout << "Input Numbers:" << argc << std::endl;
  std::cout << "File Path and Name:" << argv[0] << std::endl;

#ifdef _BOOST_SYSTEM_ERROR_
  my_category my_cat;
  boost::system::error_code ec(10, my_cat);
  std::cout << ec.value() << " " << ec.message() << std::endl;
  ec = boost::system::error_code(atoi(argv[1]), boost::system::system_category());
  std::cout << ec.value() << " " << ec.message() << std::endl;

  try {
    throw boost::system::system_error(boost::system::error_code(atoi(argv[2]), boost::system::system_category()));
  }
  catch(boost::system::system_error & e)
  {
    std::cout << e.what() << std::endl;
  }
#endif

#ifdef _BOOST_CHRONO_
  boost::chrono::hours hours(1);
  std::cout << hours << std::endl;
  day d(1);
  std::cout << d << std::endl;
  std::cout << boost::chrono::duration_cast<boost::chrono::hours>(d) << std::endl;

  auto now = boost::chrono::system_clock::now();
  std::cout << "now time: " << now << std::endl;
  auto date = boost::chrono::system_clock::to_time_t(now);
  std::cout << "date: " << date << std::endl;
  std::cout << std::ctime(&date) << std::endl;
#endif

#ifdef _BOOST_FILESYSTEM_
  boost::filesystem::path path("/");
  path /= "home";
  path /= "lige";
  std::cout << path << std::endl;
  std::cout << boost::filesystem::system_complete(path) << std::endl;
#endif


#ifdef _PROGRAM_OPTION_
  #if 0
    boost::program_options::options_description opts("name");
    /**/
    opts.add_options()("help", "just a help")("filename", boost::program_options::value<std::string>(), "to find a file");
    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, opts), vm);
    if (vm.count("help"))
      std::cout << opts;
    if (vm.count("filename"))
      std::cout << "find" << vm["filename"].as<std::string>() << std::endl;
    if (vm.empty())
      std::cout << "no option\n";
  #else
    boost::program_options::options_description opts("demo options");
    std::string filename;
    opts.add_options()("help,h", "help message \n a bit of long text")
                    ("filename,f", boost::program_options::value<std::string>(&filename)
                    ->default_value("test"), "to find a file")
                    ("dir,D", boost::program_options::value<std::vector<std::string>>()
                    ->multitoken(), "Search dir");
    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, opts), vm);
    boost::program_options::notify(vm);

    if (vm.empty())
    {
      std::cout << opts << std::endl; return 0;
    }
    if (vm.count("help"))
    {
        std::cout << opts << std::endl;
    }

    std::cout << "find opt: " << vm["filename"].as<std::string>() << std::endl;

    if(vm.count("dir"))
    {
        std::cout << "dir opt:";
        for (auto& str : vm["dir"].as<std::vector<std::string>>())
          std::cout << str << ',';
        std::cout << std::endl;
    }
  #endif
#endif

  return 0;
}