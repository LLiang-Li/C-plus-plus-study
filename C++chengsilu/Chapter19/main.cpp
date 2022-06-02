#include <iostream>

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
    char* hello = "Hello ";
    char* world = "World";
    char message[15];
    char *p = message;
    p = copy(hello, hello+6, p);
    //p = copy(world, world+5,p);
    *p = '\0';
    std::cout << message;
    return 0;
}
