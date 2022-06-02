#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

struct city {
    std::string name;
    size_t population;
    size_t latitude;
    size_t longitude;
};

std::istream &  operator>>(std::istream &in, city &c)
{
    in >> std::ws;
    in >> c.name
    >>c.population
    >>c.latitude
    >>c.longitude;
    return in;
}

int main7()
{
    // std::vector<city> l;
    // std::cout <<"--------------"<<std::endl;
    // std::copy(std::istream_iterator<city>{std::cin},{}, std::back_inserter(l));
    // std::cout <<"--------------"<<std::endl;

    // for (const auto &[name, pop, lat, lon] : l) {
    //     std::cout << std::left << std::setw(15) <<"name=" <<name
    //     << " population=" << pop
    //     << " lat=" << lat
    //     << " lon=" << lon << '\n';
    // }
    city l;
    

    std::cin >> l;
    std::cout << l.name <<l.latitude << l.longitude<< l.population<<std::endl;


    return 0;
}