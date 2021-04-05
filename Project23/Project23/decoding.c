#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *cal(char*p_str) {
	int *lps = (int *)malloc(sizeof(int)*strlen(p_str));
	memset(lps, 0, sizeof(int)*strlen(p_str));

	int p_length = strlen(p_str);

	int j = 0;

	for (int i = 1; i < p_length; i++)
	{
		while (j>0 && p_str[i]!=p_str[j])
		{
			j = lps[j - 1];
		}
		if (p_str[i]==p_str[j])
		{
			j++;
			lps[i] = j;
		}
	}
	return lps;
}

int main() {
	char t_str[1000] = "";
	scanf("%s", t_str);
	char p_str[1000] = "";
	scanf("%s", p_str);

	int t_length = strlen(t_str);
	int p_length = strlen(p_str);

	int *lps = cal(p_str);
	int j = 0;
	for (int i = 0; i < t_length; i++)
	{
		while (j>0 && t_str[i]!=p_str[j])
		{
			j = lps[j - 1];
		}
		if (p_str[j]==t_str[i])
		{
			if (j==p_length-1)
			{
				printf("%d\n", i - j);
				j = 0;
			}
			else
			{
				j++;
			}
		}
	}
}