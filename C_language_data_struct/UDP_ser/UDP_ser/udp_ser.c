#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"ws2_32.lib")

int main(void)
{
	//��ʼ��wsa
	WORD sockVision = MAKEWORD(2, 2);
	WSADATA wsadata;
	//��������
	SOCKET serSocket;
	struct sockaddr_in remoteAddr;
	struct sockaddr_in sin;
	int ret = -1;
	int nAddrlen = sizeof(remoteAddr);
	double revdata[255];
	double senddata[3] = { 0 };

	if (WSAStartup(sockVision, &wsadata) != 0)
	{
		printf("WSA��ʼ��ʧ��\n");
		return 0;
	}

	//�����׽���
	serSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (serSocket == INVALID_SOCKET)
	{
		printf("socket����������ʧ��\n");
		return 0;
	}

	//��IP�Ͷ˿�
	sin.sin_family = AF_INET;
	sin.sin_port = htons(9091);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if (bind(serSocket, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("��IP�Ͷ˿�\n");
		return 0;
	}
	printf("start\n");
	//ѭ����������
	while (1)
	{
		ret = recvfrom(serSocket, revdata, 255, 0, (SOCKADDR*)&remoteAddr, &nAddrlen);
		if (ret > 0)
		{
			revdata[ret] = 0x00;
			printf("���յ�һ�����ӣ�%s \n", inet_ntoa(remoteAddr.sin_addr));
			printf("\n");
			printf("�ͻ���");
			printf("%f",revdata[0]);
			printf("\n");
		}

		if (strcmp(revdata, "bye") == 0)
			break;
		
		//��������
		printf("�ң�");
		double temp;
		scanf("%lf", &temp);
		senddata[0] = temp;
		sendto(serSocket, senddata, strlen(senddata), 0, (SOCKADDR*)&remoteAddr, nAddrlen);
	}

	closesocket(serSocket);
	WSACleanup();
	return 0;
}
