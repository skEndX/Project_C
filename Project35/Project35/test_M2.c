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
	char c, str[100] = "�ѱ��� Eng Jap ���� �Ƹ����";
	printf("( %s ) ���忡�� �ѱ��� 9���� �־�� �ϸ�, �Լ� ���ϰ��� %d �̴� \n", str, count(str));

	return 0;
}