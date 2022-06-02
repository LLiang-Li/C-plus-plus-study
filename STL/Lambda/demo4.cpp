// #include <iostream>
// #include <functional>
// #include <string>
// #include <iterator>
// #include <algorithm>
// #include <vector>

// static bool begins_with_a(const std::string &s)
// {
//     return s.find("a") == 0;
// }


// static bool ends_with_b(const std::string &s)
// {
//     return s.find("b") == (s.length()-1);
// }

// template<typename Func, typename A, typename B>
// auto concat(Func func, A a, B b)
// {
//     return [=](auto param){ return func(a(param),b(param));};
// }

// int main()
// {
//     auto a_xxx_b (concat(std::logical_and<>{}, begins_with_a, ends_with_b));
//     std::vector<std::string> str{"asdkjfb","adhfd","sdhfdb"};
//     for (auto i:str)
//     {
//         if (a_xxx_b(i))
//             std::cout << i;
        
//     }
// }
