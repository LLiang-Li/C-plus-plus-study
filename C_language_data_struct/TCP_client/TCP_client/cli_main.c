#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")  
#define Size 5

//���� ws2_32.dll
int main() {
    //��ʼ��DLL
         
        WSADATA wsaData;
        WSAStartup(MAKEWORD(2, 2), &wsaData);
        //�����׽���

        SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        
        SOCKET sock1 = sock;
        //���������������

        struct sockaddr_in sockAddr;
        memset(&sockAddr, 0, sizeof(sockAddr));  //ÿ���ֽڶ���0���
        sockAddr.sin_family = AF_INET;
        sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        sockAddr.sin_port = htons(8088);

              
        int flag = connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
        //���շ��������ص�����
        //printf("%d", flag);
        char szBuffer[Size] = { 0 };
        if (!flag)
            printf("���ӳɹ�\n");
        else
        {
            printf("����ʧ�ܣ�����ֵ��%d\n",flag);
        }
        //int index = 1;
        FILE* fp;
        //fp = fopen("D:\\Desktop\\plot_figures\\a.txt", "w+");

        while (!flag && 1) {

            if (recv(sock, szBuffer, sizeof(szBuffer) / sizeof(char), NULL)) {
                //������յ�������
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
             //   printf("����");
              //  break;
        }
         
        printf("������");
        //fclose(fp);
            //�ر��׽���
            //closesocket(sock);
            //��ֹʹ�� DLL
        WSACleanup();
        
   
    return 0;
}