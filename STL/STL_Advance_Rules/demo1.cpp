#include<iostream>
#include<optional>
#include<algorithm>
#include<functional>
#include<iterator>
#include<map>
#include<vector>
#include<string>

template<typename T>
class trie
{
    std::map<T, trie> tries;
public:
    template<typename It>
    void insert(It it, It end_it)
    {
        if (it == end_it)
            return;
        tries[*it].insert(std::next(it), end_it);
    };

    template<typename C>
    void insert(const C & container)
    {
        insert(std::begin(container), std::end(container));
    };


    void insert(const std::initializer_list<T> &il) {
        insert(std::begin(il), std::end(il));
    };

    void print(std::vector<T> &v) const {
        if (tries.empty()) {
            std::copy(begin(v),std:: end(v),
            std::ostream_iterator<T>{std::cout, " "});
            std::cout << '\n';
        }
        for (const auto &p : tries) {
            v.push_back(p.first);
            p.second.print(v);
            v.pop_back();
        }
    }

    void print() const {
        std::vector<T> v;
        print(v);
    }

    // template <typename It>
    // std::optional<reference_wrapper<const trie>>
    // subtrie(It it, It end_it) const {
    //     if (it == end_it) { return ref(*this); }
    //     auto found (tries.find(*it));
    //     if (found == std::end(tries)) { return {}; }
    //     return found->second.subtrie(std::next(it), end_it);
    // }

};

int main1()
{
    //std::optional<int> ret; 

    std::map<int,int> a;
    std::vector<int> b{1,2};    
    
    a[1] = 2;
    return 0;
}