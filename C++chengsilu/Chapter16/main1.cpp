#include<iostream>

template<class T>
class Iterator
{
    public:
        virtual int valid()const = 0;
        virtual int next() = 0;
        virtual ~Iterator(){};
};

template<class T>
class Array_iterator: public Iterator<T>
{
    public:
        Array_iterator(T* p, int c):data(p), len(c) {}
        int valid()const{return len >0;}
        T next(){--len;return *data++;}
    private:
        T* data;
        int len;
};

template<class T>
T Sum(Array_iterator<T> ir)
{
    T result = 0;
    while (ir.valid())
    {
        result += ir.next();
    }
    return result;
}

template<class T, class Iter>
void sum2(T & result, Iter ir)
{
    result = 0;
    while (ir.valid())
    {
        result += ir.next();
    }
    
}

template<class T>
T sum3(T* p, int n)
{
    T r = 0;
    sum2(r, Array_iterator<T>(p,n));
    return r;
}

template<class T>
class Reader
{
    public:
        Reader(std::istream& os):i(os) {this->advance();};
        int valid()const {return status;}
        T next(){T res = this->data; this->advance(); return res;}
    private:
        std::istream& i;
        int status;
        T data;
        void advance()
        {
            i >> this->data;
            this->status = i.eof();
            std::cout<<"advance:"<<this->status<<std::endl;
        }
};

int main()
{
    int x[10] = {1,2,3,4,5,6,7,8,9,10};
    std::cout << Sum(Array_iterator<int>(x,10))<<'\n';
    int res;
    sum2(res,Array_iterator<int>(x,10));
    std::cout << res<<'\n';
    std::cout <<sum3(x,10);

    std::cout << "Edsgf:\n";
    double r = 0;
    sum2(r,Reader<double>(std::cin));
    std::cout << r;
    return 0;
}