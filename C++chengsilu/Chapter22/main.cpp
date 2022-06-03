#include <iostream>
#include <algorithm>
#include <cstring>

int main(int, char**) {

    int a[10] = {20};
    memset(a, 2, sizeof(int)*10);
    
    std::transform(a,a+10,a,std::bind1st(std::plus<int>(),1));
    for(int i = 0; i < 10; i++)
    {
        std::cout << a[i]<<", ";
    }
    std::cout<<'\n';
    return 0;
}
