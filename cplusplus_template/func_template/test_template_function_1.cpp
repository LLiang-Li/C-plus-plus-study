#include <iostream>

template<typename T>
T&& max(T a, T b) {
    return a > b ? std::move(a) : std::move(b);
}

class Test{
  public:
    int v_{};
    Test() = default;
    Test(const Test &) = delete;
    Test(Test &&) = delete;
    Test(int v) :v_(v) {}
    bool operator>(const Test& t) const{
        return this->v_ > t.v_;
    }
};

int main(){
    int a{ 1 };
    int b{ 2 };
    std::cout << "max(a, b) : " << max(a, b) << '\n';

    Test t1{ 10 };
    Test t2{ 20 };
    std::cout << "max(t1, t2) : " << max(Test(1), Test(2)).v_<< '\n';

}