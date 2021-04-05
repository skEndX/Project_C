#include<stdio.h>

int shape(char a, char b, char c) {
	int cnt = 0;
	if (a/2 <= 0 || b/2 <= 0)
	{
		return -1;
	}
	if (c==0)
	{
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < a; j++)
			{
				printf(" * ");
			}
			printf("\n");
		}
	}
	else {
		for (int i = 0; i < c; i++)
		{
			for (int j = 0; j < a; j++)
			{
				printf(" * ");
			}
			printf("\n");
		}
		for (int i = 0; i < a; i++)
		{
			for (int m = 0; m < c; m++)
			{
				printf(" * ");
			}
			for (int j = 0; j < a - 2 * c; j++)
			{
				printf(" x ");
				cnt++;
			}
			for (int k = 0; k < c; k++)
			{
				printf(" * ");
			}
			printf("\n");
		}
		for (int i = 0; i < c; i++)
		{
			for (int j = 0; j < a; j++)
			{
				printf(" * ");
			}
			printf("\n");
		}
	}
	return cnt;
}

int main() {
	printf("shape(3,4,1)의 경우 x의 갯수는 2개이어야 하며, 함수 리턴값은 %d 이다\n", shape(8, 10, 2)); // 참고로 "2개이어야 하며"는 학생이 직접쓰면 되고, 함수 리턴값과 같으면 된다.
}