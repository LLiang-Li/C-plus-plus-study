#include <iostream>

class Equipment
{
    public:
        Equipment(int val):value(val){}
        int getValue() const{return this->value;}
    private:
        int value;
};


using EPT = Equipment*;
int main(int, char**) {
    /*******
     * 
     * ERROR
     * Equipment* arr[10];
     * Equipment* ARR = new Equipment[10];
     * 
     * ********/
    Equipment arr[2]= {Equipment(1), Equipment(2)};
    
    EPT Ar[10];
    for(int i = 0; i < 10; i++)
        Ar[i] = new Equipment(i);
    for(int i = 0; i < 10; i++)
        std::cout << Ar[i]->getValue() << ", ";
    std::cout << '\n';
    for(int i = 0; i < 10; i++)
        delete Ar[i];

}
