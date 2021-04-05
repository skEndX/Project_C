#include<stdio.h>
#include <stdlib.h>
#include<windows.h>

DWORD WINAPI Thread1(PVOID pArg);  //DWORD: double word, WINAPI:windows ��Ÿ���� API, Thread1: �Լ��̸�
DWORD WINAPI Thread2(PVOID pArg);

DWORD WINAPI Thread1(PVOID pArg) {
	/*int i = 1;

	while (i < 20) {
		printf("A\n");
		printf("B\n");
		printf("C\n");
		i++;
	}*/
	int random = 0; // ������ ���� ����

	for (int i = 0; i < 1000; i++) { // 10�� �ݺ�

		random = rand() % 1000; // ���� ����

		printf("%d\n", random); // ���

	}
	return 0;
}

DWORD WINAPI Thread2(PVOID pArg) {
	/*int i = 1;

	while (i < 20) {
		printf("1\n");
		printf("2\n");
		printf("3\n");
		i++;
	}*/

	char random = 0; // ������ ���� ����

	for (int i = 0; i < 1000; i++) { // 10�� �ݺ�

		random = rand() % 26 + 65; // ���� ����

		printf("%c\n", random); // ���

	}
	return 0;
}

int main() {
	HANDLE hThread1, hThread2;               // handle
	DWORD dwThreadID1 = 0, dwThreadID2 = 1;  // ID
	int i = 1;


	//Thread�� ����
	hThread1 = CreateThread(NULL, 0, Thread1, (PVOID)0, 0, &dwThreadID1);
	CloseHandle(hThread1);

	hThread2 = CreateThread(NULL, 0, Thread2, (PVOID)0, 0, &dwThreadID2);
	CloseHandle(hThread2);

	while (1) {

	}
	return;
}