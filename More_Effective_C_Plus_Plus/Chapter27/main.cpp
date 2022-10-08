#include "HeapTracked.h"

class lige: public HeapTracked 
{
    public:
        lige(){}
        ~lige(){}
        static void operator delete(void* ptr);
};

void lige::operator delete(void* ptr)
{
    try
    {
        ::operator delete(ptr);
    }
    catch(...)
    {
        std::cout << "error";
        throw ;
    }
}


int main(int, char**) {
    lige *a  = new lige;
    std::cout << a->isOnHeap();
    HeapTracked::MissingAddress ls;
    try
    {
        delete a;
    }
    catch(...)
    {
        std::cout << "  error\n";
    }
    return 0;
}