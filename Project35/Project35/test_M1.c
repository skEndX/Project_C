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
	printf("shape(3,4,1)�� ��� x�� ������ 2���̾�� �ϸ�, �Լ� ���ϰ��� %d �̴�\n", shape(8, 10, 2)); // ����� "2���̾�� �ϸ�"�� �л��� �������� �ǰ�, �Լ� ���ϰ��� ������ �ȴ�.
}