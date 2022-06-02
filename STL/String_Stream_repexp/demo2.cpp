#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <string_view>
using namespace std;

std::string trim_whitespace_surrounding(const std::string &s)
{
    const char whitespace[] {" \t\n"};
    const size_t first (s.find_first_not_of(whitespace));
    if (std::string::npos == first) { return {}; }
    const size_t last (s.find_last_not_of(whitespace));
    return s.substr(first, (last - first + 1));
}

int main2()
{
    
    std::string s {" \t\n string surrounded by ugly"
        " whitespace \t\n "};
    std::cout << "{" << s << "}\n";
    std::cout << "{"    << trim_whitespace_surrounding(s)     << "}\n";
    return 0;
}