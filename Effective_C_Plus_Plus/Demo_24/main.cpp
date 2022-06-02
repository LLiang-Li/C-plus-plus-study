#include <iostream>

class Rational
{
    public :
        Rational(int numerator = 0, int denominator = 1):Numer(numerator),\
        Denom(denominator)
        {
            std::cout << "Con\n";
        };

        // const Rational operator*(const Rational & rhs)
        // {
        //     std::cout <<"intel\n";
        //     return Rational(this->Numer*rhs.Numer,this->Denom*rhs.Denom);   
        // }

        int get_de() const
        {
            return this->Denom;
        }

        int get_Nu() const
        {
            return this->Numer;
        }

        void get_value() const
        {
            std::cout << static_cast<double>(this->Numer)/static_cast<double>(this->Denom);
        }
    private:
        int Numer;
        int Denom;
};

const Rational operator*(const Rational & lhs,const Rational & rhs)
{
    std::cout << "exter\n";
    return Rational(lhs.get_Nu()*rhs.get_Nu(),lhs.get_de()*rhs.get_de());   
}

int main(int, char**) {

    Rational zeros{2,3};
    Rational one{1,2};
    Rational z{zeros};
    //z = zeros.operator*(2);
    
    z.get_value();
    
    z = 2*z;
    z.get_value();
    z = z*2;
    z.get_value();
    
    std::cout << "Hello, world!\n";
}
