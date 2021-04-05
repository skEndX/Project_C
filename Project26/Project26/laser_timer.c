#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>	/* clock 생성을 위해 window 라이브러리 사용 */

void OFF();	/* state 함수 선언 */
void ON1();
void ON2();
void ON3();

int b;	/* input */
int x; /* output */

int main(void)
{
	b = 0;
	OFF();

	return 0;
}

void OFF()
{
	x = 0;	/* output 설정 */
	printf("OFF State	x = %d \n",x);

	scanf("%d", &b);	/* b input 확인 */
	if (b == 0)	/* input이 안들어왔을 때*/
	{
		Sleep(1000);	/* clock */
		OFF();
	}
	else if(b==1)	/* input이 들어왔을 때 */
	{
		b = 0; /* 입력을 내림 */
		Sleep(1000);
		ON1();	/* 다음 state */
	}

}
void ON1()
{
	x = 1; /* ouput 설정 */
	printf("Switch 1 ON	x = %d \n", x);
	Sleep(1000);	/* clock */
	ON2();	/* 다음 state */
}
void ON2()
{
	x = 1;
	printf("Switch 2 ON	x = %d \n", x);
	Sleep(1000);
	ON3();
}
void ON3()
{
	x = 1;
	printf("Switch 3 ON	x = %d \n", x);
	Sleep(1000);
	OFF();
}