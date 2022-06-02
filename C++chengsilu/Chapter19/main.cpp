#include <iostream>
#include "const_iter.hpp"
#include "output.hpp"

template<class In, class Out>
Out copy(In start, In end, Out dest)
{
    while (start != end )
    {
        *dest++ = *start++;
    }
    return dest;
    
}


int main(int, char**) {
    // char* hello = "Hello ";
    // char* world = "World";
    // char message[15];
    // char *p = message;
    // p = copy(hello, hello+6, p);
    //p = copy(world, world+5,p);
    // *p = '\0';
    // std::cout << message;

    //
    // int x[100];
    // Constant_iterator c(100);

    // copy(c, c + 100, x);

    // for (int i = 0; i < 100; i++)
    //     std::cout << x[i]<<", ";
    // std::cout << '\n';

    ostream_iter<int> o(std::cout, "\n");
    Constant_iterator c(42);
    copy(c, c+10, o);

    return 0;

}
