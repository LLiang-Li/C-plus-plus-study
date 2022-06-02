#include "header.h"



int main()
{
    my_socket::Init();
    auto sock_crate([](int po){
        my_socket so(po);
        so.Create_socket();
        so.Start();
    });

    // int a = 8888;
    // sock_crate(a);

    std::thread t1{sock_crate,8888};
    std::thread t2{sock_crate,9999};
    t1.join();
    t2.join();
    
}

// int main()
// {
//     WSADATA wsaData;
//     int port = 8888;
//     /*初始化链接库*/
//     if (WSAStartup(MAKEWORD(2,2),&wsaData) != 0)
//     {
//         std::cout <<"Init Fail!";
//         return 0;
//     }
//     /*创建socket*/
//     SOCKET sockSrv, sockCon;
//     sockSrv = socket(AF_INET, SOCK_STREAM,0);

//     /*绑定*/
//     SOCKADDR_IN addrSrv, addrClien;
//     addrSrv.sin_family = AF_INET;
//     addrSrv.sin_port = htons(port);
//     addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
//     int reVal = bind(sockSrv, (LPSOCKADDR)&addrSrv, sizeof(SOCKADDR_IN));
//     if (reVal == SOCKET_ERROR)
//     {
//         std::cout << "Bind fali" <<std::endl;
//         return 0;
//     }

//     /*监听*/

//     if (listen(sockSrv, 10) == SOCKET_ERROR)
//     {
//         std::cout << "Listen Fail"<<std::endl;
//         return 0;
//     }

//     /*接受*/
    
//     int len = sizeof(SOCKADDR);
//     int counter = 1;

//     std::thread s{stop_while};
//     s.detach();

//     while (1)
//     {
//         //std::cout << "accept" << std::endl;
//         if (jud <=0)
//             break;
//         sockCon = accept(sockSrv, (SOCKADDR *)&addrClien, &len);
//         if (jud <=0)
//             break;
//         if (sockCon == SOCKET_ERROR)
//         {
//             std::cout << "Accept:fail"<<std::endl;
//         }
//         else{

//             std::cout <<inet_ntoa(addrClien.sin_addr)<<":"<< addrClien.sin_port <<std::endl;
//             // std::thread t{cli, sockCon, counter++};
//             // t.detach();


//         }
//         if (jud <=0)
//             break;   
//     }
// }