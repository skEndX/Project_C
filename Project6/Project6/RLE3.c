#include<stdio.h>
#include<string.h>
#define N 256*256
unsigned char results[N] = { '\0' };	//encoding�� �����͸� ������ �迭
FILE *bin = 0;	//encoding�� �迭�� ������ binary file

int encoding(unsigned char num[N]) {
	int i, cnt = 1, idx = 0;

	printf("���ڵ� �� : ");
	for (i = 0; i < N; i++)
	{
		if (num[i] == 0) break;	//�迭�� �����Ͱ� ������ �ݺ��� Ż��
		if ((num[i] != num[i + 1]) || (cnt == 255))	//���� ������ �����Ϳ� �ٸ��ų� �ݺ�Ƚ���� 255�� �Ǹ� �� �迭�� �ݺ�Ƚ���� �����͸� ����
		{
			results[idx] = cnt;
			results[idx + 1] = num[i];	//�����ʹ� ����ĭ�� �����ؾ��ϹǷ� idx+1
			cnt = 1;	//cnt�� 1�� �ʱ�ȭ
			printf("%d%c", results[idx], results[idx + 1]);
			idx += 2;	//�ݺ�Ƚ���� �����͸� 2ĭ�� �����ϱ� ������ 2�� ����
		}
		else cnt++;
	}
	//encoding�� �迭�� binary file�� ����
	if(bin=fopen("en_code.bin", "wb"))
	fwrite(results, sizeof(unsigned char), N, bin);
	return;
}

int decoding(unsigned char en_number[N]) {
	int i, j, idx = 0;
	unsigned char de_number[2 * N] = { 0, };
	for (i = 0;; i += 2)
	{
		if (en_number[i] == 0) break;
		for (j = 0; j < en_number[i]; j++)	//�ݺ�Ƚ����ŭ �� �迭�� �����͸� �����ؾ��ϹǷ� j�� en_number[i]���� �ݺ�
		{
			printf("%c", en_number[i + 1]);
			de_number[idx] = en_number[i + 1];
			idx++;
		}
	}
	printf("\n��� : %s\n", de_number);
	if (bin = fopen("string.bin", "rb"))
	{
		FILE *txt = 0;	//decoding�� �迭�� ������ txt file
		if (txt = fopen("de_code.txt", "w"))
		fwrite(de_number, sizeof(unsigned char), N, txt);
	}
}

int main() {
	unsigned char num[N];
	unsigned char num1[N];
	unsigned char num2[N];
	FILE *fp = fopen("string.txt", "r");	//�Է� ����
	fgets(num, sizeof(num), fp);
	printf("���ڵ� �� : %s\n",num);
	encoding(num);
	printf("\n\n�迭 ���ڵ� ���� : ");
	decoding(results);	//encoding�� �迭�� decoding
	printf("\n");

	FILE *bin = fopen("en_code.bin", "rb");	//encoding�� binary file
	fgets(num1, sizeof(num1), bin);
	printf("binary file ���ڵ� ���� : ");
	decoding(num1);	//encoding�� binary file�� decoding

	FILE *txt = fopen("de_code.txt", "r");	//decodinge�� txt file
	fgets(num2, sizeof(num2), txt);

	if (strcmp(num, num2) == 0) printf("\n����");	//�Է����ϰ� ���� ���� ��
	else printf("\n�ٸ���");
	return 0;
}