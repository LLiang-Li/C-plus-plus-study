#include <iostream>
template<class T> class Array;
template<class T> class Pointer;

template<class T>
class Array_data
{
    friend class Array<T>;
    friend class Pointer<T>;

    Array_data(unsigned size):data(new T[size]),sz(size), use(1) {}

    ~Array_data(){delete[] data;}

    const T& operator[](unsigned n) const
    {
        if (n >= sz)
            throw "Out of range!";
        return this->data[n];
    }

    T& operator[](unsigned n)
    {
        if (n >= sz)
            throw "Out of range!";
        return this->data[n];
    }

    T* data;
    unsigned sz;
    int use;
};


template<class T>
class Array
{
    friend class Pointer<T>;
    public:
        Array(unsigned size):data(new Array_data<T>(size)){};
        ~Array(){
            if (--(this->data->use) == 0)
                delete data;
        }
        const T& operator[](unsigned n) const
        {
            return (*data)[n];
        }

        T& operator[](unsigned n)
        {
            return (*data)[n];
        }

    private:
        Array(const Array&);
        Array& operator=(const Array &);
        Array_data<T> *data;
};

template<class T>
class Pointer
{
    public:
        Pointer():data(0){};
        Pointer(const Array<T> & ar):data(ar.data)
        {
            this->data->use++;
        }
        Pointer(const Array<T> * ar):data(ar->data)
        {
            this->data->use++;
        }

        Pointer(const Pointer & p):data(p.data)
        {
            this->data->use++;
        }

        Pointer& operator=(const Pointer & rhs)
        {
            if (this == &rhs)
                return *this;
            if (--(this->data->use) == 0)
                delete this->data;
            this->data = rhs.data;
            this->data->use++;
            return *this;
        }

        ~Pointer()
        {
            if(this->data == 0)
                return;
            if(--(this->data->use) == 0)
                delete this->data;
        }

        const T& operator[](unsigned n) const{
            if(this->data == 0)
                throw "The Point is NULL";
            return (*this->data)[n];
        }

        T& operator[](unsigned n){
            if(this->data == 0)
                throw "The Point is NULL";
            return (*this->data)[n];
        }

    private:
        Array_data<T> *data;
};

int main(int, char**) {
    Array<int>* r = new Array<int>(10);
    Pointer<int> p(*r);
    delete r;
    p[0] = 1;
    std::cout << p[0];
}
