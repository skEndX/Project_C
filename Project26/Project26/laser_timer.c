#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>	/* clock ������ ���� window ���̺귯�� ��� */

void OFF();	/* state �Լ� ���� */
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
	x = 0;	/* output ���� */
	printf("OFF State	x = %d \n",x);

	scanf("%d", &b);	/* b input Ȯ�� */
	if (b == 0)	/* input�� �ȵ����� ��*/
	{
		Sleep(1000);	/* clock */
		OFF();
	}
	else if(b==1)	/* input�� ������ �� */
	{
		b = 0; /* �Է��� ���� */
		Sleep(1000);
		ON1();	/* ���� state */
	}

}
void ON1()
{
	x = 1; /* ouput ���� */
	printf("Switch 1 ON	x = %d \n", x);
	Sleep(1000);	/* clock */
	ON2();	/* ���� state */
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