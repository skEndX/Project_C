#include<stdio.h>

#if 0
int i[3][4] = { 100,200,300,400,500,600, };

int main() {
	printf("%d\n", i);
	printf("%d	%d	%d\n", i+1,&i,&i+1);
	printf("%d	%d	%d\n", i[0],i[1],i[2]);
	printf("%d	%d	%d\n", i[0]+1, i[1]+1, i[2]+1);
	printf("%d	%d	%d\n", i[0]+2, i[1]+2, i[2]+2);
	printf("%d	%d	%d\n", &i[0], &i[1], &i[2]);
	printf("%d	%d	%d\n", &i[0] + 1, &i[1] + 1, &i[2] + 1);
	printf("%d	%d	%d\n", &i[0][0], &i[1][0], &i[2][0]);
	printf("%d	%d	%d\n", i[0][0], i[1][0], i[2][0]);
}
#endif

#if 0
int main() {
	unsigned char c=128;
	if (c % 2 ==0) printf("¦��");
	else printf("Ȧ��");

	unsigned char c = 128;
	if (c & 0x01 == 0x01) printf("Ȧ��");
	else printf("¦��");
}
#endif

#if 0
int main() {
	int i[2][3] = { 4,2,3,6,1,5 };

	int m, tmp;	// b�� ���� ������ ���� ����, �迭�� ���� �ٲ� �� �ӽ÷� ������ tmp ����
	for (int a = 0; a < 2; a++)
		for (int b = 0; b < 3; b++)
		{
			m = b;	//���� ���� ��� ���� ����� ��ġ�� ����
			for (int c = a; c < 2; c++)
				for (int d = m; d < 3; d++)	//������ ��ġ���� �� ����
				{
					if (i[a][b] > i[c][d])	//���� �տ� �ִ� �迭�� �� ũ�ٸ� �� ��ȯ
					{
						tmp = i[a][b];	//���� ������ �����ʰ� ���� �ٲٱ� ���ؼ� �ӽ÷� ������ ������ �̿�
						i[a][b] = i[c][d];
						i[c][d] = tmp;
					}
					m = 0;	//�ٽ� 0���� �ʱ�ȭ
				}
		}

	for (int a = 0; a < 2; a++)
		for (int b = 0; b < 3; b++)
			printf("%d ", i[a][b]);
}
#endif