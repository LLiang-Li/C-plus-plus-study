#include"proxy_pattern.hpp"

int main(int, char**) {
    PersonBeanImpl* per = new PersonBeanImpl();
    per->setName("lige");
    per->setGender("man");
    per->setInterests("liliangliang");
    per->setHotOrNotRating(1);
    std::cout << std::string(*per); 

    Proxy_Myself * my = new Proxy_Myself(per);
    Proxy_Other * ot = new Proxy_Other(per);
    ot->setHotOrNotRating(10);
    std::cout << std::string(*per); 
    my->setName("ge");
    std::cout << std::string(*per); 
    delete per;
    delete my;
    delete ot;
    return 0;
}
