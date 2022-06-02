#include<iostream>
#include<string>
#include<algorithm>
#include<vector>


template <typename It>
It remove_multi_whitespace(It it, It end_it)
{
    return std::unique(it, end_it, [](const auto &a, const auto &b) {
        return std::isspace(a) && std::isspace(b);
    });
}


int main8()
{

    // std::vector<int> data{1,2,3,4};
    // std::vector<int> a;
    // a.push_back(std::move(data[0]));
    // for (auto i : data)
    // {
    //     std::cout << i<<",";
    // }
    // std::cout <<"\n";

    // for (auto i : a)
    // {
    //     std::cout << i<<",";
    // }

    // std::string s{"123"};
    // std::string s1;
    // s1 = std::move(s);
    // std::cout << s<<"   "<<s1<<std::endl;

    std::string s {"fooo bar \t baz"};
    std::cout << s << '\n';

    auto it = remove_multi_whitespace(begin(s), end(s));
    std::cout << s << '\n';

    return 0;
}