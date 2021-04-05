//#include <stdio.h>
//#include <stdlib.h>
//
//int NUM = 7;
//
//int *graph = 0;
//int *stack = 0;
//int top = -1;
//int *visited = 0;
//
//void push(int v)
//{
//	if (top == NUM - 1)
//	{
//		return;
//	}
//	top = top + 1;
//	stack[top] = v;
//}
//
//int pop()
//{
//	if (top == -1)
//	{
//		return -999;
//	}
//	int temp = stack[top];
//	top--;
//	return temp;
//}
//
//void addEdge(int v1, int v2)
//{
//	graph[v1*NUM + v2] = 1;
//	graph[v2*NUM + v1] = 1;
//
//	printf("graph[%d] == 1\n", v1*NUM + v2);
//	printf("graph[%d] == 1\n", v2*NUM + v1);
//}
//
//int cheakstack(int v)
//{
//	for (int i = 0; i < top; i++)
//	{
//		if (stack[i] == v)
//		{
//			return -999;
//		}
//	}
//	return 1;
//}
//
//void DFS(int v)
//{
//	int cur;
//	int f;
//	push(v);
//
//	while (1)
//	{
//		cur = pop();
//		if (cur == -999)
//		{
//			return;
//		}
//
//		if (visited[cur] != 1)
//		{
//			visited[cur] = 1;
//			printf("visited %d\n", cur);
//		}
//
//		for (f = cur * NUM;f < cur*NUM + NUM;f++)
//		{
//			if (graph[f] == 1) 
//			{
//				int real_f = f - cur * NUM;
//				if (visited[real_f] == 0 && cheakstack(real_f) == 1)
//				{
//					push(real_f);
//				}
//			}
//		}
//	}
//}
//
//int main(void)
//{
//	int i;
//	graph = (int *)malloc(sizeof(int)*NUM*NUM);
//	for (i = 0; i < NUM*NUM; i++)
//	{
//		graph[i] = 0;
//	}
//
//	addEdge(0, 1);
//	addEdge(0, 2);
//	addEdge(0, 3);
//	addEdge(4, 2);
//	addEdge(2, 3);
//
//	stack = (int *)malloc(sizeof(int)*NUM);
//	for (i = 0; i < NUM; i++)
//	{
//		stack[i] = 0;
//	}
//	visited = (int *)malloc(sizeof(int)*NUM);
//	for (i = 0; i < NUM; i++)
//	{
//		visited[i] = 0;
//	}
//
//	DFS(4);
//	return 0;
//}