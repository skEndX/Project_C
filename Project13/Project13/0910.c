#include <stdio.h>
#include <stdlib.h>

#define NUM 5

struct vertex
{
	int vertex_num;
	struct vertex *next;
};

struct vertex graph[NUM];

/*
   v1�� v2���̿� edge�� ���´�.
   ������ ��� ���ʿ�
*/
void _putEdge(int v1, int v2)
{
	// 1. �̹� v2�� �پ� �ִ��� Ȯ��.
	struct vertex *cur = graph[v1 - 1].next;
	while (cur != 0)
	{
		if (cur->vertex_num == v2)
		{
			return;
		}
		cur = cur->next;
	}

	// 2. ������, v2�� ���� �߰�
	struct vertex *new_one = (struct vertex *)malloc(sizeof(struct vertex));
	new_one->vertex_num = v2;
	new_one->next = 0;

	cur = graph[v1 - 1].next;
	if (cur == 0)
	{
		graph[v1 - 1].next = new_one;
	}
	else
	{
		while (cur->next != 0)
		{
			cur = cur->next;
		}
		cur->next = new_one;
	}

	return;

}

/*
  v1�� v2���̿� edge�� ������ ǥ��
*/
void addEdge(int v1, int v2)
{
	_putEdge(v1, v2);
	_putEdge(v2, v1);
}

int main()
{
	// vertex array�� vertex num�� ä���ִ´�.
	int i;
	for (i = 0; i < NUM; i++)
	{
		graph[i].vertex_num = i + 1;
		graph[i].next = 0;
	}

	// vertex 1�� vertex 3 ���̿��� 
	// edge�� �ִ�.
	// ����: 1->3 �� 3->1�� �߰�
	addEdge(1, 3);
	addEdge(1, 2);
	addEdge(1, 4);
	addEdge(3, 4);
	addEdge(3, 5);
	addEdge(2, 4);
	addEdge(4, 5);

	return 0;
}