#include <iostream>
template<class T> class Array;
template<class T> class Pointer;
template<class T> class Ptr_to_const;

template<class T>
class Array_data
{
    friend class Array<T>;
    friend class Pointer<T>;
    friend class Ptr_to_const<T>;

    Array_data(unsigned size = 0):data(new T[size]),sz(size), use(1) {}

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
    friend class Ptr_to_const<T>;
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
class Pointer:public Ptr_to_const<T>
{
    public:
        Pointer(const Array<T> &a, unsigned n = 0):Ptr_to_const<T>(a,n) {}
        Pointer(){}
        const T& operator*() const
        {
            return Ptr_to_const<T>::operator*();
        }
};

template<class T>
class Ptr_to_const
{
    public:
        Ptr_to_const(const Array<T> &a, unsigned n = 0):
            ap(a.data), sub(n)
        {
            this->ap->use++; 
        }
        
        Ptr_to_const():ap(0),sub(0){}

        Ptr_to_const(const Ptr_to_const<T>& rhs):
            ap(rhs.ap),sub(rhs.sub)
        {
            this->ap->use++; 
        }
        ~Ptr_to_const()
        {
            if(ap && --(this->ap->use) == 0)
                delete this->ap;
        }

        Ptr_to_const& operator=(const Ptr_to_const<T> & rhs)
        {
            if(this == &rhs)
                return *this;
            if(rhs.ap)
                rhs.ap->use++;
            if(ap && --(ap->use) == 0)
                delete this->ap;
            this->ap = rhs.ap;
            this->sub = rhs.sub;
            return *this;
        }

        const T& operator*() const
        {
            if (this->ap == 0)
                throw "This data is un";
            return (*this->ap)[sub];
        }   

    private:
        Array_data<T> *ap;
        unsigned sub;
};




int main(int, char**) {
    Array<int> n(10);
    Pointer<int> p(n,2);
    std::cout << *p;
}
