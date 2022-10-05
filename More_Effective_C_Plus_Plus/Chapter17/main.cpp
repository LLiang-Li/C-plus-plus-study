#include <iostream>
class LargeObject
{
    public:
        LargeObject(int val = 0):a(val) {};
        void set_a(int value)const{
            this->a = value;
        }
        int get_a()const{
            return this->a;
        }
    private:
        mutable int a;
};

int main(int, char**) {
    LargeObject l;
    std::cout << l.get_a() <<std::endl;
    l.set_a(10);
    std::cout << l.get_a() <<std::endl;
    return 0;
}
