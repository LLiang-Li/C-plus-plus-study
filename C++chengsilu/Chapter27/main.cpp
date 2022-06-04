#include "cluster_class.hpp"


class A:public Clusteritem
{
    public:
        A():val(0){}
        A(int v):val(v){}
    private:
        int val;
};

int main(int, char**) {
    Cluster c;
    A* var = new(c) A;
    A* v = new(c) A;
    std::cout << sizeof(A)<<'\n';

}
