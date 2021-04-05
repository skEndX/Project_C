#include<stdio.h>

int is_hangul(unsigned char st[]) {
	for (int i = 0; st[i] != NULL; i++)
	{
		//0~127까지는 영어 숫자 특수문자 등으로 이루어져 있음
		//때문에 입력 받은 문자열은 128보다 커야지 한글임을 판별할 수 있음
		if (st[i] < 128) printf("영어");	//영어일 경우
		else printf("한글");				//한글일 경우
	}
}

int main() {
	unsigned char str[100];
	scanf("%s", str);

	if (is_hangul(str) == 0) printf("영어");	//리턴 값이 0일 경우
	else printf("한글");						//리턴 값이 1일 경우
}

#if 0
int is_hangul(unsigned char st[]) {
	for (int i = 0; st[i] != NULL; i++)
	{
		//0~127까지는 영어 숫자 특수문자 등으로 이루어져 있음
		//때문에 입력 받은 문자열은 128보다 커야지 한글임을 판별할 수 있음
		if (st[i]<128) return 0;	//영어일 경우
		else return 1;				//한글일 경우
	}
}

int main() {
	unsigned char str[10];
	scanf("%s", str);

	if (is_hangul(str)==0) printf("영어");	//리턴 값이 0일 경우
	else printf("한글");					//리턴 갑싱 1일 경우
}
#endif


//숫자 1~7을 입력하면 A부터 G까지 출력하는 프로그램(2)
#if 0
int main() {
	int num;
	scanf("%d", &num);

	//A~G까지는 10진수로 65~ 71
	//따라서 입력한 숫자에 +64를 한 후 char로 출력
	printf("%c", num + 64);
	return 0;
}
#endif

#if 0
//반복문 사용해서 4x4 중간에 빈 네모 만들기 0xA1E1로(3)
int main() {
	for (int i = 0; i < 4; i++)
	{
		if (i==0 || i==3) printf("■ ■ ■ ■ ■\n\n");
		else printf("■          ■\n\n");
	}
}
#endif