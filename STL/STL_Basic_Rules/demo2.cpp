#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <random>

static void print(const std::vector<int> &v)
{
    std::copy(std::begin(v), std::end(v), std::ostream_iterator<int>{std::cout, ", "});
    std::cout <<std::endl;
}

struct mystruct {
int a;
int b;
};

namespace std{
    ostream& operator<<(ostream &os, const mystruct &in)
    {
        return os <<" {"<< in.a <<", "<<in.b<<"}";
    }
}


int main2()
{
    std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
    // print(data);
    std::random_device rd;
    std::mt19937 g{rd()};
    std:: cout << std::is_sorted(std::begin(v), std::end(v)) << '\n';

    std::shuffle(std::begin(v), std::end(v), g);
    std:: cout << std::is_sorted(std::begin(v), std::end(v)) << '\n';
    print(v);

    std::shuffle(std::begin(v), std::end(v), g);
    std::partition(std::begin(v), std::end(v), [] (int i) { return i < 5; });
    print(v);

    std::shuffle(std::begin(v), std::end(v), g);
    auto middle (std::next(std::begin(v), int(v.size()) / 2));
    std::partial_sort(std::begin(v), middle, std::end(v));
    print(v);

    std::vector<mystruct> mv { {5, 100}, {1, 50}, {-123, 1000},{3, 70}, {-10, 20} };

    std::sort(std::begin(mv), std::end(mv),[] (const mystruct &lhs, const mystruct &rhs) {return lhs.b < rhs.b;
});
    std::cout << std::endl;

    for (auto i : mv)
        std::cout<< i;
}