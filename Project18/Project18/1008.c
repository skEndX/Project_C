//#include<stdio.h>
//#include<stdlib.h>
//#define vertex_n 5
//#define edge_n 8
//int cycle_d[5] = { 0,1,2,3,4 };
//int cnt = 0;
//struct node {
//	int v;
//	int w;
//	struct node *next;
//};
//struct node *graph[vertex_n];
//struct edges {
//	int from;
//	int to;
//	int w;
//};
//struct edges edge[edge_n];
//void addEdge(int v1, int v2, int w)
//{
//	struct node*cur = graph[v1];
//	struct node*new = (struct node*)malloc(sizeof(struct node));
//	new->v = v2;
//	new->w = w;
//	new->next = 0;
//	if (cur == 0)
//	{
//		graph[v1] = new;
//	}
//	else
//	{
//		while (cur->next != 0)
//		{
//			cur = cur->next;
//		}
//		cur->next = new;
//	}
//}
//void swap(int i, int j)
//{
//	struct edges temp;
//	temp = edge[i];
//	edge[i] = edge[j];
//	edge[j] = temp;
//}
//void edgesorting()
//{
//	int i;
//	int edge_cnt = 0;
//	for (i = 0; i < vertex_n; i++)
//	{
//		struct node*cur = graph[i];
//		while (cur != 0)
//		{
//			edge[edge_cnt].from = i;
//			edge[edge_cnt].to = cur->v;
//			edge[edge_cnt].w = cur->w;
//			edge_cnt++;
//			cur = cur->next;
//		}
//	}
//	int j;
//	for (i = 0; i < vertex_n; i++)
//	{
//		for (j = 0; j < vertex_n - 1 - i; j++)
//		{
//			if (edge[j].w > edge[j + 1].w)
//			{
//				swap(j, j + 1);
//			}
//		}
//	}
//}
//void family(int v1, int v2)
//{
//	int b = v1, s = v2;
//	if (b < s)
//	{
//		s = v1;
//		b = v2;
//	}
//	int i;
//	for (i = 0; i < vertex_n; i++)
//	{
//		if (cycle_d[i] == b)
//		{
//			cycle_d[i] = s;
//		}
//	}
//}
//void doMST()
//{
//
//	int edge_cnt = 0;
//	int next_v = -1;
//	int i;
//	for (i = 0; i < edge_n; i++)
//	{
//		if (cycle_d[edge[i].from] != cycle_d[edge[i].to])
//		{
//			family(cycle_d[edge[i].from], cycle_d[edge[i].to]);
//			//printf("%d--%d %d\n", edge[i].from, edge[i].to, edge[i].w);
//			//printf("%d\n", edge[i].w);
//			cnt = cnt + edge[i].w;
//			edge_cnt++;
//			if (edge_cnt == vertex_n - 1)
//			{
//				return;
//			}
//		}
//	}
//	printf("%d", cnt);
//}
//
//int main(void)
//{
//	int i;
//	addEdge(0, 1, 1);
//	addEdge(0, 3, 50);
//	addEdge(0, 2, 1);
//	addEdge(2, 1, 90);
//	addEdge(3, 2, 1);
//	addEdge(3, 1, 1);
//
//	edgesorting();
//	doMST();
//}
//
