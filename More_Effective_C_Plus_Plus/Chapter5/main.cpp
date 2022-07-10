#include <iostream>

class Rational
{
    public:
        Rational(int num, int denom):numerator(num), denominator(denom) {}
        operator double() const{
            return static_cast<double>(numerator) / denominator;
        }

    private:
        int numerator;
        int denominator;
};

std::ostream& operator<<(std::ostream &os, const Rational& rhs )
{
    return os << "123";
}      

#define _Myclass 

#ifndef _Myclass
template<class T>
class Array
{
    public:
        explicit Array(int Size):size(Size){
        //Array(int Size):size(Size){
            value = new T[size];
        }
        Array(int lob, int high):size(high - lob){
            if (this->size > 0)
                value = new T[size];
        }

        T operator[](int index) const{
            if (this->size > index)
                return this->value[index];
            return *this->value;
        }

        ~Array()
        {
            delete [] this->value;
        }
    private:
        T* value;
        int size;
};
#else

template<class T>
class Array
{
    public:
        class Arraysize
        {
            public:
                Arraysize(int Size):size(Size){}
                int getSize()const {return this->size;}
            private:
                int size;
                int ss;
        };
        Array(Arraysize Size){
            value = new T[Size.getSize()];
        }
        Array(int lob, int high){
            int size = high - lob;
            if (this->size > 0)
                value = new T[size];
        }

        T operator[](int index) const{
            return this->value[index];
            //return *this->value;
        }

        ~Array()
        {
            delete [] this->value;
        }
    private:
        T* value;
        int si;
};

#endif

bool operator==(const Array<int> &lhs, const Array<int> &rhs)
{
    std::cout << "operator==\n";
    return 1;
}


int main(int, char**) {
    //std::cout << static_cast<double>(Rational(2,3));

    Array<int> a(10);
    Array<int> b(10);
    for (int i = 0; i < 1; i++)
    {
#ifndef _Myclass
        //a==static_cast<Array<int>>(b[i]); //主要看构造函数时候能够隐式转化
        std::cout <<sizeof(Array<int>);
#else
        //a == b[i];
        std::cout << sizeof(Array<int>)<<'\n';
        std::cout << sizeof(Array<int>::Arraysize)<<'\n';
#endif
    }

    std::cout <<"  double* : " << sizeof(double *)<< " int *:" <<sizeof(int *)<< "int : " << sizeof(int)
                << "double : " <<sizeof(double) << '\n';
    
}
