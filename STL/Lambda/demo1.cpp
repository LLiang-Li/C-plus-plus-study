#include<iostream>
#include<string>
#include<typeinfo>

// const std::type_info &s = typeid(just_one);
// std::cout <<s.name()<<std::endl;

auto add([](auto fi, auto se){return (fi+se);});

// int main()
// {
//     int a{2};
//     auto just_one ([](){return 1;});
//     auto index([counter = 0.0] () mutable -> double{
//             return counter++;
//     } );

//     std::cout << index()<<std::endl;
//     std::cout << index()<<std::endl;
//     std::cout << add(1.2,2)<<std::endl;    
//     return 0;
// }