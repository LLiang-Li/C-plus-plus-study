#define MAX 4
#if(MAX == 1)
    #include "BookEntry.h"
#elif(MAX == 2)
    #include "BookEntry_with_exception.h"
#elif(MAX == 3)
    #include "BookEntry_private_function.h"
#else
    #include "BookEntry_with_autoptr.h"
#endif

int main(int, char**) {
    
    BookEntry* s = NULL;
    try
    {
        s = new BookEntry("lige");
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
        std::cout << "catch\n";
    }
    
    delete s;
    return 0;
}

