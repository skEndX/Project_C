#include<stdio.h>
#include <string.h>

int strCMP(char *pA, char *pB)
{
	while (*pA != '\0' || *pB != '\0')
	{
		*pA++;
		*pB++;

		if (*pA == *pB)
		{
			continue;
		}
		else if (*pA > *pB)
		{
			if (*pA - 32 == *pB)
			{
				continue;
			}
			return 1;
		}
		else if (*pA < *pB)
		{
			if (*pA + 32 == *pB)
			{
				continue;
			}
			return -1;
		}
	}

	return 0;
}

int main(void)
{
	char a1[10] = "AA";
	char b2[10] = "AA";

	char a3[10] = "Aa";
	char b4[10] = "AA";

	char a5[10] = "Ac";
	char b6[10] = "Ab";

	char a7[100] = "there are 4 seasons in A year";
	char b8[100] = "there are 4 students in a in class";

	char a9[10] = "week";
	char b10[10] = "year";

	printf("%d\n", strCMP(a1, b2));
	if (strCMP(a1, b2) == 0)
	{
		printf("두 문자열은 동일함\n");
	}

	printf("%d\n", strCMP(a3, b4));
	if (strCMP(a3, b4) == 0)
	{
		printf("두 문자열은 동일함\n");
	}

	printf("%d\n", strCMP(a5, b6));
	if (strCMP(a5, b6) == 0)
	{
		printf("두 문자열은 동일함\n");
	}

	printf("%d\n", strCMP(a7, b8));
	if (strCMP(a7, b8) == 0)
	{
		printf("두 문자열은 동일함\n");
	}

	printf("%d\n", strCMP(a9, b10));
	if (strCMP(a9, b10) == 0)
	{
		printf("두 문자열은 동일함\n");
	}

	return 0;
}
