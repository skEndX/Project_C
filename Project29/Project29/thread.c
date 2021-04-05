#include<stdio.h>
#include<Windows.h>

HANDLE hMutex;
int g_var;
CRITICAL_SECTION cs;

DWORD WINAPI MyThread_1(LPVOID arg) {
	for (;;)
	{
		/*WaitForSingleObject(hMutex, INFINITE);
		Sleep(1);
		g_var = 1;
		printf("Thread_1 : g_var = %d\n", g_var);
		ReleaseMutex(hMutex);*/
		EnterCriticalSection(&cs);

		//g_var = (int)*arg;
		Sleep(1);
		printf("Thread_1 : g_var = %d %d \n", g_var, g_var);
		LeaveCriticalSection(&cs);
	}
	return 0;
}



int main(int arge, char* argv[]) {
	HANDLE hThread[1];
	DWORD Threadld[1];

	hThread[0] = CreateThread(NULL, 0, MyThread_1, NULL, 0, &Threadld[0]);
	//hThread[1] = CreateThread(NULL, 0, MyThread_2, NULL, 0, &Threadld[1]);

	WaitForMultipleObjects(1, hThread, TRUE, INFINITE);

	CloseHandle(hMutex);
	return 0;
}