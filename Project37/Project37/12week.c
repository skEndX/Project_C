#include<stdio.h>

void main() {
	char s[] = "Fine";
	printf("%d\n", s[0]);
	printf("%d", s+1);
	
	*s = 'N';
	 
	printf("%s", s);
}

#if 0
// 1�� ����
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
//2�� ����
//a�� ���� �״�� ����, aa�� �� ���ڸ� ����Ű��, ab�� ���ڸ� ������
void main() {
	char a = 'a', b = 'b', c = 'c', *aa = "aaa", ab[] = "bbb";
	abc(a, aa, ab);
}

abc(char a, char *aa, char ab[]) {
	printf("%c %s %s", a, aa, ab);
}
#endif

#if 0
//3�� ����
//������ p�� b�� ����Ű���� �ٲٰ�, p�� ����Ű�� �ִ� ���� a�� ���� �ٲ�
void main() {
	int a = 0x1234ABCD, b = 0, *p = a;

	p = &b;
	*p = a;
	printf("%x %x",a, b);
}
#endif

#if 0
// 4�� ���� ���� �Ȼ���
// *s�� ù��° �ּ��� ���� �ٲٴ� ���̱� ������ Nine���� ��µ�
void main() {
	char s[] = "Fine";
	*s = 'N';

	printf("%s", s);
}
#endif

#if 0
// 5�� ���� ���� ����
//
void main() {
	char s[] = "C++";

	printf("%s", s);
	s++;
	printf("%s", s);
}
#endif