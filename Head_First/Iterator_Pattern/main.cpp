#include"Iterator_patter.hpp"

int main(int, char**) {
    PancakeHouseMenu* pan = new PancakeHouseMenu;
    // std::vector<MenuItem*> it = pan->getMenuItems();

    // for(auto i : it)
    // {
    //     std::cout << std::string(*i);
    // }
    // std::cout << "-------------------------\n";

    Waitress * nW = new Waitress(pan);
    nW->printMenu();
    
    delete nW;
}
