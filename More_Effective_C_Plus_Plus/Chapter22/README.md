考虑操作符复合模式取代其独生模式：
x = x + y；转化成 x+=y
例如
class Rational 
{
    public:
    ...
    Rational & operator+=(const Rational &rhs);
    Rational & operator+-(const Rational &rhs);
}

const Rational operator+(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs)+=rhs;
}

const Rational operator-(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs)-=rhs;
}

此举只需要维护一份代码；