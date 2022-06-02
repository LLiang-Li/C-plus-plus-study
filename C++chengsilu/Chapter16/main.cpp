#include <iostream>

int sum(int *p, int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
        result += p[i];
    return result;
}

// template<class T>
// class Iterator
// {
//     public:
//         Iterator(T * p, int c):data(p), len(c) {};
//         ~Iterator(){};
//         int valid() const
//         {
//             return len > 0;
//         }
//         T next()
//         {
//             len--;
//             return *data++;   
//         }

//         Iterator(const Iterator<T> & rhs)
//         {  
//             this->data = rhs.data;
//             this->len = rhs.len;
//         }

//         Iterator& operator=(const Iterator<T> &rhs)
//         {
//             this->data = rhs.data;
//             this->len = rhs.len;
//         }
    
//     private:
//         T* data;
//         int len;
// };

// template<class T>
// T sum(Iterator<T> ir)
// {
//     T result = 0;
//     while (ir.valid())
//     {
//         result+=ir.next();
//     }
//     return result;
// } 


int main0(int, char**) {
    int x[10] = {1,2,3,4,5,6,7,8,9,10};
    //std::cout << sum(Iterator<int>(x,10));
    return 0;
}
