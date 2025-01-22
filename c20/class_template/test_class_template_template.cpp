#include <iostream>

template<typename T>
struct my_array{
    T arr[10];
};

template<typename Ty,template<typename T> typename C >
struct Array {
    C<Ty>array;
};

template<typename T>
struct X{};

template<typename T>
struct X2 {};

template<template<typename T>typename...Ts>
struct Test{};

template<std::size_t N>
struct XX {};

template<template<std::size_t> typename C>
struct Test1 {};

template<typename... T>
struct my_array1{
    int arr[sizeof...(T)];  // 保有的数组大小根据模板类型形参的元素个数
};

template<typename Ty, template<typename... T> typename C = my_array1 >
struct MyArray {
    C<Ty>array;
};

int main(int argc, char** argv){
  Array<int, my_array> arr;
  Test<X, X2, X, X>t;
  Test1<XX> ar;
  MyArray<int> s;
  return 0;
}