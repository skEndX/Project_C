#include<stdio.h>

char a = 10, b, c;
int d = 10, e, f;
char g[5];

main() {
	char h = 10, i, j;	
	int k = 10, l, m;
	char n[5];
	
	printf("�й� : 201801730, �̸� : ����� \n\n");

	printf("a�� �ּ� = %p, h�� �ּ� = %p\n", &a, &h);
	printf("b�� �ּ� = %p, c�� �ּ� = %p\n", &b, &c);
	printf("i�� �ּ� = %p, j�� �ּ� = %p\n", &i, &j);
	printf("d�� �ּ� = %p, k�� �ּ� = %p\n", &d, &k);
	printf("e�� �ּ� = %p, f�� �ּ� = %p\n", &e, &f);
	printf("l�� �ּ� = %p, m�� �ּ� = %p\n", &l, &m);
	printf("g�� �ּ� = %p, n�� �ּ� = %p\n\n", &g, &n);

	printf("a�� �ּ� = %x, h�� �ּ� = %x\n", &a, &h);
	printf("b�� �ּ� = %x, c�� �ּ� = %x\n", &b, &c);
	printf("i�� �ּ� = %x, j�� �ּ� = %x\n", &i, &j);
	printf("d�� �ּ� = %x, k�� �ּ� = %x\n", &d, &k);
	printf("e�� �ּ� = %x, f�� �ּ� = %x\n", &e, &f);
	printf("l�� �ּ� = %x, m�� �ּ� = %x\n", &l, &m);
	printf("g�� �ּ� = %x, n�� �ּ� = %x\n\n", &g, &n);

	printf("g�� �ּ� = %x, g[0]�� �ּ� = %x, g[4]�� �ּ� = %x\n", &g, &g[0], &g[4]);
	printf("n�� �ּ� = %x, n[0]�� �ּ� = %x, n[4]�� �ּ� = %x\n", &n, &n[0], &n[4]);
}

#if 0
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	for (int i = 0; i < b; i++)
	{
		for (int i = 0; i < a; i++)
		{
			printf(" * ");
		}
		printf("\n");
	}
}
#endif