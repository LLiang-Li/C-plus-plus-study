#include <iostream>
class Upint
{
    public:
        Upint():value(0){}
        Upint& operator++()
        {
            *this += 1;
            return *this;
        }
        const Upint operator++(int)
        {
            Upint oldPint(*this);
            *this += 1;
            return oldPint;
        }
         Upint& operator--()
        {
            *this += -1;
            return *this;
        }
        const Upint operator--(int)
        {
            Upint oldPint(*this);
            *this += -1;
            return oldPint;
        }
        Upint& operator+=(int val)
        {
            this->value += val;
            return *this;
        }
        int getValue()const
        {
            return this->value;
        }
    private:
        Upint(const Upint &rhs)
        {
            this->value = rhs.value;
        }
        int value;
};

int main(int, char**) {
    Upint u;
    std::cout << u.getValue() << '\n';
    u++;
    std::cout << u.getValue() << '\n';
    u--;
    ++++u;
    std::cout << u.getValue() << '\n';
}
