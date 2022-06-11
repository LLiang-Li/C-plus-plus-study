#include "Singleton.hpp"

int main(int, char**) {
    Singleton* n = Singleton::getInstance();
    n = Singleton::getInstance();
    delete n;
}
