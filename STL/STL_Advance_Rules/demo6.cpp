#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>

// namespace std{
//     ostream& operator<<(ostream &os, vector<int> &a)
//     {
//         for (auto i : a)
//             os<<i;
//         return os;
//     }
// }

template <typename InIt, typename OutIt, typename T, typename F>
InIt split(InIt it, InIt end_it, OutIt out_it, T split_val, F bin_func)
{
    while (it != end_it)
    {
        auto slice_end (std::find(it, end_it, split_val));
        *out_it++ = bin_func(it, slice_end);
        if (slice_end == end_it) { return end_it; }
        it = next(slice_end);

    }
    return it;    
}

int main6()
{
    // std::vector<int> a{1,2,3,4,5,6,7};
    // std::copy(std::begin(a), std::end(a),std::ostream_iterator<int>{std::cout, ","});
    

    // std::cout <<"-------------"<< std::endl;
    
    // std::cout << a;
    // std::vector<int> b(7);
    // std::transform(std::begin(a), std::end(a), std::begin(b), [](int a){return a*2;});
    // std::cout <<b;

    // std::string l{"012345678"};
    // std::cout <<std::string(l.begin(),l.begin()+2);

    const std::string s {"a-b-c-d-e-f-g"};

    auto binfunc ([](auto it_a, auto it_b) {
        return std::string(it_a, it_b);
    });

    std::list<std::string> l;
    split(begin(s), end(s), std::back_inserter(l), '-', binfunc);

    std::copy(std::begin(l), std::end(l),std::ostream_iterator<std::string>{std::cout, "\n"});

    std::cout << l.size();

    for (auto i : l)
    {
        std::cout << i<<std::endl;
    }    

    return 0;

}