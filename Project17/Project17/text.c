#include <stdio.h>
#include <stdlib.h>

int VERTEX_NUM;

int* graph = 0;
int* queue = 0;
int front = 0;
int rear = 0;
int* visited = 0;

void enqueue(int v)
{
	if ((rear + 1) % VERTEX_NUM == front)
	{
		return;
	}
	queue[rear] = v;
	rear = (rear + 1) % VERTEX_NUM;
}

int dequeue()
{
	int temp = -999;
	if (rear != front)
	{
		temp = queue[front];
		front = (front + 1) % VERTEX_NUM;
	}
	return temp;
}

void addEdge(int v1, int v2)
{
	graph[v1 * VERTEX_NUM + v2] = 1;
	graph[v2 * VERTEX_NUM + v1] = 1;
}



int isInQueue(int v)
{
	int i;
	for (i = front; i != rear; i = (i + 1) % VERTEX_NUM)
	{
		if (queue[i] == v)
		{
			return 1;
		}

	}
	return 0;
}
int doBFS(int v, int x, int y)
{
	int cur_vertex;
	int f;
	enqueue(v);
	int t = 0;

	while (1)
	{

		cur_vertex = dequeue();

		if (cur_vertex == -999)
		{
			return -1;
		}
		if (cur_vertex >= VERTEX_NUM)
		{
			return -1;
		}

		visited[cur_vertex] = 1;

		if (cur_vertex == x)
		{
			if (visited[y] == 0)
			{
				return 1;
			}
			return 0;
		}
		f = 0;

		for (f = cur_vertex * VERTEX_NUM;
			f < cur_vertex*VERTEX_NUM + VERTEX_NUM;
			f++)
		{
			if (graph[f] == 1)
			{
				int real_f = f - cur_vertex * VERTEX_NUM;
				if (visited[real_f] == 0 && isInQueue(real_f) == 0)
				{
					enqueue(real_f);
				}
			}
		}
	}
}

int main(void)
{
	int v1, v2;
	int i;
	int first, second;
	int cnt = 0;
	scanf("%d", &VERTEX_NUM);

	if (VERTEX_NUM <= 1)
	{
		return 0;
	}
	graph = (int*)malloc(sizeof(int) * VERTEX_NUM * VERTEX_NUM);
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

		cnt++;
		if (cnt == VERTEX_NUM)
		{
			continue;
		}
		addEdge(v1, v2);
	}

	scanf("%d %d", &first, &second);
	if (first >= VERTEX_NUM || second >= VERTEX_NUM)
	{
		return 0;
	}
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

	printf("%d", doBFS(0, first, second));



	return 0;
}