#include<stdio.h>

int count(char *c)
{
	int i, count;
	count = 0;

	for (i = 0; c[i] != NULL; i++)
	{
		if (c[i] >= 'a'&&c[i] <= 'z' || c[i] >= 'A'&& c[i] <= 'Z' || c[i] == ' ')
			continue;
		else //�ѱ�
			count++;
	}
	return count / 2;
}

int main(void)
{
	char result[28], str[100] = "�ѱ��� Eng Jap ���� �Ƹ����";
	printf("( %s ) ����, �Լ� ���ϰ��� %d �̴� \n", str, count(str));

	int len, i;
	int ch[255] = { 0 };

	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		ch[str[i]]++;
	}
	for (i = 'a'; i <= 'z'; i++)
	{
			printf("%c : %d\n", i, ch[i]);
			//ch[i] = 0;
	}



	return 0;
}