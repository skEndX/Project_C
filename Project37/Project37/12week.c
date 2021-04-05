#include<stdio.h>

void main() {
	char s[] = "Fine";
	printf("%d\n", s[0]);
	printf("%d", s+1);
	
	*s = 'N';
	 
	printf("%s", s);
}

#if 0
// 1번 문제
void main() {
	char c1 = 97;
	char c2 = 'a';
	char c3 = "a";	//error
	char c4 = "abcd";	//error
	char *c5 = "abcd";
	char c6[5] = "abcd";
	char c7[] = "abcd";

	printf("%d\n", c1);
	printf("%c\n", c2);
	//printf("%s\n", c3);
	//printf("%s\n", c4);
	printf("%s\n", c5);
	for (int i = 0; i < 5; i++)
		printf("%c", c6[i]);

	printf("\n");

	for (int i = 0; i < 5; i++)
		printf("%c", c7[i]);
}
#endif

#if 0
//2번 문제
//a는 문자 그대로 들어가고, aa는 그 문자를 가리키고, ab는 문자를 복사함
void main() {
	char a = 'a', b = 'b', c = 'c', *aa = "aaa", ab[] = "bbb";
	abc(a, aa, ab);
}

abc(char a, char *aa, char ab[]) {
	printf("%c %s %s", a, aa, ab);
}
#endif

#if 0
//3번 문제
//포인터 p를 b를 가리키도록 바꾸고, p가 가리키고 있는 값을 a의 값을 바꿈
void main() {
	int a = 0x1234ABCD, b = 0, *p = a;

	p = &b;
	*p = a;
	printf("%x %x",a, b);
}
#endif

#if 0
// 4번 문제 에러 안생김
// *s는 첫번째 주소의 값을 바꾸는 것이기 때문에 Nine으로 출력됨
void main() {
	char s[] = "Fine";
	*s = 'N';

	printf("%s", s);
}
#endif

#if 0
// 5번 문제 에러 생김
//
void main() {
	char s[] = "C++";

	printf("%s", s);
	s++;
	printf("%s", s);
}
#endif