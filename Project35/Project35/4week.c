#include<stdio.h>

#if 0
int i[3][4] = { 100,200,300,400,500,600, };

int main() {
	printf("%d\n", i);
	printf("%d	%d	%d\n", i+1,&i,&i+1);
	printf("%d	%d	%d\n", i[0],i[1],i[2]);
	printf("%d	%d	%d\n", i[0]+1, i[1]+1, i[2]+1);
	printf("%d	%d	%d\n", i[0]+2, i[1]+2, i[2]+2);
	printf("%d	%d	%d\n", &i[0], &i[1], &i[2]);
	printf("%d	%d	%d\n", &i[0] + 1, &i[1] + 1, &i[2] + 1);
	printf("%d	%d	%d\n", &i[0][0], &i[1][0], &i[2][0]);
	printf("%d	%d	%d\n", i[0][0], i[1][0], i[2][0]);
}
#endif

#if 0
int main() {
	unsigned char c=128;
	if (c % 2 ==0) printf("짝수");
	else printf("홀수");

	unsigned char c = 128;
	if (c & 0x01 == 0x01) printf("홀수");
	else printf("짝수");
}
#endif

#if 0
int main() {
	int i[2][3] = { 4,2,3,6,1,5 };

	int m, tmp;	// b의 값을 저장할 변수 선언, 배열의 값을 바꿀 때 임시로 저장할 tmp 선언
	for (int a = 0; a < 2; a++)
		for (int b = 0; b < 3; b++)
		{
			m = b;	//값을 비교할 덩어리 안의 덩어리의 위치를 저장
			for (int c = a; c < 2; c++)
				for (int d = m; d < 3; d++)	//저장한 위치부터 비교 시작
				{
					if (i[a][b] > i[c][d])	//만약 앞에 있는 배열이 더 크다면 값 교환
					{
						tmp = i[a][b];	//값에 영향을 주지않고 서로 바꾸기 위해서 임시로 저장할 변수를 이용
						i[a][b] = i[c][d];
						i[c][d] = tmp;
					}
					m = 0;	//다시 0으로 초기화
				}
		}

	for (int a = 0; a < 2; a++)
		for (int b = 0; b < 3; b++)
			printf("%d ", i[a][b]);
}
#endif