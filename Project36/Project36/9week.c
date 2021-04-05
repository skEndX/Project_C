#include<stdio.h>

#if 0
void swap(int* p, int* q) {
	int tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}

int main() {
	int i = 3, j = 5;
	swap(&i, &j);
	printf("%d %d", i, j);
}
#endif

#if 0
int *abc(int a) {
	a = a + 1;
	return &a;
}

int main() {
	int o = 2, *i;
	i = &o;
	i = abc(o);
	printf("%d", *i);
}
#endif


int *abc(int *a) {
	*a = *a + 1;
	return &a;
}

int main() {
	int o = 2, *i;
	i = &o;
	i = abc(i);
	printf("%d", *i);
}
