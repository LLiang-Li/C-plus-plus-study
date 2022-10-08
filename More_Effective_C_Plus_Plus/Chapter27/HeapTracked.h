#ifndef _HEAPTRACK_
#include <iostream>
#include <list>
#include <algorithm>

using RawAddress = const void *;
class HeapTracked
{
    public:
        class MissingAddress{};
        virtual ~HeapTracked() = 0;
        static void *operator new(size_t size);
        static void operator delete(void* ptr);
        bool isOnHeap() const;
    private:
        static std::list<RawAddress> addresses;
};

std::list<RawAddress> HeapTracked::addresses;

HeapTracked::~HeapTracked(){}

void* HeapTracked::operator new(size_t size)
{
    void* menPtr = ::operator new(size);
    addresses.push_front(menPtr);
    return menPtr;
}


void HeapTracked::operator delete(void *ptr)
{
    std::list<RawAddress>::iterator it = std::find(
        addresses.begin(), addresses.end(), ptr
    );
    if(it != addresses.end())
    {
        addresses.erase(it);
        ::operator delete(ptr);
    }
    else
    {
        throw MissingAddress{}; 
    }
}

bool HeapTracked::isOnHeap() const
{
    RawAddress rawAddress = dynamic_cast<RawAddress> (this);
    std::list<RawAddress>::iterator it = std::find(
        addresses.begin(), addresses.end(), rawAddress
    );
    return (it != addresses.end());
}

#endif