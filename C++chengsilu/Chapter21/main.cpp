#include <iostream>
#include "template_class.hpp"

template<class F, class G, class X, class Y>
class Comp
{
    public:
        Comp(F f0, G g0): f(f0), g(g0) {}

        Y operator()(X x)
        {
            return f(g(x));
        }
    private:
        F f;
        G g;
};


int f(int x) 
{
    return x;
}

int main(int, char**) {
     //Compe<int (*)(int), int (*)(int), int, int> ob(f,f);
     //std::cout << ob(1) << '\n';

    Composition<int,int> obj(f,f);
    std::cout << obj(10);
    return 0;
}
