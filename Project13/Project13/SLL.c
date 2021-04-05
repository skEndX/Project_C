//#include<stdio.h>
//#include<stdlib.h>
//struct node {
//	int v;
//	struct node *next;
//};
//struct node *graph[4];
//
//void _putEdge(int v1, int v2) {
//	struct node*new = (struct node*)malloc(sizeof(struct node));
//	struct node*cur = graph[v1];
//
//	new->v = v2;
//	new->next = 0;
//
//	if (cur == 0)
//	{
//		graph[v1] = new;
//		return;
//	}
//	else
//	{
//		while (cur->next != 0)
//		{
//			cur = cur->next;
//		}
//		cur->next = new;
//		return;
//	}
//}
//
//void addEdge(int v1, int v2) {
//	_putEdge(v1, v2);
//	_putEdge(v2, v1);
//}
//
//void show(int v) {
//	struct node*cur = graph[v];
//	while (cur != 0)
//	{
//		printf("%d is the adjacent vertex\n", cur->v);
//		cur = cur->next;
//	}
//}
//
//void main() {
//	addEdge(0, 1);
//	addEdge(0, 2);
//	addEdge(0, 4);
//	addEdge(1, 2);
//	addEdge(2, 3);
//	addEdge(2, 4);
//	addEdge(3, 4);
//
//	show(0);
//}