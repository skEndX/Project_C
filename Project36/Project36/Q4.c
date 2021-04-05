#include<stdio.h>

int setBITs(unsigned char *a, unsigned char *b, unsigned char *c) {
	int max = *a<*b ? (*b<*c ? *c:*b) : (*a<*c ? *c : *a);
	int min = *a > *b ? (*b > *c ? *c : *b) : (*a > *c ? *c : *a);

	max = max & 240;
	min = min << 4 | min >> 4;
	
}

int main() {
	unsigned char a = 2;
	unsigned char b = 3;
	unsigned char c = 4;
	setBITs(&a, &b, &c);

	//printf("%d %d %d", a, b, c);
}