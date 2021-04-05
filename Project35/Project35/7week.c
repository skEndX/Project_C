#include<stdio.h>

#if 0
void change(int *a, int *b) {
	int temp = *a;	//�ش� �ּ��� ���� change �ؾ��ϹǷ� *�� ����
	*a = *b;
	*b = temp;
}

int main() {
	int i = 3, j = 5, k[6] = { 1,2,3,0,5,6 };

	change(&i, &j);
	for (int m = 0; m < sizeof(k) / sizeof(k[0]); m++)
	{
		if (k[m] == 0) { //0 �����Ͱ� ������
			for (int l = 0; l < m / 2; l++)
				change(&k[l], &k[m - 1 - l]);
			break; //������ ����
		}
		if (m == sizeof(k) / sizeof(k[0]) - 1) return -1; //0 �����Ͱ� ���ٸ� -1�� ����
	}

	printf("i = %d, j = %d\n", i, j);
	for (int n = 0; n < sizeof(k) / sizeof(k[0]); n++)
		printf("%d ", k[n]);
}
#endif

#if 0
int main() {
	int data[6] = { 0,100,200,300,400,500 };
	char *p;
	int i = 0;

	for (int j = 0; j < 6; j++)
	{
		p = &data[j];
		for (int k = 3; k >= 0; k--)
		{
			i = i << 8;	//shift�� 1����Ʈ�� ��
			i |= *(p + k); //OR ��Ʈ�������� ��ħ
		}
		printf("1���� �迭 data�� %d��° �����ʹ� %d�Դϴ�.\n", j, i);
	}
}
#endif

#if 0
int main() {
	int data[6] = { 10,20,30,40,50,60 };
	char *p = &data;	//������ ���� p�� data �迭�� �ּҸ� ����

	for (int i = 0; i < 6; i++)	//-5�� ��
		*(p + i*4) = *(p + i*4) - 5; //������ p�� char�� 1����Ʈ, data�迭�� int�� 4����Ʈ�̹Ƿ� *4�� ����

	for (int i = 0; i < 6; i++)
		printf("%d ", data[i]);
}
#endif

#if 0
int main() {
	int data[6] = { 10,20,30,40,50,60 };
	int *p = &data;	//������ ���� p�� data �迭�� �ּҸ� ����

	for (int i = 0; i < 6; i++)	//-5�� ��
		*(p + i) = *(p + i) - 5;

	for (int i = 0; i < 6; i++)
		printf("%d ", data[i]);
}
#endif

#if 0
int main() {
	unsigned char data[6] = { 10,20,30,40,50,60 };
	unsigned char *p = &data;	//������ ���� p�� data �迭�� �ּҸ� ����

	for (int i = 0; i < 6; i++)	//-5�� ��
		*(p + i) = *(p + i) - 5;

	for (int i = 0; i < 6; i++)
		printf("%d ", data[i]);
}
#endif

#if 0
int main() {
	unsigned int i = 515;
	unsigned char c = 276, *p = (unsigned char *)&i;
	*p = c;

	printf("%d", i);
}
#endif