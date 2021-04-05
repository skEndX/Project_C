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

	printf("(%s) 문자열과 (%s) 문자열의 strcat2 함수 결과는 ", s1, s2);            
	printf("(%s) 이고, 변경된 s1의 값도 (%s) 이다.", strcat2(s1, s2), s1);
}