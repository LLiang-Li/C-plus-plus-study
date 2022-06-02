#include "Picture.h"

int main(int, char**) {
    char *init[] = {"Pairs", "in the", "Spring"};
    Picture p(init, 3);
    std::cout << p <<'\n';
    Picture p1 = frame(p);
    std::cout << p1 << '\n';
    Picture p2 = p | p1;
    std::cout << p2 << '\n';
    Picture p3 = p1 & p2;
    std::cout << frame(p3);
    return 0;
}
