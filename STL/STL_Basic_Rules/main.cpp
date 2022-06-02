#include <iostream>
#include <vector>
#include<numeric>

int main_(int, char**) {
    std::vector<int> data{1,2,3,4,5,6};

    int sum{0};
    for (auto i : data)
    {
        sum+=i;
    }

    std::cout<< sum <<std::endl;

    auto re = accumulate(data.begin(),data.end(),0);
    std::cout<<re<<std::endl;

    return 0;
}
