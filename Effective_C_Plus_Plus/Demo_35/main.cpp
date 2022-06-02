#include <iostream>
#include <functional>

class base
{
    public:
        void gethealth()
        {
            getvalue();
        }
        //virtual void test()=0;
    private:
        virtual void getvalue()
        {
            std::cout <<"base"<<std::endl;
        }  
};

class sub: public base
{
    private:
        void getvalue()
        {
            std::cout << "sub"<<std::endl;
        }
};


class ptr_call
{
    public:
        using func_prt = std::function<int (const ptr_call &)> ;
        ptr_call(func_prt func_in): func{func_in}{};
        void call_fun()
        {
            func(*this);
        }
        const int get_a() const
        {
            return a;
        }
    private:
        int a{0};
        func_prt func;
};

int get_pri(const ptr_call &val)
{
    std::cout <<val.get_a();
    return -1;
}

int main(int, char**) {

    // base{}.gethealth();
    // sub{}.gethealth();

    ptr_call ls(get_pri);
    ls.call_fun();
    std::cout << "Hello, world!\n";
}
