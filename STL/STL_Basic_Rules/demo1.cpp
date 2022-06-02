#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<tuple>
#include<map>
#include<iterator>

namespace std{
    ostream& operator<<(ostream &os, const pair<int, string> &p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }
}

int main1()
{
    std::vector<std::pair<int, std::string>> v{
        {1, "one"}, {2, "two"}, {3, "three"},
        {4, "four"}, {5, "five"}};
    std::map<int, std::string> m;
    std::copy_n(v.begin(),3,std::inserter(m, std::begin(m)));
    auto shell_it (std::ostream_iterator<std::pair<int, std::string>>{std::cout,", "});
    std::copy(std::begin(m), std::end(m), shell_it);
    m.clear();
    std::move(std::begin(m), std::end(m), shell_it);
    std::cout << '\n';
    std::copy(std::begin(v), std::end(v), shell_it);
    std::cout << '\n';
    return 0;
}