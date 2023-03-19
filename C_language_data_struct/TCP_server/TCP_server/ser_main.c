#define  _WINSOCK_DEPRECATED_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <winsock2.h>
#pragma comment (lib, "ws2_32.lib")  //加载 ws2_32.dll
#define target_IP "127.0.0.1"

int main() {
    //初始化 DLL
    WSADATA wsaData;
    
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    //创建套接字 PF_INET:IPv4
    
    SOCKET servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    printf("创建嵌套字\n");
    //绑定套接字
    struct sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充

    sockAddr.sin_family = AF_INET;  //使用IPv4地址
    sockAddr.sin_addr.s_addr = inet_addr(target_IP);  //具体的IP地址
    sockAddr.sin_port = htons(8088);  //端口


    bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    printf("绑定SOCKET\n");
    //进入监听状态

    listen(servSock, 20);
    printf("监听端口\n");
    //接收客户端请求
    SOCKADDR clntAddr;
    int nSize = sizeof(SOCKADDR);
    printf("创建嵌套字\n");
    printf("------------------\n");
    int xy = 0;

        SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);
        printf("响应%d\n",++xy);
        //向客户端发送数据
        while (1) {
            char* str[200];
            scanf("%s", str);
            
            send(clntSock, str, strlen(str) + sizeof(char), NULL);
            printf("发送数据\n");
            printf("-------------------\n");
            if (!strcmp(str, "end"))
                break;
            //system("pause");
        }
        //关闭套接字
        closesocket(clntSock);

    
    closesocket(servSock);
    //终止 DLL 的使用
    WSACleanup();
    return 0;
}
