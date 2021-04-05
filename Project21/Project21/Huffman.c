#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define sz 100

typedef struct node
{
	char c;
	int f;
	struct node *next;
	struct node *l;
	struct node *r;
}node;

struct node *head = 0;
char c_buf[200];
int idx = -1;

struct node *create(char _c, int _f);
void SLL(struct node * new);
struct node *find(void);
void travel(struct node *n, char _code);

int main(void)
{
	FILE *fp;
	char BUF[sz];
	int cnt[256];

	memset(BUF, 0, sizeof(char)*sz);
	memset(cnt, 0, sizeof(int) * 256);

	fp = fopen("file.txt", "rt");

	if (fp == 0)
	{
		return 0;
	}
	while (1)
	{
		char *temp = fgets(BUF, sizeof(char)*(sz - 1), fp);
		if (temp==0)
		{
			break;
		}
		for (int i = 0; i < strlen(BUF); i++)
		{
			cnt[BUF[i]]++;
		}
	}
	fclose(fp);

	for (int i = 0; i < 256; i++)
	{
		if (cnt[i] > 0)
		{
			SLL(create(i, cnt[i]));
		}
	}
	while (1)
	{
		if (head->next == 0)
		{
			break;
		}
		struct node *a = find();
		struct node *b = find();
		struct node *c = create(' ', a->f + b->f);
		c->l = a;
		c->r = b;
		SLL(c);
	}
	travel(head->l, '0');
	travel(head->r, '1');

	return 0;
}

struct node *find()
{
	struct node *temp = head;
	int min = 9999999;
	struct node *least = 0;

	while (temp != 0)
	{
		if (temp->f < min)
		{
			least = temp;
			min = temp->f;
		}
		temp = temp->next;
	}

	if (head == least)
	{
		head = head->next;
	}
	else
	{
		temp = head;
		while (temp->next != least)
		{
			temp = temp->next;
		}
		temp->next = least->next;
	}
	least->next = 0;
	return least;
}

struct node *create(char _c, int _f)
{
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->c = _c;
	new->f = _f;
	new->l = new->r = new->next = 0;

	return new;
}

void SLL(struct node * new)
{

	struct node *temp = head;
	if (head == 0)
	{
		head = new;
		return;
	}
	while (temp->next != 0)
	{
		temp = temp->next;
	}
	temp->next = new;
}

void travel(struct node *n, char _code)
{
	idx++;
	c_buf[idx] = _code;
	c_buf[idx + 1] = 0;

	if (n->l == 0 && n->r == 0)
	{
		printf("%c ----> %s \n", n->c, c_buf);
	}
	else
	{
		travel(n->l, '0');
		travel(n->r, '1');
	}
	c_buf[idx] = 0;
	idx--;
}
#endif


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define sz 100

typedef struct node
{
	char c;
	int f;
	struct node *next;
	struct node *l;
	struct node *r;
}node;

struct node *head = 0;
char c_buf[200];
int idx = -1;

struct node *create(char _c, int _f);
void SLL(struct node * new);
struct node *find(void);
void travel(struct node *n, char _code);

int main(void)
{
	char BUF[sz];
	int cnt[256];
	int num;
	char c;

	memset(BUF, 0, sizeof(char)*sz);
	memset(cnt, 0, sizeof(int) * 256);

	scanf("%d\n", &num);
	for (int i = 0; i < num; i++) {
		scanf("%c", &c);
		cnt[c]++;
	}

	for (int i = 0; i < 256; i++)
	{
		if (cnt[i] > 0)
		{
			SLL(create(i, cnt[i]));
		}
	}
	while (1)
	{
		if (head->next == 0)
		{
			break;
		}
		struct node *a = find();
		struct node *b = find();
		struct node *c = create(' ', a->f + b->f);
		c->l = a;
		c->r = b;
		SLL(c);
	}
	travel(head->l, '0');
	travel(head->r, '1');

	return 0;
}

struct node *find()
{
	struct node *temp = head;
	int min = 9999999;
	struct node *least = 0;

	while (temp != 0)
	{
		if (temp->f < min)
		{
			least = temp;
			min = temp->f;
		}
		temp = temp->next;
	}

	if (head == least)
	{
		head = head->next;
	}
	else
	{
		temp = head;
		while (temp->next != least)
		{
			temp = temp->next;
		}
		temp->next = least->next;
	}
	least->next = 0;
	return least;
}

struct node *create(char _c, int _f)
{
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->c = _c;
	new->f = _f;
	new->l = new->r = new->next = 0;

	return new;
}

void SLL(struct node * new)
{

	struct node *temp = head;
	if (head == 0)
	{
		head = new;
		return;
	}
	while (temp->next != 0)
	{
		temp = temp->next;
	}
	temp->next = new;
}

void travel(struct node *n, char _code)
{
	idx++;
	c_buf[idx] = _code;
	c_buf[idx + 1] = 0;

	if (n->l == 0 && n->r == 0)
	{
		printf("%c ----> %s \n", n->c, c_buf);
	}
	else
	{
		travel(n->l, '0');
		travel(n->r, '1');
	}
	c_buf[idx] = 0;
	idx--;
}