#define  _WINSOCK_DEPRECATED_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <winsock2.h>
#pragma comment (lib, "ws2_32.lib")  //���� ws2_32.dll
#define target_IP "127.0.0.1"

int main() {
    //��ʼ�� DLL
    WSADATA wsaData;
    
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    //�����׽��� PF_INET:IPv4
    
    SOCKET servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    printf("����Ƕ����\n");
    //���׽���
    struct sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //ÿ���ֽڶ���0���

    sockAddr.sin_family = AF_INET;  //ʹ��IPv4��ַ
    sockAddr.sin_addr.s_addr = inet_addr(target_IP);  //�����IP��ַ
    sockAddr.sin_port = htons(8088);  //�˿�


    bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    printf("��SOCKET\n");
    //�������״̬

    listen(servSock, 20);
    printf("�����˿�\n");
    //���տͻ�������
    SOCKADDR clntAddr;
    int nSize = sizeof(SOCKADDR);
    printf("����Ƕ����\n");
    printf("------------------\n");
    int xy = 0;

        SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);
        printf("��Ӧ%d\n",++xy);
        //��ͻ��˷�������
        while (1) {
            char* str[200];
            scanf("%s", str);
            
            send(clntSock, str, strlen(str) + sizeof(char), NULL);
            printf("��������\n");
            printf("-------------------\n");
            if (!strcmp(str, "end"))
                break;
            //system("pause");
        }
        //�ر��׽���
        closesocket(clntSock);

    
    closesocket(servSock);
    //��ֹ DLL ��ʹ��
    WSACleanup();
    return 0;
}
