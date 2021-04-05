#include<stdio.h>

#if 0
void change(int *a, int *b) {
	int temp = *a;	//해당 주소의 값을 change 해야하므로 *을 붙임
	*a = *b;
	*b = temp;
}

int main() {
	int i = 3, j = 5, k[6] = { 1,2,3,0,5,6 };

	change(&i, &j);
	for (int m = 0; m < sizeof(k) / sizeof(k[0]); m++)
	{
		if (k[m] == 0) { //0 데이터가 나오면
			for (int l = 0; l < m / 2; l++)
				change(&k[l], &k[m - 1 - l]);
			break; //끝으로 간주
		}
		if (m == sizeof(k) / sizeof(k[0]) - 1) return -1; //0 데이터가 없다면 -1로 종료
	}

	printf("i = %d, j = %d\n", i, j);
	for (int n = 0; n < sizeof(k) / sizeof(k[0]); n++)
		printf("%d ", k[n]);
}
#endif

#if 0
int main() {
	int data[6] = { 0,100,200,300,400,500 };
	char *p;
	int i = 0;

	for (int j = 0; j < 6; j++)
	{
		p = &data[j];
		for (int k = 3; k >= 0; k--)
		{
			i = i << 8;	//shift로 1바이트를 밈
			i |= *(p + k); //OR 비트연산으로 합침
		}
		printf("1차원 배열 data의 %d번째 데이터는 %d입니다.\n", j, i);
	}
}
#endif

#if 0
int main() {
	int data[6] = { 10,20,30,40,50,60 };
	char *p = &data;	//포인터 변수 p에 data 배열의 주소를 넣음

	for (int i = 0; i < 6; i++)	//-5씩 뺌
		*(p + i*4) = *(p + i*4) - 5; //포인터 p는 char로 1바이트, data배열은 int로 4바이트이므로 *4를 해줌

	for (int i = 0; i < 6; i++)
		printf("%d ", data[i]);
}
#endif

#if 0
int main() {
	int data[6] = { 10,20,30,40,50,60 };
	int *p = &data;	//포인터 변수 p에 data 배열의 주소를 넣음

	for (int i = 0; i < 6; i++)	//-5씩 뺌
		*(p + i) = *(p + i) - 5;

	for (int i = 0; i < 6; i++)
		printf("%d ", data[i]);
}
#endif

#if 0
int main() {
	unsigned char data[6] = { 10,20,30,40,50,60 };
	unsigned char *p = &data;	//포인터 변수 p에 data 배열의 주소를 넣음

	for (int i = 0; i < 6; i++)	//-5씩 뺌
		*(p + i) = *(p + i) - 5;

	for (int i = 0; i < 6; i++)
		printf("%d ", data[i]);
}
#endif

#if 0
int main() {
	unsigned int i = 515;
	unsigned char c = 276, *p = (unsigned char *)&i;
	*p = c;

	printf("%d", i);
}
#endif