#include<stdio.h>

char* strcat2(char *a, char *b) {
	for (int i = 0; i < strlen(a); i++)
	{
		if (*(a+i)==' ')
		{
			while (*b)
			{
				*(a + i++) = *b++;
			}
			break;
		}
		if (i==strlen(a)-1)
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