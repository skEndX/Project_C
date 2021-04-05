#include<stdio.h>
#include<stdlib.h>
#define num 5
struct node {
	int v;
	struct node*next;
};
struct node*graph[num];
int stack[num];
int top = -1;
int visited[num];

void push(int v) {
	if (top==num-1)
	{
		return;
	}
	top++;
	stack[top] = v;
}
int empty() {
	return ((top == -1) ? 1 : 0);
}
int pop() {
	if (top==-1)
	{
		return -1;
	}
	int temp = stack[top];
	top--;
	return temp;
}

int putEdge(int v1, int v2) {
	struct node*new = (struct node*)malloc(sizeof(struct node));
	struct node*cur = graph[v1];
	new->v = v2;
	new->next = 0;

	if (cur==0)
	{
		graph[v1] = new;
		return;
	}
	while (cur->next!=0)
	{
		cur = cur->next;
	}
	cur->next = new;
}
void addEdge(int a, int b) {
	putEdge(a, b);
	putEdge(b, a);
}

void show(int v) {
	struct node*cur = graph[v];
	while (cur!=0)
	{
		printf("%d is the adjacent vertex\n", cur->v);
		cur = cur->next;
	}
}

int find(int v) {
	struct node*cur = graph[v];
	while (cur!=0)
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
	printf("visited %d\n", v);
	visited[v] = 1;
	push(v);
	while (empty()==0)
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

int main() {
	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(0, 4);
	addEdge(1, 2);
	addEdge(2, 3);
	addEdge(2, 4);
	addEdge(3, 4);

	int v;
	scanf("%d", &v);
	show(v);
	DFS(v);
}