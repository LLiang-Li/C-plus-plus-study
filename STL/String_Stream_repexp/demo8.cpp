#include <iostream>
#include <iomanip>
#include <map>
#include <iterator>
#include <algorithm>
#include <numeric>

struct meme {
    std::string description;
    size_t year;
};

std::istream& operator>>(std::istream &is, meme &m)
{
    return is >> std::quoted(m.description) >> m.year;
}

std::istream& operator >>(std::istream &is,std::pair<std::string, meme> &p) {
return is >> std::quoted(p.first) >> p.second;
}


int main8()
{
    std::map<std::string, meme> m;
    std::copy(std::istream_iterator<std::pair<std::string, meme>>{std::cin},
        {},
        std::inserter(m, std::end(m)));
    auto max_func ([](size_t old_max,
    const auto &b) {
    return std::max(old_max, b.first.length());
    });
    size_t width {std::accumulate(std::begin(m), std::end(m),
    0u, max_func)};
    // for (const auto &[meme_name, meme_desc] : m) {
    //     const auto &[desc, year] = meme_desc;
    //     std::cout << std::left << std::setw(width) << meme_name
    //     << " : " << desc
    //     << ", " << year << '\n';
    // }
    return 0;
}