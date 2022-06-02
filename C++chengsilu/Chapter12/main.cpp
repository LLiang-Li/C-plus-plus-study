#include <iostream>

template<class T>
class Array
{
public:
    Array():data(0), sz(0){}
    Array(unsigned size):data(new T[size]),sz(size){};
    ~Array(){delete[] data;}
    const T& operator[](unsigned n) const
    {
        if(n > this->sz || data == 0)
            throw "Arr";
        return this->data[n];
    }
    T& operator[](unsigned n)
    {
        if(n > this->sz || data == 0)
            throw "Arr";
        return this->data[n];
    }
    operator const T*() const
    {
        return data;
    }
    operator T*()
    {
        return data;
    }
private:
    T* data;
    unsigned sz;
    Array(const Array & a);
    Array& operator=(const Array& a);
};


int main(int, char**) {
    Array<int> a{10};
    for (int i = 0; i < 10; i++)
        a[i] = i;
    auto b = *a;
    auto c = static_cast<int *>(a);

    for (int i = 0; i < 10; i++)
    {
        std::cout << *c++<<'\n';
    }

    //std::cout << 1.2 + *a;
}
