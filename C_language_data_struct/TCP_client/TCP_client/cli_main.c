#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")  
#define Size 5

//加载 ws2_32.dll
int main() {
    //初始化DLL
         
        WSADATA wsaData;
        WSAStartup(MAKEWORD(2, 2), &wsaData);
        //创建套接字

        SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        
        SOCKET sock1 = sock;
        //向服务器发起请求

        struct sockaddr_in sockAddr;
        memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
        sockAddr.sin_family = AF_INET;
        sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        sockAddr.sin_port = htons(8088);

              
        int flag = connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
        //接收服务器传回的数据
        //printf("%d", flag);
        char szBuffer[Size] = { 0 };
        if (!flag)
            printf("连接成功\n");
        else
        {
            printf("连接失败，返回值：%d\n",flag);
        }
        //int index = 1;
        FILE* fp;
        //fp = fopen("D:\\Desktop\\plot_figures\\a.txt", "w+");

        while (!flag && 1) {

            if (recv(sock, szBuffer, sizeof(szBuffer) / sizeof(char), NULL)) {
                //输出接收到的数据
                //printf("Message form server: %s\n", szBuffer);
                //printf("%d", index++);
            }
            else
                break;
            //fputs(szBuffer, fp);
            //printf("%d\n", szBuffer[0] == '\0');
            //index++;
            //if ((szBuffer[0] == '\0') && (szBuffer[1] == '\0') && (szBuffer[2] == '\0')
            //    && (szBuffer[3] == '\0') && (szBuffer[4] == '\0') && (szBuffer[5] == '\0')
            //   && (szBuffer[6] == '\0') && (szBuffer[7] == '\0') && (szBuffer[8] == '\0')
            //    && (szBuffer[9] == '\0'))
            //    if (0)
            //{
             //   printf("结束");
              //  break;
        }
         
        printf("结束！");
        //fclose(fp);
            //关闭套接字
            //closesocket(sock);
            //终止使用 DLL
        WSACleanup();
        
   
    return 0;
}