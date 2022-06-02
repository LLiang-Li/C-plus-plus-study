#include <iostream>
#include <string>
#include <string_view>
#include <sstream>
#include <algorithm>
using namespace std;
using namespace std::literals;

int main1()
{

    std::string a{"a"};
    

    //std::string_view c{"c"};

    

    std::cout <<::toupper('a');
    std::cout <<int(' ');
    std::cout << ::toupper(' ');
    return 0;
}