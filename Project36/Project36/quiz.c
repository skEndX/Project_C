#include<stdio.h>

#if 0
int shape(char a, char b, char c) {
	int cnt = 0;
	if (a/2 <= c || b / 2 <= c || c<0)
	{
		return -1;
	}

	if (c == 0)
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
		for (int i = 0; i < b-2*c; i++)
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
	printf("x�� ������ %d �̴�\n", shape(4, 4, 2)); 
}
#endif

#if 0
int count(char *c)
{
	int i, count;
	count = 0;
	for (i = 0; c[i] != NULL; i++)
	{
		if (c[i] >= 'a'&&c[i] <= 'z' || c[i] >= 'A'&& c[i] <= 'Z' || c[i] == ' ')
			continue;
		else
			count++;
	}
	return count / 2;
}

int main(void)
{
	char c, str[100] = "�ѱ��� Eng Jap ���� �Ƹ����";
	printf("( %s ) ����, �Լ� ���ϰ��� %d �̴� \n", str, count(str));

	return 0;
}
#endif

#if 0
#include<stdio.h>

char* strcat2(char *a, char *b) {
	for (int i = 0; i < strlen(a); i++)
	{
		if (*(a + i) == ' ')
		{
			while (*b)
			{
				*(a + i++) = *b++;
			}
			break;
		}
		if (i == strlen(a) - 1)
		{
			while (*b)
			{
				*(a + i++) = *b++;
			}
		}
	}
	return a;
}

int main() {
	char s1[100] = "abcdef", s2[50] = "123 456";

	printf("(%s) ���ڿ��� (%s) ���ڿ��� strcat2 �Լ� ����� ", s1, s2);
	printf("(%s) �̰�, ����� s1�� ���� (%s) �̴�.", strcat2(s1, s2), s1);
}
#endif

#if 0
int setset(unsigned char *a, unsigned char *b) {
	*a = *a & 15;
	*b = *b | 15;
}

int main() {
	unsigned char a = 16;
	unsigned char b = 0;
	setset(&a, &b);

	printf("%d %d", a, b);
}
#endif