#include <iostream>
#include <iterator>
#include <vector>

template <typename C>
void print2d(const C & container)
{
    if (container.size() > 2)
    {
        typename C::const_iterator iter{container.begin()};
        typename C::value_type v;
        std::cout << typeid(v).name()<<'\n';
        std::cout <<*iter<<'\n';
    }
}

int main(int, char**) {
    print2d(std::vector<int>{1,2,3,4});
    std::vector<int> val{1,2,3,4};
    std::vector<int>::const_iterator it{val.begin()};
    it++;
    // std::cout << typeid(1).name();

    std::cout << "Hello, world!\n";
}
