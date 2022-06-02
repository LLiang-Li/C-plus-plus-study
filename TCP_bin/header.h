#ifndef HEADER
#define HEADER

#include <iostream> 
#include <sstream>
#include <stdlib.h>
#include "winsock2.h"
#include <cstdlib>
#include <thread>
#include <string>
#pragma comment(lib,"ws2_32.lib")

//extern int jud;

//extern void cli(SOCKET sockCon, int counter);

//extern void stop_while();

class my_socket;

using f_p = void(my_socket::*)(SOCKET,int);
using ff = void(*)();

class my_socket
{
    public:
        my_socket():port{8888}{};
        my_socket(int);
        void Create_socket();
        void Start();

        static void Init();
        static void cli(SOCKET, SOCKET, SOCKADDR_IN, SOCKADDR_IN,int);
    private:
        SOCKET sockSrv, sockCon;
        SOCKADDR_IN addrSrv, addrClien;
        int len = sizeof(SOCKADDR);
        int counter = 1;
        int port;
};

#endif