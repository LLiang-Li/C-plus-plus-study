#include <stdlib.h>
#include <windows.h>
#include<stdio.h>
typedef double real_T;

int main(int argc, char const* argv[])
{
    void(*step_func)(real_T*, real_T*) = NULL;
  

    HMODULE module = LoadLibraryA("Dll.dll");
    if (module == NULL)
    {
        system("error load");
    }

    step_func = (void(*)(real_T*, real_T*))GetProcAddress(module, "step_func");
  

    if (step_func != NULL)
    {
        real_T in, out;
        in = -20;
        step_func(&in, &out);
        printf("%f", out);
    }
    else {
        system("function p_test_print can not excute");
    }
    
    FreeLibrary(module);
    system("pause");
    return 0;
}
