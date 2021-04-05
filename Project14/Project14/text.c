//#include <stdio.h>
//#include <stdlib.h>
//
//int VERTEX_NUM = 7;
//
//int *graph = 0;
//int *stack = 0;
//int top = -1;
//int *visited = 0;
//
//void push(int v)
//{
//	if (top == VERTEX_NUM - 1)
//	{
//		// stack full
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
//		// stack �����.
//		return -999;
//	}
//	top = top - 1;
//	return stack[top + 1];
//}
//
//void addEdge(int v1, int v2)
//{
//	graph[v1*VERTEX_NUM + v2] = 1;
//	graph[v2*VERTEX_NUM + v1] = 1;
//
//	printf("graph[%d] == 1\n", v1*VERTEX_NUM + v2);
//	printf("graph[%d] == 1\n", v2*VERTEX_NUM + v1);
//}
//
///*
//
//v���� �����ؼ�,,, DFS
//*/
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
//void doDFS(int v)
//{
//	int cur_vertex;
//	int f;
//	// 1. v�� stack�� �ִ´�.
//	push(v);
//
//	// stack�� ������� �ʴ� ��...
//	while (1)
//	{
//		cur_vertex = pop();
//		if (cur_vertex == -999)
//		{
//			printf("����\n");
//			return;
//		}
//
//		// 1. stack���� ������ visited
//		if (visited[cur_vertex] != 1) {
//			visited[cur_vertex] = 1;
//			printf("HELOO!!!!!!!!!!!!!!!!!!!!!!!!!!! %d\n", cur_vertex);
//		}
//
//
//		// 2. ģ������ ã�Ƽ� stack�� push
//		for (f = cur_vertex * VERTEX_NUM;
//			f < cur_vertex*VERTEX_NUM + VERTEX_NUM;
//			f++)
//		{
//			if (graph[f] == 1) // ģ��
//			{
//				int real_f = f - cur_vertex * VERTEX_NUM;
//				if (visited[real_f] == 0 && cheakstack(real_f) == 1)  /* stack�� ������*/
//				{
//					push(real_f);
//
//				}
//
//			}
//		}
//
//
//
//	}
//
//
//
//}
//
//int main(void)
//{
//
//
//	int i;
//	// �׷��� ����
//	graph = (int *)malloc(sizeof(int)*VERTEX_NUM*VERTEX_NUM);
//	// �ʱ�ȭ
//	for (i = 0; i < VERTEX_NUM*VERTEX_NUM; i++)
//	{
//		graph[i] = 0;
//	}
//	// edge ������ �߰��Ѵ�.
//	addEdge(0, 1);
//	addEdge(0, 2);
//	addEdge(0, 3);
//	addEdge(4, 2);
//	addEdge(2, 3);
//
//	// stack ����
//	stack = (int *)malloc(sizeof(int)*VERTEX_NUM);
//	for (i = 0; i < VERTEX_NUM; i++)
//	{
//		stack[i] = 0;
//	}
//	visited = (int *)malloc(sizeof(int)*VERTEX_NUM);
//	for (i = 0; i < VERTEX_NUM; i++)
//	{
//		visited[i] = 0;
//	}
//
//	// DFS ����
//	// vertex 0������ �����ؼ� gogogo...
//	doDFS(4);
//
//
//
//	return 0;
//}