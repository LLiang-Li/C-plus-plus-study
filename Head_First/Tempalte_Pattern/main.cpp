#include "Template_pattern.hpp"

int main(int, char**) {
   Duck* duck = new Duck[6]{
    Duck("Daffy", 8),
    Duck("Dewwy", 2),
    Duck("Howard", 7),
    Duck("Louie", 2),
    Duck("Donald", 10),
    Duck("Huey", 2),
   };

    for (int i = 0; i < 6; i++)
        std::cout << std::string(duck[i])<<"\n";

    std::cout <<"----------------------------\n";
    
    sort(duck, 0, 6);

    std::cout <<"----------------------------\n";
    for (int i = 0; i < 6; i++)
        std::cout << std::string(duck[i])<<"\n";

    delete [] duck;
    

}
