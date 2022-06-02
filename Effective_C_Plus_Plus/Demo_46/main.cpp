#include <iostream>

template<typename T>
class Rational
{
    public:
        Rational(const T& num = 0, const T &dem = 1):numeration(num),denominator(dem){};
        const T get_num()const {return this->numeration;}
        const T get_den()const {return this->denominator;}
        friend Rational operator*(const Rational &lhs, const Rational &rhs)
        {
            return Rational(lhs.get_num() * rhs.get_num(), lhs.get_den() * rhs.get_den());
        }
    private:
        T numeration;
        T denominator;
};

// template <typename T>
// const Rational<T> operator*(const Rational<T> &lhs, const Rational<T> &rhs)
// {
//     return Rational<T>(lhs.get_num() * rhs.get_num(), lhs.get_den() * rhs.get_den());
// }

int main(int, char**) {

    Rational<int> l{1,2};
    Rational<int> res = l*2.0;
    
    std::cout << "Hello, world!\n";

    return 0;
}
