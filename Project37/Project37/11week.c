#include<stdio.h>

char* strNcpy(char* s1, char* s2, int n)
{
	char* tmp = s1;
	//복사할 문자열이 0개보다 적거나 문자열이 길이를 넘을 때
	if (n < 0 || strlen(s2) <n ) return -1;

	else {
		for (int i = 0; i < n; i++)
		{
			s1[i] = s2[i];
		}
	}
	return tmp; //포인터 리턴
}

int main()
{
	char str1[20] = "qweqwe";
	char str2[20] = "Hello000000000000000";

	printf("%d\n", strNcpy(str1, str2, 19));
	printf("%s\n", str1);

	return 0;
}

#if 0
int strNcpy(char *s1, char *s2, char n) {
	int i;
	//복사할 문자열이 0개보다 적거나 문자열이 길이를 넘을 때
	if (n < 0 || strlen(s2) < n) i = 0;	//성공여부 실패

	else {
		for (i = 0; i < n; i++)
		{
			s1[i] = s2[i];
		}
		i = 1;	//성공여부 성공
	}
	return i;
}

int main()
{
	char str1[20] = "dfdfdf";
	char str2[20] = "Hello";

	printf("%d\n", strNcpy(str1, str2, 4));
	printf("%s\n", str1);

	return 0;
}
#endif

#if 0
char* strNcpy(char* s1, char* s2, int n)
{
	char* tmp = s1;
	//복사할 문자열이 0개보다 적거나 문자열이 길이를 넘을 때
	if (n < 0 || strlen(s2) < n) return -1;

	else {
		for (int i = 0; i < n; i++)
		{
			s1[i] = s2[i];
		}
	}
	return tmp; //포인터 리턴
}

int main()
{
	char str1[20] = "";
	char str2[20] = "Hello";

	printf("%d\n", strNcpy(str1, str2, 4));
	printf("%s\n", str1);

	return 0;
}
#endif

//int strNcpy(char* dest, const char* src, char maxlen)
//{
//	int i = 0;
//	while (src[i] != '\0' && i < maxlen)
//	{
//		dest[i] = src[i];
//		i++;
//	}
//	while (i < maxlen)
//	{
//		dest[i] = '\0';
//		i++;
//	}
//
//	return &dest[0];
//}

#if 0
char* strNcpy(char* s1, char* s2, int n)
{
	char* tmp = s1;

	for (int i=0; i < n; i++)
	{
		s1[i] = s2[i];
	}
	return tmp;
}
#endif

//char* strNcpy(char *dest, const char *source, char n) {
//	char *tmp = dest;
//
//	while (n && (*dest++ = *source++)) n--;
//	if (n) while (--n) *dest++ = '\0';
//
//	return tmp;
//}
