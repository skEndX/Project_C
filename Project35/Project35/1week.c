#include<stdio.h>

char a = 10, b, c;
int d = 10, e, f;
char g[5];

main() {
	char h = 10, i, j;	
	int k = 10, l, m;
	char n[5];
	
	printf("切锅 : 201801730, 捞抚 : 辫促锐 \n\n");

	printf("a狼 林家 = %p, h狼 林家 = %p\n", &a, &h);
	printf("b狼 林家 = %p, c狼 林家 = %p\n", &b, &c);
	printf("i狼 林家 = %p, j狼 林家 = %p\n", &i, &j);
	printf("d狼 林家 = %p, k狼 林家 = %p\n", &d, &k);
	printf("e狼 林家 = %p, f狼 林家 = %p\n", &e, &f);
	printf("l狼 林家 = %p, m狼 林家 = %p\n", &l, &m);
	printf("g狼 林家 = %p, n狼 林家 = %p\n\n", &g, &n);

	printf("a狼 林家 = %x, h狼 林家 = %x\n", &a, &h);
	printf("b狼 林家 = %x, c狼 林家 = %x\n", &b, &c);
	printf("i狼 林家 = %x, j狼 林家 = %x\n", &i, &j);
	printf("d狼 林家 = %x, k狼 林家 = %x\n", &d, &k);
	printf("e狼 林家 = %x, f狼 林家 = %x\n", &e, &f);
	printf("l狼 林家 = %x, m狼 林家 = %x\n", &l, &m);
	printf("g狼 林家 = %x, n狼 林家 = %x\n\n", &g, &n);

	printf("g狼 林家 = %x, g[0]狼 林家 = %x, g[4]狼 林家 = %x\n", &g, &g[0], &g[4]);
	printf("n狼 林家 = %x, n[0]狼 林家 = %x, n[4]狼 林家 = %x\n", &n, &n[0], &n[4]);
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