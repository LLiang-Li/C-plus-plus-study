#include <iostream>
#include <string>

class CompanyA
{
    public:
        void sendclear(const std::string &msg)
        {
            std::cout <<"A\n";
            std::cout <<msg<<"\n";
        }
};

class CompanyB
{
    public:
        void sendclear(const std::string &msg)
        {
            std::cout <<"B\n";
             std::cout <<msg<<"\n";
        }
};


class Msg{public: std::string mag{"str"};};

template <typename company>
class msgsend
{
    public:
        void Send_m(const Msg &info)
        {
            
            company c;
            c.sendclear(info.mag);
        }
};

template<typename company>
class logg: public msgsend<company>
{
    public:
        //方案二
        using msgsend<company>::Send_m;
        void send_data(const Msg &info)
        {
            //错误，msgsend是模板，没有实例化，没办法直接调用
            //Send_m(info)  
            //方案一，使用this指针
            //this->Send_m(info);
            //方案二
            //Send_m(info);
            //方案三
            msgsend<company>::Send_m(info);
        }
};

int main(int, char**) {

    Msg str{"1234"};
    logg<CompanyB>{}.send_data(str);
    logg<CompanyA>{}.send_data(str);
    logg<CompanyA>{}.Send_m(str);
    std::cout << "Hello, world!\n";
}
