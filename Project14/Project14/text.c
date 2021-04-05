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
//		// stack 비었음.
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
//v부터 시작해서,,, DFS
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
//	// 1. v를 stack에 넣는다.
//	push(v);
//
//	// stack이 비어있지 않는 한...
//	while (1)
//	{
//		cur_vertex = pop();
//		if (cur_vertex == -999)
//		{
//			printf("종료\n");
//			return;
//		}
//
//		// 1. stack에서 꺼내서 visited
//		if (visited[cur_vertex] != 1) {
//			visited[cur_vertex] = 1;
//			printf("HELOO!!!!!!!!!!!!!!!!!!!!!!!!!!! %d\n", cur_vertex);
//		}
//
//
//		// 2. 친구들을 찾아서 stack에 push
//		for (f = cur_vertex * VERTEX_NUM;
//			f < cur_vertex*VERTEX_NUM + VERTEX_NUM;
//			f++)
//		{
//			if (graph[f] == 1) // 친구
//			{
//				int real_f = f - cur_vertex * VERTEX_NUM;
//				if (visited[real_f] == 0 && cheakstack(real_f) == 1)  /* stack에 없으면*/
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
//	// 그래프 구성
//	graph = (int *)malloc(sizeof(int)*VERTEX_NUM*VERTEX_NUM);
//	// 초기화
//	for (i = 0; i < VERTEX_NUM*VERTEX_NUM; i++)
//	{
//		graph[i] = 0;
//	}
//	// edge 정보를 추가한다.
//	addEdge(0, 1);
//	addEdge(0, 2);
//	addEdge(0, 3);
//	addEdge(4, 2);
//	addEdge(2, 3);
//
//	// stack 구성
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
//	// DFS 시작
//	// vertex 0번부터 시작해서 gogogo...
//	doDFS(4);
//
//
//
//	return 0;
//}