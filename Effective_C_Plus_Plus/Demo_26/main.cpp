#include <iostream>
#include <string>
#include <exception>

std::string encryptPasswd(const std::string &passwd)
{
    if (passwd.length() < 5)
    {
        throw std::logic_error("Passwd is too short!");
    }
    return passwd;
}

class base{
    public:
        int a;
};

class sub: public base{
    public:
        sub(int a1 = 0){
            base::a = a1;
        }
        int b;
};


int main(int, char**) {
    // std::cout << "Hello, world!\n";
    // std::string str{"123"};
    // std::cout <<str.length();

    sub b{2};
    base *p = &b;
    std::cout <<"&b = "<<&b <<"p = "<<p<<'\n';
}
