//#include <stdio.h>
//#include <stdlib.h>
//
//int NUM;
//
//int* graph = 0;
//int* queue = 0;
//int front = 0;
//int rear = 0;
//int* visited = 0;
//int mystery = 0;
//
//void enque(int v)
//{
//	if ((rear + 1) % NUM == front)
//	{
//		return;
//	}
//	queue[rear] = v;
//	rear = (rear + 1) % NUM;
//}
//
//int deque()
//{
//	if (front == rear)
//	{
//		return -999;
//	}
//	int temp = queue[front];
//	front = (front + 1) % NUM;
//	return temp;
//}
//
//void addEdge(int v1, int v2)
//{
//	graph[v1 * NUM + v2] = 1;
//	graph[v2 * NUM + v1] = 1;
//}
//
//int check(int v)
//{
//	int i;
//	for (i = 0; i < NUM; i++)
//	{
//		if (queue[i]==v)
//		{
//			return 1;
//		}
//	}
//	return 0;
//
//}
//
//
//
//void BFS(int v)
//{
//	int cur;
//	int f;
//	enque(v);
//
//	while (1)
//	{
//		cur = deque();
//		if (cur == -999)
//		{
//			return;
//		}
//
//		if (visited[cur]!=1)
//		{
//			visited[cur] = 1;
//			printf("visited %d\n",cur);
//		}
//
//		if ((cur % 2) == 0)
//		{
//			mystery += cur;
//		}
//
//		for (int i = cur * NUM; i < cur*NUM + NUM; i++)
//		{
//			int v_id = i - cur * NUM;
//			if (visited[v_id] == 0 && graph[v_id] == 1 && check(v_id) == 0)
//			{
//				enque(v_id);
//			}
//		}
//	}
//}
//
//int main(void)
//{
//	int v1, v2;
//	int i;
//	scanf("%d", &NUM);
//
//	graph = (int*)malloc(sizeof(int) * NUM * NUM);
//	for (i = 0; i < NUM * NUM; i++)
//	{
//		graph[i] = 0;
//	}
//
//	while (1)
//	{
//		scanf("%d %d", &v1, &v2);
//		if ((v1 == -1) && (v2 == -1))
//		{
//			break;
//		}
//		addEdge(v1, v2);
//	}
//
//	queue = (int*)malloc(sizeof(int) * NUM);
//	for (i = 0; i < NUM; i++)
//	{
//		queue[i] = 0;
//	}
//	visited = (int*)malloc(sizeof(int) * NUM);
//	for (i = 0; i < NUM; i++)
//	{
//		visited[i] = 0;
//	}
//
//	BFS(0);
//	printf("%d", mystery);
//	return 0;
//}