#include<stdio.h>

int count(char *c)
{
	int i, count;
	count = 0;
	for (i = 0; c[i] != NULL; i++)
	{
		if (c[i] >= 'a'&&c[i] <= 'z' || c[i] >= 'A'&&c[i] <= 'Z' ||c[i]==0)
			continue;
		else
			count++;
	}
	return count/2-2;
}

int main(void)
{
	char c, str[100] = "한글은 Eng Jap 보다 아름답다";
	printf("( %s ) 문장에는 한글이 9글자 있어야 하며, 함수 리턴값은 %d 이다 \n", str, count(str));

	return 0;
}