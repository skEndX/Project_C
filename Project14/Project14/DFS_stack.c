#include<stdio.h>
#include<stdlib.h>
#define NUM 5
struct node {
	int v;
	struct node *next;
};
struct node *graph[NUM];
int visited[NUM] = { 0 };
int stack[NUM];
int top = -1;

void push(int v) {
	if (top==NUM-1)
	{
		printf("full");
		return;
	}
	top++;
	stack[top] = v;
}
int Empty() {
	return ((top == -1) ? 1 : 0);
}
int pop() {
	int temp = 0;
	if (top==-1)
	{
		printf("empty");
		return -1;
	}
	temp = stack[top];
	top--;
	return temp;
}

void _putEdge(int v1, int v2) {
	struct node*new = (struct node*)malloc(sizeof(struct node));
	struct node*cur = graph[v1];

	new->v = v2;
	new->next = 0;

	if (cur == 0)
	{
		graph[v1] = new;
		return;
	}
	else
	{
		while (cur->next != 0)
		{
			cur = cur->next;
		}
		cur->next = new;
		return;
	}
}

void addEdge(int v1, int v2) {
	_putEdge(v1, v2);
	_putEdge(v2, v1);
}

void show(int v) {
	struct node*cur = graph[v];
	while (cur != 0)
	{
		printf("%d is the adjacent vertex\n", cur->v);
		cur = cur->next;
	}
}

int find(int v) {
	struct node*cur = graph[v];
	while (cur != 0)
	{
		if (visited[cur->v]==0)
		{
			return cur->v;
		}
		cur = cur->next;
	}
	return -1;
}
void DFS(int v) {
	printf("visited %d \n", v);
	visited[v] = 1;
	push(v);

	while (Empty()==0)
	{
		int next_vertex = -1;
		next_vertex = find(stack[top]);

		if (next_vertex==-1)
		{
			pop();
			return;
		}
		DFS(next_vertex);
	}
}

void main() {
	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(0, 4);
	addEdge(1, 2);
	addEdge(2, 3);
	addEdge(2, 4);
	addEdge(3, 4);

	//show(0);

	DFS(2);
}