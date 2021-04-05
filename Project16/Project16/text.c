#include<stdio.h>
#include<stdlib.h>
#define num 100
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
		return -999;
	}
	int temp = stack[top];
	top--;
	return temp;
}

void addEdge(int a, int b) {
	putEdge(a, b);
	putEdge(b, a);
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
	while (cur->next != 0)
	{
		cur = cur->next;
	}
	cur->next = new;
}

int find(int v) {
	struct node*cur = graph[v];
	while (cur!=0)
	{
		if (visited[cur->v]==0)
		{
			return cur->v;
		}
		return -1;
	}
}
void doBFS(int v) {
	printf("visited %d\n", v);
	visited[v] = 1;
	push(v);

	while (empty()==0)
	{
		int next_v = -1;
		next_v = find(stack[top]);
		if (next_v==-1)
		{
			pop();
			return;
		}
		doBFS(next_v);
	}
}

void show(int a, int b) {
	
}

int main() {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		if ((v1 == -1) && (v2 == -1))
		{
			break;
		}
		addEdge(v1, v2);
	}

	// BFS ½ÃÀÛ
	doBFS(0);
	int a,b;
	scanf("%d &d", &a,&b);
	show(a, b);
}