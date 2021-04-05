#include<stdio.h>

struct node {
	char *data;
	char *num;
	int add;
	struct node *next;
};

typedef struct node Node;
Node *head = NULL;

int main() {
	head = (Node *)malloc(sizeof(Node));
	head->data = "±è±æµ¿";	head->num = "2009523";	head->add = 1;

	Node *q = (Node *)malloc(sizeof(Node));
	q->data = "È«±æµ¿";	q->num = "2009524";	q->add = 3;
	head->next = q;

	Node *q1 = (Node *)malloc(sizeof(Node));
	q1->data = "¹æÅº";	q1->num = "2023143";	q1->add = 2;
	head->next = q1;

	Node *q2 = (Node *)malloc(sizeof(Node));
	q2->data = "¼Ò³â´Ü";	q2->num = "2503024";	q2->add = 2;
	q2->next = NULL;
	head->next = q2;

	q = (Node *)malloc(sizeof(Node));
	q->data = "¸¶ÀÌÅ¬";	q->num = "203814";	q->add = 4;
	q->next = head;
	head = q;

	Node *p = head;
	while (p != NULL) {
		if (*(p->num) == '2' && *((p->num) + 1) == '5')
		{
			printf("%s %s %d\n", p->data, p->num, p->add);
		}
		p = p->next;
	}
	return 0;
}