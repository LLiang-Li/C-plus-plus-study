#include <iostream>

template<class P, class T>
P find(P start, P beyond, const T & x)
{
    while (start != beyond && *start != x)
    {  
        std::cout << *start<<", ";
        start++;
    }
    std::cout << *start<<", ";
    return start;
}

template<class P, class T>
void fan(P start, T* beyond)
{
    T temp;
    while (start < beyond)
    {
        temp = *beyond;
        *beyond = *start;
        *start = temp;
        start++;
        beyond--;   
    }
    
}



template<class Iter, class Function>
void apply(Iter start, Iter beyond, Function f)
{   
    while (start != beyond)
    {
        f(*start);
        start++;
    }
    
}

void print(int x)
{
    std::cout << x<<", ";
}

int main(int, char**) {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    // int*b = new int[10];
    // for (int i = 0; i< 10;i++)
    //     b[i] = i+1;
    // std::cout <<*find(a,a+15,15)<<'\n';
    // fan(a,a+9);
    // for (int i = 0; i < 10; i++)
    // {
    //     std::cout << a[i]<<',';
    // }
    // std::cout <<"-------------\n";
    // for (int i = 0; i < 16; i++)
    //     std::cout << a[i]<<", ";
    //apply(a,a+10,print);
    
}
