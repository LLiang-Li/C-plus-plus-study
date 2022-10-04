#include "Widget.h"

void passANDThrowWidget()
{
    Widget localwidget;
    std::cin >> localwidget;
    
    throw localwidget; // throw 会复制一份，不要抛局部指针
}

int main(int, char**) {
    // try
    // {
    //     passANDThrowWidget();
    // }
    // catch( Widget& e)
    // {
    //     for (int i = 0 ; i < 1000000;i++);
    //     std::cout << e;
    // }

    int i;
    std::cin >> i;
    std::cout << i << '\n';
    char num = 0;
    try {
        num = -1;
    }
    catch(std::exception &e)
    {
        std::cout << "123\n";
        std::cout << e.what()<<'\n';
    }
    return 0;
}
