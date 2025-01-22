#include <iostream>
#include <type_traits>
#include <numeric>
void f(const char*, int, double) { puts("value"); }
void f(const char**, int*, double*) { puts("&"); }

template<typename...Args>
void sum(Args...args){  // const char * args0, int args1, double args2
    f(args...);   // 相当于 f(args0, args1, args2)
    f(&args...);  // 相当于 f(&args0, &args1, &args2)
}

template<typename...Args>
void print(const Args&...args){    // const char (&args0)[5], const int & args1, const double & args2
    // int _[]{0, (std::cout << args << ' ' ,0)... };
    using Arr = int[];
    Arr{0, (std::cout << args << ' ' ,0)...};
}

template<typename T,std::size_t N, typename...Args>
void f(const T(&array)[N], Args...index) {
    print(array[index]...);
}

template<typename...Args,typename RT = std::common_type_t<Args...>>
RT sum_temp(const Args&...args) {
    RT _[]{ static_cast<RT>(args)... };
    RT n{};
    for (int i = 0; i < sizeof...(args); ++i) {
        n += _[i];
    }
    return n;
}

template<typename...Args,typename RT = std::common_type_t<Args...>>
RT sum_temp_std(const Args&...args) {
    RT _[]{ static_cast<RT>(args)... };
    return std::accumulate(std::begin(_), std::end(_), RT{});
}

template<std::size_t... N>
void f(){
    std::size_t _[]{ N... }; // 展开相当于 1UL, 2UL, 3UL, 4UL, 5UL
    std::for_each(std::begin(_), std::end(_),
        [](std::size_t n){
            std::cout << n << ' ';
        }
    );
}

int main(int argc, char** argv){

  sum("luse", 1, 1.2);
  print("luse", 1, 1.2);
  std::cout << std::endl;
  int array[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  f(array, 1, 3, 5);
  std::cout << std::endl;
  double ret = sum_temp(1, 2, 3, 4, 5, 6.7);
  std::cout << ret << '\n';
  double ret1 = sum_temp_std(1, 2, 3, 4, 5, 6.7);
  std::cout << ret1 << std::endl;
  f<1,2,3,4,5,6,7>();
  return 0;
}