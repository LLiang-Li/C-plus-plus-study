#include <iostream>
class object
{
    public:
        object()
        {
            std::cout << "create object\n";
        }
        object(const object& rhs)
        {
            std::cout << "copy object\n";
        }
        ~object()
        {
            std::cout << "delete object\n";
        }
};

const object f()
{
    //object d;
    return object{};
}

void call(object i)
{

}

int main(int, char**) {
    int a;
    const int b = 10;
    a = b;
    object s ;
    s = f();
    call(s);
    return 0;
}
