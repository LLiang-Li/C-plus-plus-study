// #include <iostream>
// template <typename ... Ts>
// static auto multicall (Ts ...functions)
// {
//     return [=](auto x) {
//     (void)std::initializer_list<int>{
//         ((void)functions(x), 0)...
//         };
//     };
// }

// static auto brace_print (char a, char b) {
// return [=] (auto x) {
// std::cout << a << x << b << ", ";
// };
// }


// int main()
// {
//     auto f (brace_print('(', ')'));
//     auto g (brace_print('[', ']'));
//     auto h (brace_print('{', '}'));

//     auto call_fgh (multicall(f, g, h));
//     call_fgh(1);

//     auto li = {1.2,2.2,3.3};


// }