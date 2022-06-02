#include <iostream>

class pc
{
    public:
        pc(int in): val(in){std::cout <<"con\n";};

        pc(pc &in): val(in.val){std::cout <<"cp\n";};

        pc& operator=(pc &in)
        {
            std::cout <<"op=\n";
            this->val = in.val;
            return *this;
        }

       pc& operator*(pc & in)
        {
            std::cout <<"op*\n";
            this->val *= in.val;
            return *this;
        }

    friend std::ostream& operator<<(std::ostream& os, pc &val)
    {
        std::cout <<val.val<<std::endl;
        return os;
    }

    private:
        int val;
};

int main(int, char**) {

    pc a(1);
    pc b(a);
    pc c(3);
    a*b=c;
    std::cout <<a << b<<c<<'\n';
    std::cout << "Hello, world!\n";

    std::cout << typeid(pc).name()<<std::endl;
}
