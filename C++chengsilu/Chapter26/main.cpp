#include <iostream>

class Obj_trace
{
    public:
        Obj_trace():ct(++counter){
            std::cout << "Object" << ct <<"construction\n";
        }
        ~Obj_trace(){
            std::cout << "Object" << ct <<"Destory\n";
        }
        Obj_trace(const Obj_trace &):ct(++counter){
            std::cout << "Object" << ct <<"construction\n";
        }
        Obj_trace & operator=(const Obj_trace &)
        {
            return *this;
        }
    private:
        static int counter;
        int ct;
};

int Obj_trace::counter = 0;

template<class T>
class Array
{
    public:
        Array(int n = 0):data(new T[n]), sz(n) {}

        Array(const Array& rhs)
        {
            this->data = new T[rhs.sz];
            this->sz = rhs.sz;
            for (int i = 0; i < this->sz; i++)
                this->data[i] = rhs.data[i];
        }

        Array& operator=(const Array& rhs)
        {
            if(this != &rhs)
            {
                delete [] this->data;
                this->data = new T[rhs.sz];
                this->sz = rhs.sz;
                for (int i = 0; i < this->sz; i++)
                    this->data[i] = rhs.data[i];
            }
            return *this;
        }

        ~Array(){delete [] data;}
        
        T& operator[](int n)
        {
            return data[n];
        }
    private:
        T* data;
        int sz;
};

int main(int, char**) {
    Array<Obj_trace> x(3);
    Array<Obj_trace> y = x;
    x = x;
}
