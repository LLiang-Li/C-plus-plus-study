#include"Header.h"

static std::map<char, size_t> histogram(const std:: string &s)
{
    std::map<char, size_t> m;
    for (char c : s) { m[c] += 1; }
    return m;
}

static std::string sorted(std::string s)
{
    std::sort(std::begin(s), std::end(s));
    return s;
}

static bool is_vowel(char c)
{
    char vowels[] {"aeiou"};
    return (std::end(vowels) != std::find(std::begin(vowels), std::end(vowels), c));
}

static size_t vowels(std::string s)
{
    return std::count_if(std::begin(s), std::end(s), is_vowel);
}

int main8()
{
    std::cin.unsetf(std::ios::skipws);
    std::string input;
    std::getline(std::cin,input);
    input.pop_back();

    auto hist (std::async(std::launch::async,histogram, input));
    auto sorted_str (std::async(std::launch::async,sorted, input));
    auto vowel_count (std::async(std::launch::async,vowels, input));

    for (const auto & [c, coun] : hist.get())
    {
        std::cout << c << ":" << coun <<'\n';
    }

    std::cout <<"Sorted string " << (sorted_str.get()) << '\n'
        << "Total vowels: "<< vowel_count.get() << '\n';

    std::cout <<"endl"<<std::endl;
    return 0;
}













// std::map<char, size_t> l;
    // l['a'] = 1;
    // l['a']++;
    // l['b'] = 2;
    // l['c'] = 4;
    // std::cout <<l.size()<<'\n';
    // for (auto [str, num]: l)
    // {
    //     std::cout << str <<" " <<num <<'\n';
    // }