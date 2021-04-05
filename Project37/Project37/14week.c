#include<stdio.h>

struct info{
	char name[10];
	char sID[10];
	int num;
	struct info* next; //자기참조
};

int main(){
	struct info man1 = { "김길동", "19882020", 1 };
	struct info man2 = { "홍길동", "19992020", 2 };
	struct info man3 = { "마이클", "20012020", 3 };
	struct info man4 = { "을지문덕", "20202020", 4 };
	struct info man5 = { "방탄소년", "21342020", 5 };

	man1.next = &man2; man2.next = &man3; man3.next = &man4; man4.next = &man5;
	man5.next = NULL; //더이상 연결할 수 없으므로 NULL

	struct info* p = &man1;
	while (p != NULL)
	{
		if (*(p->sID) == '2' && *((p->sID) + 1) == '0') //20으로 시작하는 학번 찾기
			printf("%s %s %d\n", p->name, p->sID, p->num);
		p = p->next;
	}
	return 0;
}

#if 0
#define N 5

int main() {
	char *p[N], count;
	char str[N][10] = { "abcd","123","wxzy","가나다라","789" };

	for ( count = 0; count < N; count++)
	{
		p[count] = str[count]; // 각 배열을 포인터배열에 연결
		if (*(p[count] + (strlen(p[count]) - 1)) & 0x80) //마지막 문자가 한글인 경우
		{
			*(p[count] + (strlen(p[count]) - 2)) = '*';
			*(p[count] + (strlen(p[count]) - 1)) = NULL;
		}
		else *(p[count] + (strlen(p[count]) - 1)) = '*'; //아닌 경우
	}

	for ( count = 0; count < N; count++)
		printf("%s ", str[count]);
}
#endif

