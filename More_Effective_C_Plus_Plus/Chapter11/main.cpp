#include <iostream>
#include <exception>

class Session
{
    public:
        Session(){
            this->logCreation(this);
        }
        ~Session(){
            this->logDestruct(this);
        }
        static void logCreation(Session *objAddr);
        static void logDestruct(Session *objAddr);
};

void Session::logCreation(Session *objAddr)
{
    std::cout<< "create Session\n";
    throw "cerate error";
}

void Session::logDestruct(Session *objAddr)
{
    std::cout<< "destruct Session\n";
    throw "error";
}

int main(int, char**) {
    try
    {
        Session s;
    }
    catch(char const * str)
    {
        std::cout << "123" <<std::endl;
    }
    return 0;
}
