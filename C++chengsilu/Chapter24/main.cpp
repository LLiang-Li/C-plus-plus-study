#include <iostream>
//C library
#include <stdio.h>
#include <dirent.h>

//
#include "Dir_List.hpp"

int main(int, char**) {
    //
    //C Language
    // DIR *dp = opendir(".");
    // struct dirent *d;
    // while (d = readdir(dp))
    // {
    //     printf("%s\n",d->d_name);
    // }
    // closedir(dp);
    //
    Dir pr(".");
    dirent d;
    while (pr.read(d))
    {
        std::cout << d.d_name<<'\n';
    }
    

    return 0;
}
