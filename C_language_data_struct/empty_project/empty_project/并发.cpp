#include<stdio.h>
#include<windows.h>
int a = 0;
void Thread1()
{
	while (1)

	{

		//system("title %time%");
		printf("%d\n", a++);
		if (a == 100)
			a = 0;
	}
}

void main(int argc, char* argv[])
{
	HANDLE hThread;
	DWORD ThreadID;
	hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread1, NULL, 0, &ThreadID);
	getchar();
}