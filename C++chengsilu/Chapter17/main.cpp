#include <iostream>

class a
{
    public:
        a(int v):val(v){};
        int get() const {return this->val;}
    private:
        int val;
};

int main(int, char**) {
    a v(1);
    v.get();
    const a v1(0);
    v1.get();
}
