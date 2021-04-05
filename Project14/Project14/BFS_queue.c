//#include<stdio.h>
//#include<stdlib.h>
//#define NUM 5
//struct node {
//	int v;
//	struct node *next;
//};
//struct node *graph[NUM];
//int visited[NUM] = { 0 };
//int head = 0;
//int tail = 0;
//int que[NUM];
//
//void enque(int v) {
//	if ((tail+1)%NUM==head)
//	{
//		printf("full");
//		return;
//	}
//	que[tail] = v;
//	tail=(tail + 1) % NUM;
//	return;
//}
//int queEmpty() {
//	return (head == tail) ? 1 : 0;
//}
//int deque() {
//	int temp = -1;
//	if (queEmpty()==0)
//	{
//		temp = que[head];
//		head = (head + 1) % NUM;
//	}
//	return temp;
//}
//
//void _putEdge(int v1, int v2) {
//	struct node*new = (struct node*)malloc(sizeof(struct node));
//	struct node*cur = graph[v1];
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
//int quefind(int v) {
//	struct node*cur = graph[v];
//	while (cur != 0)
//	{
//		if (visited[cur->v] == 0)
//		{
//			enque(cur->v);
//		}
//		cur = cur->next;
//	}
//	return -1;
//}
//void BFS(int v) {
//	enque(v);
//	while (queEmpty() == 0)
//	{
//		int k = deque();
//		if (visited[k]==0)
//		{
//			printf("BFS visited %d \n", k);
//			visited[k] = 1;
//			quefind(k);
//		}
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
//	BFS(0);
//}