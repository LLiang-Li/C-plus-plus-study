#include <iostream>

#define SAFE
#define auto_ptr_safe

class ALA
{
    public:
        virtual void processAdoption() = 0;
        virtual ~ALA() = default;
};

class Puppy: public ALA
{
    public:
        void processAdoption()
        {
            std::cout << "Puppy\n";
        }
        ~Puppy(){std::cout << "~Puppy\n";}
};

class Kitten: public ALA
{
    public:
        void processAdoption()
        {
            std::cout << "Kitten\n";
        }
        ~Kitten(){std::cout << "~Kitten\n";}
};

ALA* readALA(std::istream & datasource)
{
    char str[20];
     datasource.getline(str, 20);
     std::cout << str;
     if ('d' > str[0])
        return new Kitten;
     else
        return new Puppy;
}

template<class T>
class my_auto_ptr{
    public:
        my_auto_ptr(T* p = NULL): ptr(p){}
        T* operator->()
        {
            return ptr;
        }
        ~my_auto_ptr()
        {
            if (NULL != this->ptr)
                delete this->ptr;
        }
    private:
        T* ptr;
};


int main(int, char**) {
#ifdef auto_ptr_safe
    my_auto_ptr<ALA> pa(readALA(std::cin));
    pa->processAdoption();

#else
    #ifndef SAFE
        ALA* al = readALA(std::cin);
        al->processAdoption();
        delete al;
    #else
        ALA* al = readALA(std::cin);
        try{
        al->processAdoption();
        }
        catch (std::exception &str)
        {
            delete al;
        }
        delete al;
    #endif
#endif

}
