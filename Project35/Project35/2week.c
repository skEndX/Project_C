#include<stdio.h>

int is_hangul(unsigned char st[]) {
	for (int i = 0; st[i] != NULL; i++)
	{
		//0~127������ ���� ���� Ư������ ������ �̷���� ����
		//������ �Է� ���� ���ڿ��� 128���� Ŀ���� �ѱ����� �Ǻ��� �� ����
		if (st[i] < 128) printf("����");	//������ ���
		else printf("�ѱ�");				//�ѱ��� ���
	}
}

int main() {
	unsigned char str[100];
	scanf("%s", str);

	if (is_hangul(str) == 0) printf("����");	//���� ���� 0�� ���
	else printf("�ѱ�");						//���� ���� 1�� ���
}

#if 0
int is_hangul(unsigned char st[]) {
	for (int i = 0; st[i] != NULL; i++)
	{
		//0~127������ ���� ���� Ư������ ������ �̷���� ����
		//������ �Է� ���� ���ڿ��� 128���� Ŀ���� �ѱ����� �Ǻ��� �� ����
		if (st[i]<128) return 0;	//������ ���
		else return 1;				//�ѱ��� ���
	}
}

int main() {
	unsigned char str[10];
	scanf("%s", str);

	if (is_hangul(str)==0) printf("����");	//���� ���� 0�� ���
	else printf("�ѱ�");					//���� ���� 1�� ���
}
#endif


//���� 1~7�� �Է��ϸ� A���� G���� ����ϴ� ���α׷�(2)
#if 0
int main() {
	int num;
	scanf("%d", &num);

	//A~G������ 10������ 65~ 71
	//���� �Է��� ���ڿ� +64�� �� �� char�� ���
	printf("%c", num + 64);
	return 0;
}
#endif

#if 0
//�ݺ��� ����ؼ� 4x4 �߰��� �� �׸� ����� 0xA1E1��(3)
int main() {
	for (int i = 0; i < 4; i++)
	{
		if (i==0 || i==3) printf("�� �� �� �� ��\n\n");
		else printf("��          ��\n\n");
	}
}
#endif