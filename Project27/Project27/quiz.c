#include<stdio.h>
#include<windows.h>

DWORD WINAPI Thread1(PVOID pArg);  //DWORD: double word, WINAPI:windows 스타일의 API, Thread1: 함수이름
DWORD WINAPI Thread2(PVOID pArg);

DWORD WINAPI Thread1(PVOID pArg) {
	int i = 1;

	while (i < 20) {
		printf("A\n");
		printf("B\n");
		printf("C\n");
		i++;
	}
	return 0;
}

DWORD WINAPI Thread2(PVOID pArg) {
	int i = 1;

	while (i < 20) {
		printf("1\n");
		printf("2\n");
		printf("3\n");
		i++;
	}
	return 0;
}

int main() {
	HANDLE hThread1, hThread2;               // handle
	DWORD dwThreadID1 = 0, dwThreadID2 = 1;  // ID
	int i = 1;


	//Thread를 만듦
	hThread1 = CreateThread(NULL, 0, Thread1, (PVOID)0, 0, &dwThreadID1);
	CloseHandle(hThread1);

	hThread2 = CreateThread(NULL, 0, Thread2, (PVOID)0, 0, &dwThreadID2);
	CloseHandle(hThread2);

	while (i < 20) {
		printf("main\n");
		i++;
	}
	return;
}