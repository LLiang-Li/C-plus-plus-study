
#include <iostream>

class Rational
{
    public:
        Rational(int num = 0, int demo = 1): numerator(num), denominator(demo) {
            std::cout << "create\n";
        }
        ~Rational()
        {
            std::cout << "delete\n";
        }
        int numerator;
        int denominator;
};

inline const Rational operator*(const Rational & lhs, const Rational & rhs)
{
    return Rational(lhs.numerator * rhs.numerator, lhs.denominator * rhs.denominator);
}

int main(int, char**) {
    Rational a = 10;
    Rational b(1,2);
    Rational c = a * b;
    return 0;
}

