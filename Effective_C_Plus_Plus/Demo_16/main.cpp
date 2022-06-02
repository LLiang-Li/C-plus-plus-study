#include <iostream>
#include <memory>


int prot(){return 0;}

void func(std::shared_ptr<int> ptr_share, int val){};

int main(int, char**) {
    auto f([](int *a){std::cout << *a<<std::endl;});
    int a= 1;
    int *p = &a;
    f(p);
    std::shared_ptr<int> sh{p};

    //Right
    std::shared_ptr<int> ptr(new int(3));
    func(ptr,prot());
    //Un proper
    func(std::shared_ptr<int>(new int(3)), prot());
    
}
