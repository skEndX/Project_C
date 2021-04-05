#include<stdio.h>
#include <stdlib.h>
#include<windows.h>

DWORD WINAPI Thread1(PVOID pArg);  //DWORD: double word, WINAPI:windows 스타일의 API, Thread1: 함수이름
DWORD WINAPI Thread2(PVOID pArg);

DWORD WINAPI Thread1(PVOID pArg) {
	/*int i = 1;

	while (i < 20) {
		printf("A\n");
		printf("B\n");
		printf("C\n");
		i++;
	}*/
	int random = 0; // 정수형 변수 선언

	for (int i = 0; i < 1000; i++) { // 10번 반복

		random = rand() % 1000; // 난수 생성

		printf("%d\n", random); // 출력

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

	char random = 0; // 정수형 변수 선언

	for (int i = 0; i < 1000; i++) { // 10번 반복

		random = rand() % 26 + 65; // 난수 생성

		printf("%c\n", random); // 출력

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

	while (1) {

	}
	return;
}