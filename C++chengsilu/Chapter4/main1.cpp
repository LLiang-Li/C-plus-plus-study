#include <iostream>
class de
{
    public:
        de():data(0){std::cout<<"de()\n";}
        de(int num):data(num){std::cout<<"de(int)\n";}
        de(const de &rhs){std::cout << "de(const &de)\n";this->data = rhs.data;}
        int get_data()const{return this->data;}

        de& operator=(const de & rhs)
        {
            std::cout << "op=\n";
            this->data = rhs.data;
            return *this;
        }
        // de operator+(const de &rhs)
        // {
        //     std::cout <<"oper+\n";
        //     this->data+=rhs.data;
        //     return *this;
        // }
    private:
        int data;
};

de operator+(const de &num1, const de&num2)
{   std::cout <<"oper+(de,ded)\n";
    return de(num1.get_data()+num2.get_data());
}


int main()
{
    de l(1),k(2);
    de j = l+k+k;
    std::cout <<j.get_data()<<'\n';
    j = k;
    std::cout <<l.get_data()<<'\n';
    std::cout <<j.get_data()<<'\n';


    
    return 0;
}