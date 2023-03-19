#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"ws2_32.lib")

int main(void)
{
	//初始化wsa
	WORD sockVision = MAKEWORD(2, 2);
	WSADATA wsadata;
	//其他变量
	SOCKET serSocket;
	struct sockaddr_in remoteAddr;
	struct sockaddr_in sin;
	int ret = -1;
	int nAddrlen = sizeof(remoteAddr);
	double revdata[255];
	double senddata[3] = { 0 };

	if (WSAStartup(sockVision, &wsadata) != 0)
	{
		printf("WSA初始化失败\n");
		return 0;
	}

	//创建套接字
	serSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (serSocket == INVALID_SOCKET)
	{
		printf("socket服务器创建失败\n");
		return 0;
	}

	//绑定IP和端口
	sin.sin_family = AF_INET;
	sin.sin_port = htons(9091);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if (bind(serSocket, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("绑定IP和端口\n");
		return 0;
	}
	printf("start\n");
	//循环接收数据
	while (1)
	{
		ret = recvfrom(serSocket, revdata, 255, 0, (SOCKADDR*)&remoteAddr, &nAddrlen);
		if (ret > 0)
		{
			revdata[ret] = 0x00;
			printf("接收到一个连接：%s \n", inet_ntoa(remoteAddr.sin_addr));
			printf("\n");
			printf("客户：");
			printf("%f",revdata[0]);
			printf("\n");
		}

		if (strcmp(revdata, "bye") == 0)
			break;
		
		//发送数据
		printf("我：");
		double temp;
		scanf("%lf", &temp);
		senddata[0] = temp;
		sendto(serSocket, senddata, strlen(senddata), 0, (SOCKADDR*)&remoteAddr, nAddrlen);
	}

	closesocket(serSocket);
	WSACleanup();
	return 0;
}
