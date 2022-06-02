#include <iostream>

class base
{
    public:
        base(int a, int b):val_a(a),val_b(b){};
        int get_a() const {return val_a;};
        int get_b() const {return val_b;};

        int& set_a(){return val_a;};
        int& set_b(){return val_b;};



        friend std::ostream& operator<<(std::ostream &os, base& a) ;
       
    private:
        int val_a;
        int val_b;
};

std::ostream& operator<<(std::ostream &os,const base& a)
{
    os<< a.get_a()<<", "<< a.get_b()<<std::endl;
    return os;
}

std::istream & operator>>(std::istream &os, base& a)
{
    os >> a.set_a() >> a.set_b();
    return os;
}

int main1(int, char**) {

    const base val{1,2};
    base v{2,3};
    v.set_a() = 3;
    std::cout << val ;
    std::cout << static_cast<base>(v);
    // std::cin >> val >> v;
    // std::cout << val << v;
    std::cout << "Hello, world!\n";

    return 0;
}
