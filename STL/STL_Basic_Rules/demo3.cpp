#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void print(const std::vector<int> &v)
{
std::copy(std::begin(v), std::end(v), std::ostream_iterator<int>{std::cout, ", "});
std::cout << '\n';
}


int main3()
{
    std::vector<int> v {1, 2, 3, 4, 5, 6};
    print(v);

    const auto new_end (std::remove(std::begin(v), std::end(v), 2));
    print(v);
    v.erase(new_end, std::end(v));
    print(v);
    std::cout << "Replace 4 to 123\n";
    replace(begin(v), end(v), 4, 123);
    print(v);

    std::cout << "-------------------"<<std::endl;
    v = {1,2,3,4,5,6,7,8};
    std::vector<int> v2 {100};
    std::vector<int> v3;

    auto odd_number ([](int i) { return i % 2 != 0; });
    auto even_number ([](int i) { return i % 2 == 0; });

    std::remove_copy_if(std::begin(v), std::end(v),
    std::inserter(v2,std::end(v2)), odd_number);
    std::copy_if(std::begin(v), std::end(v),
    back_inserter(v3), even_number);
    print(v2);
    print(v3);
    return 0;
}