#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"ws2_32.lib")


int main(void)
{
	WORD sockVision = MAKEWORD(2, 2);
	WSADATA wsadata;
	SOCKET sclient;
	struct sockaddr_in clientAddr;
	char senddata[255];
	char revdata[255];
	int ret = -1;
	int len = -1;
	if (WSAStartup(sockVision, &wsadata) != 0)
	{
		printf("WSA初始化失败\n");
		return 0;
	}

	sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sclient == INVALID_SOCKET)
	{
		printf("socket客户端创建失败\n");
		return 0;
	}

	clientAddr.sin_family = AF_INET;
	clientAddr.sin_port = htons(9092);
	clientAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	len = sizeof(clientAddr);

	while (1)
	{
		printf("我：");
		scanf("%s", senddata);
		sendto(sclient, senddata, strlen(senddata), 0, (SOCKADDR*)&clientAddr, len);
		if (strcmp(senddata, "bye") == 0)
			break;
		ret = recvfrom(sclient, revdata, 255, 0, (SOCKADDR*)&clientAddr, &len);
		if (ret > 0)
		{
			revdata[ret] = 0x00;
			printf("\n");
			printf("服务器：");
			printf(revdata);
			printf("\n");
		}
	}

	closesocket(sclient);
	WSACleanup();

	system("pause");
	return 0;
}
