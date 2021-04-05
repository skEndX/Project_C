#include<stdio.h>

struct info{
	char name[10];
	char sID[10];
	int num;
	struct info* next; //�ڱ�����
};

int main(){
	struct info man1 = { "��浿", "19882020", 1 };
	struct info man2 = { "ȫ�浿", "19992020", 2 };
	struct info man3 = { "����Ŭ", "20012020", 3 };
	struct info man4 = { "��������", "20202020", 4 };
	struct info man5 = { "��ź�ҳ�", "21342020", 5 };

	man1.next = &man2; man2.next = &man3; man3.next = &man4; man4.next = &man5;
	man5.next = NULL; //���̻� ������ �� �����Ƿ� NULL

	struct info* p = &man1;
	while (p != NULL)
	{
		if (*(p->sID) == '2' && *((p->sID) + 1) == '0') //20���� �����ϴ� �й� ã��
			printf("%s %s %d\n", p->name, p->sID, p->num);
		p = p->next;
	}
	return 0;
}

#if 0
#define N 5

int main() {
	char *p[N], count;
	char str[N][10] = { "abcd","123","wxzy","�����ٶ�","789" };

	for ( count = 0; count < N; count++)
	{
		p[count] = str[count]; // �� �迭�� �����͹迭�� ����
		if (*(p[count] + (strlen(p[count]) - 1)) & 0x80) //������ ���ڰ� �ѱ��� ���
		{
			*(p[count] + (strlen(p[count]) - 2)) = '*';
			*(p[count] + (strlen(p[count]) - 1)) = NULL;
		}
		else *(p[count] + (strlen(p[count]) - 1)) = '*'; //�ƴ� ���
	}

	for ( count = 0; count < N; count++)
		printf("%s ", str[count]);
}
#endif

