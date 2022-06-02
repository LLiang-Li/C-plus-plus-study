#include "header.h"

WSADATA wsaData;

//int jud = 1;

// void cli(SOCKET sockCon, int counter)
// {
//     std::cout << "connet:"<<counter<<std::endl;
//     char str[]="Connect success!                            !";
//     send(sockCon, str, sizeof(str), 0);
//     while (1)
//     {

//         memset(str,' ',sizeof(str));
//         int rel = recv(sockCon,str,sizeof(str),0);
//         if(rel != SOCKET_ERROR)
//         {
//             std::cout << "re:"<< counter<<std::endl;
//             send(sockCon, str, sizeof(str), 0);
//         }
//         else
//         {
//             std::cout <<"connet:"<<counter << "over"<<std::endl;
//             break;
//         }
//     }
    
// }

// void stop_while()
// {
//     while (1)
//     {
//         std::cin >>jud;
//         if (jud <=0)
//         break;
//     }
    
// }

///////////////////////////////////////

my_socket::my_socket(int po = 8888):port(po){}

void my_socket::Init()
{
    if (WSAStartup(MAKEWORD(2,2),&(wsaData)) != 0)
    {
        std::cout <<"Init Fail!";
        return;
    }
}

void my_socket::Create_socket()
{
    this->sockSrv = socket(AF_INET, SOCK_STREAM,0);
    this->addrSrv.sin_family = AF_INET;
    this->addrSrv.sin_port = htons(this->port);
    
    this->addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    int reVal = bind(sockSrv, (LPSOCKADDR)&(this->addrSrv), sizeof(SOCKADDR_IN));
    if (reVal == SOCKET_ERROR)
    {
        std::cout << "Bind fali" <<std::endl;
        return;
    }

    if (listen(sockSrv, 10) == SOCKET_ERROR)
    {
        std::cout << "Listen Fail"<<std::endl;
        return;
    }
    //std::cout <<ntohs(this->addrSrv.sin_port) <<std::endl;  
}


void my_socket::Start()
{
    while(1)
    {
        this->sockCon = accept(this->sockSrv, (SOCKADDR *)&(this->addrClien), &(this->len));
        if (this->sockCon == SOCKET_ERROR)
        {
            std::cout << "Accept:fail"<<std::endl;
        }
        else{

            std::cout << "Port:" <<ntohs(this->addrSrv.sin_port)<<" : "<<inet_ntoa(this->addrClien.sin_addr)<<":"<< ntohs(this->addrClien.sin_port) <<std::endl;
            std::thread t{&(my_socket::cli), this->sockCon, this->sockSrv, this->addrClien, this->addrSrv,counter++};
            t.detach();
        }
    }
}

void my_socket::cli(SOCKET sockCon, SOCKET sockSer, SOCKADDR_IN addrClien,SOCKADDR_IN addrSrv,int counter)
{
    std::cout << "connet:"<<counter<<std::endl;
    char str[]="Connect success!                            !";
    send(sockCon, str, sizeof(str), 0);
    while (1)
    {

        memset(str,' ',sizeof(str));
        int rel = recv(sockCon,str,sizeof(str),0);
        
        if(rel != SOCKET_ERROR)
        {
            std::cout << "Socket:" << ntohs(addrSrv.sin_port)<<" : "<<inet_ntoa(addrClien.sin_addr)<< ":"<< ntohs(addrClien.sin_port) <<std::endl;
            //std::cout <<std::string(str, sizeof(str))<<std::endl;
            std::cout << "re:"<< counter<<std::endl;
            send(sockCon, str, sizeof(str), 0);
        }
        else
        {
            std::cout <<"connet:"<<counter << "over       ";
            std::cout << "Socket:" << ntohs(addrSrv.sin_port)<<" : "<<inet_ntoa(addrClien.sin_addr)<< ":"<< ntohs(addrClien.sin_port) <<std::endl;
            break;
        }
    }
    
}
