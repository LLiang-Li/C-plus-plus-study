#include <iostream>

#define Type_Convert

class UPInt
{
    public:
        UPInt(): value(0) {};
        UPInt(int val): value(val){
            std::cout <<this->value << ", create\n";
        };
        UPInt(const UPInt &rls)
        {
            std::cout << "copy\n";
        }
        UPInt& operator=(const UPInt &rhs)
        {
            this->value = rhs.value;
            std::cout << "=\n";
            return *this;
        }
        ~UPInt()
        {
            std::cout << "delete\n";
        }
       friend const UPInt operator+(const UPInt &lhs, const UPInt &rhs);  

#ifdef Type_Convert
        friend const UPInt operator+(const int &lhs, const UPInt &rhs);
        friend const UPInt operator+(const UPInt &lhs, const int &rhs);
#endif
        std::ostream& show()
        {
            std::cout << this->value;
            return std::cout;
        }
    private:
        int value;
};

const UPInt operator+(const UPInt &lhs, const UPInt &rhs)
{
    return UPInt(rhs.value + lhs.value);
}

#ifdef Type_Convert
   
    const UPInt operator+(const int &lhs, const UPInt &rhs)
    {
        return UPInt(rhs.value + lhs);
    }
    const UPInt operator+(const UPInt &lhs, const int &rhs)
    {
        return UPInt(rhs + lhs.value);
    }
#endif
int main(int, char**) {
    UPInt s(20);
    s.show() << std::endl;
    UPInt s1 = s + (20);
    s1 = 20 + s1;
    s1.show() <<std::endl;
    return 0;
}
