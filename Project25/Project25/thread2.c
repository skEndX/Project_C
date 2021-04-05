#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX 20

DWORD WINAPI ThreadFunc(LPVOID n)
{
	//����ȭ�� ���� �ʱ� ���� volatile ���
	for (volatile int i = 0; i < 1000000000; i++);	
	return 0;
}

int main() {
	clock_t start, finish;
	double time;
	DWORD thread;
	HANDLE thrd[MAX];

	int i;
	start = clock();//���� �ð� ��ȯ

	for (i = 0; i < MAX; i++) {
		thrd[i] = CreateThread(NULL, 0, ThreadFunc, (LPVOID)i, 0, &thread);
	}

	//thread�� �� ���� ������ ��ٸ�
	//WaitForMultipleObjects(MAX, thrd, TRUE, INFINITE);	

	for (i = 0; i < MAX; i++) {
		CloseHandle(thrd[i]);	//������ �ڵ��� ����
	}
	//���� �ð�
	finish = clock();

	//CLOCKS_PER_SEC�� ������ -> �� ������ �ٲٱ� ���ؼ�
	//thread�� �����Ǵµ� �ҿ��� �ð�
	time = (double)(finish - start) / CLOCKS_PER_SEC;	
	printf("�ҿ�ð� : %f ��\n", time);
	return 0;
}
