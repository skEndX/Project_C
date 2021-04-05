#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int VERTEX_NUM;

int* graph = 0;
int* queue = 0;
int front = 0;
int rear = 0;
int* visited = 0;
int mystery = 0;

/*
 Queue full �̸� �ܼ��� return
*/
void enqueue(int v)
{
	if (front==rear-1)
	{
		return;
	}
	rear++;
	queue[rear] = v;
}

/*
 Empty queue�̸� -999�� return
*/
int dequeue()
{
	if (front==rear)
	{
		return -999;
	}
	int temp = queue[rear];
	rear--;
	return temp;
}

void addEdge(int v1, int v2)
{
	graph[v1 * VERTEX_NUM + v2] = 1;
	graph[v2 * VERTEX_NUM + v1] = 1;
}

/*
 queue�� vertex v�� ������, 1
 ������ 0�� ��ȯ
*/
int isInQueue(int v)
{
	while (1)
	{
		if (queue[v]==1)
		{
			return 1;
		}
		return 0;
	}
}

/*
  v���� �����ؼ�,,, DFS
*/
void doBFS(int v)
{
	int cur_vertex;
	int f;
	// 1. v�� stack�� �ִ´�.
	enqueue(v);

	// queue�� ������� �ʴ� ��...
	while (1)
	{
		cur_vertex = dequeue();

		if (cur_vertex == -999)
		{
			return;
		}

		// 1. queue���� ������ visited
		visited[cur_vertex] = 1;

		if (cur_vertex==x)
		{
			if (visited[y]==0)
			{

			}
		}

		// �Ʒ� �ڵ�� ���� �������� ������.
		if ((cur_vertex % 2) == 0)
		{
			mystery += cur_vertex;
		}
		//------------------------------
		// ������ʹ� �����ص� �˴ϴ�.


		// 2. ģ������ ã�Ƽ� queue�� enqueue
		//
		// �� ������ �����Ͻÿ�.
		//
	}
}

int main(void)
{
	int v1, v2;
	int i;
	scanf("%d", &VERTEX_NUM);

	// �׷��� ����
	graph = (int*)malloc(sizeof(int) * VERTEX_NUM * VERTEX_NUM);
	// �ʱ�ȭ
	for (i = 0; i < VERTEX_NUM * VERTEX_NUM; i++)
	{
		graph[i] = 0;
	}

	while (1)
	{
		scanf("%d %d", &v1, &v2);
		if ((v1 == -1) && (v2 == -1))
		{
			break;
		}
		addEdge(v1, v2);
	}

	// Queue ����
	queue = (int*)malloc(sizeof(int) * VERTEX_NUM);
	for (i = 0; i < VERTEX_NUM; i++)
	{
		queue[i] = 0;
	}
	visited = (int*)malloc(sizeof(int) * VERTEX_NUM);
	for (i = 0; i < VERTEX_NUM; i++)
	{
		visited[i] = 0;
	}

	// BFS ����
	doBFS(0);

	printf("%d", mystery);

	return 0;
}