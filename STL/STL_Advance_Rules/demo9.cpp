#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<tuple>
#include<iterator>

template <typename Iterator>
std::tuple<Iterator, size_t> occur(Iterator it, Iterator it_end)
{
    if (it == it_end) {return {it_end, 0};}
    auto It = std::find_if(it, it_end, [=](char v){return (*it != v);});
    return{It, std::distance(it, It)};
}


std::string compress(std::string &s)
{
    auto it(s.begin());
    auto it_end(s.end());
    if(it == it_end) return std::string(it, it_end);
    std::stringstream s1;
    for(auto i = it; i !=  it_end;)
    {
        auto [next_it, si] = occur(i, it_end);
        
        s1<<*i<<si;
        i = next_it;
    }

    return s1.str();
}

std::string decompress(std::string &&s)
{
    std::stringstream ss{s};
    std::stringstream out;
    char zi;
    size_t num;
    while (ss >> zi >> num)
    {
        out << std::string(num, zi);
    }
     
    return out.str();
}

int main9()
{
    std::string s {"aaaaaaaaabbbbbbbbbccccccccccc"};
    std::cout << compress(s)<<std::endl;
    auto s1 = compress(s);
    std::cout <<decompress(compress(s))<<std::endl;
    return 0;
}