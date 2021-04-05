#include<stdio.h>

#if 0
int main() {
	char a, b;

	for (a = 3; a < 7; a++)
	{
		for (b = 1; b < 10; b++)
		{
			printf("%d x %d = %d\n", a, b, a*b);
		}
		printf("\n");
	}
}
#endif

#if 0
int main() {
	int a = 8;	//세로 값
	int b = 10;	//가로 값

	for (int i = 0; i < a; i++)
	{
		printf("#");
		for (int j = 1; j < b - 1; j++)
		{
			if (i == 0 || i == a - 1)	printf(" # ");
			else printf(" 0 ");
		}
		printf("#\n");
	}
}
#endif

#if 0
int main() {
	int a = 10;
	int b = 30;
	int c = 60;
	int d = 100;

	int *p[4] = { &a,&b,&c,&d };	//포인터 배열을 이용하여 변수들의 주소 저장
	int *min;	//가장 작은 주소를 저장할 포인터 변수 선언

	min = (p[0] < p[1]) ? p[0] : p[1];	//삼항연산자를 이용하여 최소 번지를 구함
	min = (min < p[2]) ? min : p[2];
	min = (min < p[3]) ? min : p[3];

	//printf("%d\n", min);
	//printf("%d\n\n", *min+1);
	*min = *min + 1;
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", *p[i]);
	}
}
#endif

#if 0	//배열은 당연히 가장 첫번째가 작으니까 이거 물어보고
int main() {
	int data[4] = { 10,30,60,100 };

	int *p[4] = { &data[0],&data[1],&data[2],&data[3] };	//포인터 배열을 이용하여 변수들의 주소 저장
	int *min;	//가장 작은 주소를 저장할 포인터 변수 선언

	min = (p[0] < p[1]) ? p[0] : p[1];	//삼항연산자를 이용하여 최소 번지를 구함
	min = (min < p[2]) ? min : p[2];
	min = (min < p[3]) ? min : p[3];

	//printf("%d\n", min);
	//printf("%d\n\n", *min+1);
	*min = *min + 1;
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", *p[i]);
	}
}
#endif

int main() {
	unsigned char A = 0xA8;
	unsigned char B = 0x7F;
	unsigned char A_value = A;

	A = (A & 0xF0) | (B & 0x0F);
	B = (B & 0xF0) | (A_value & 0x0F);
	printf("0x%02X\n", A);
	printf("0x%02X\n", B);
}