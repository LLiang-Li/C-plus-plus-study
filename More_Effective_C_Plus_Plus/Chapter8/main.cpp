#include <iostream>
#include <string>
#include <stdio.h>

class Widget{
    public:
        Widget(int v):val(v) {}
        int getval()const{
            return val;
        }
        void* operator new(size_t, void* location)
        {
            return location;
        }
    private:
        int val;
};

Widget* constructWidget(void* buffer, int widgetsize)
{
    return new (buffer) Widget(widgetsize);
}

int main(int, char**) {
    std::cout << "Hello, world!\n";
    printf("%#x",11);

    std::string *ps = new std::string("Memory Managemet!");
    /***
     * 上句的new会执行以下操作
     * 
     * void *memory = operator new(sizeof(std::string));
     * 
     * call string::string("Memory Management")
     * on *memory
     * 
     * std::string *ps = static_cast<std::string *>(memory);
     * ****/
    
    //placement new

    Widget wi(1);
    std::cout <<'\n'<< wi.getval()<<'\n';
    Widget* a = constructWidget(&wi, 2);
    std::cout << wi.getval()<<'\n';
    std::cout << a->getval()<<'\n';
    //由于指针a是指向wi，new操作并没有产生重新开辟空间，delete会导致多次释放。
    //delete a;
    
    //需要添加::，此时调用的是全局的new而不是类中重载的new
    Widget* b = ::new Widget(20);
    std::cout << b->getval()<<'\n';
    delete b;
    

    return 0;
}
