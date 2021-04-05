#if 0
//DFS
#include<stdio.h>
#include<stdlib.h>
#define num 10
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
	printf("%d ", v);
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
		DFS(next_v);
	}
}

int main() {
	int v, e, s;
	scanf("%d %d %d", &v, &e, &s);
	int v1, v2;

	for (int i = 0; i < e; i++)
	{
		scanf("%d %d", &v1, &v2);
		if (v1 == -1 && v2 == -1)
		{
			break;
		}
		addEdge(v1, v2);
	}
	DFS(s);
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
int vertex;

int *graph = 0;
int *que = 0;
int front = 0;
int rear = 0;
int *visited = 0;

void enque(int v) {
	if ((rear+1)%vertex==front%vertex)
	{
		return;
	}
	que[rear] = v;
	rear = rear + 1;
	rear = rear % vertex;
}

int deque() {
	if (front%vertex==rear %vertex)
	{
		return -999;
	}
	int temp = que[front];
	front = front + 1;
	front = front % vertex;
	return temp;
}

void addEdge(int v1, int v2) {
	graph[v1*vertex + v2] = 1;
	graph[v2*vertex + v1] = 1;
}

int isInQue(int v) {
	int cnt = 0;
	int temp = front;
	while (1)
	{
		if (temp==rear)
		{
			return 1;
		}
		if (cnt==vertex)
		{
			return 0;
		}
		temp = temp + 1;
		temp = temp % vertex;
	}
}

int first(int v1, int v2) {
	int cur;
	int f;
	enque(0);

	while (1)
	{
		cur = deque();
		if (cur==-999)
		{
			return -999;
		}

		visited[cur] = 1;
		if (visited[v1]==1)
		{
			return 1;
		}
		if (visited[v2]==1)
		{
			return 0;
		}
		for ( f = cur*vertex; f < cur*vertex+vertex; f++)
		{
			if (graph[f]==1)
			{
				int real_f = f - vertex * cur;
				if (visited[real_f]==0 && isInQue(real_f))
				{
					enque(real_f);
				}
			}
		}
	}
}

int main() {
	int v1, v2;
	scanf("%d", &vertex);
	graph = (int *)malloc(sizeof(int)*vertex*vertex);
	for (int i = 0; i < vertex*vertex; i++)
	{
		graph[i] = 0;
	}
	while (1)
	{
		scanf("%d %d", &v1, &v2);
		if (v1==-1 && v2==-1)
		{
			break;
		}
		addEdge(v1, v2);
	}

	que = (int *)malloc(sizeof(int)*vertex);
	for (int i = 0; i < vertex; i++)
	{
		que[i] = 0;
	}
	visited = (int*)malloc(sizeof(int)*vertex);
	for (int i = 0; i < vertex; i++)
	{
		visited[i] = 0;
	}

	scanf("%d %d", &v1, &v2);
	printf("%d", first(v1, v2));
	return 0;
}
#endif

#if 0
#include <stdio.h>
int *graph;
int *visited;
int *que;
int rear = 0, front = 0;
int vertex;
void enque(int v)
{
	if ((rear + 1) % vertex == front)
	{
		return;
	}
	que[rear] = v;
	rear = (rear + 1) % vertex;
	return;
}

int deque()
{
	if (rear == front)
	{
		return -999;
	}
	int temp = que[front];
	front = (front + 1) % vertex;
	return temp;
}

void addEdge(int v1, int v2)
{
	graph[v1*vertex + v2] = 1;
	graph[v2*vertex + v1] = 1;
	return;
}
int NotInque(int v)
{
	int temp = front;
	while ((temp%vertex) == rear)
	{
		if (que[temp] == v)
		{
			return 0;
		}
		temp = (temp + 1) % vertex;
	}
	return 1;
}
int doBFS(int v1, int v2)
{
	int f;
	int temp;
	enque(v1);
	while (front != rear)
	{
		temp = deque();
		visited[temp] = 1;

		for (f = temp * vertex; f < temp*vertex + vertex; f++)
		{
			if (graph[f] == 1)
			{
				int real_f = f - temp * vertex;
				if (visited[real_f] == 0 && NotInque(real_f))
				{
					enque(real_f);
				}
			}
		}
	}
	if (temp == v2)
	{
		return 1;
	}
	return 0;
}
int main(void)
{
	scanf("%d", &vertex);

	graph = (int *)malloc(sizeof(int)*vertex*vertex);
	for (int i = 0; i < vertex*vertex; i++)
	{
		graph[i] = 0;
	}
	visited = (int *)malloc(sizeof(int)*vertex);
	for (int i = 0; i < vertex; i++)
	{
		visited[i] = 0;
	}
	que = (int *)malloc(sizeof(int)*vertex);
	for (int i = 0; i < vertex; i++)
	{
		que[i] = 0;
	}
	int v1, v2;
	while (1)
	{
		scanf("%d %d", &v1, &v2);
		if (v1 == -1 && v2 == -1)
		{
			break;
		}
		addEdge(v1, v2);
	}
	scanf("%d %d", &v1, &v2);
	printf("%d", doBFS(v1, v2)); //same
}
#endif

#if 0
//최단경로
#include<stdio.h>
#include<stdlib.h>
struct node {
	int v;
	int w;
	struct node *next;
};
struct node **graph;
struct edges {
	int from;
	int to;
	int w;
};
struct edges *edge;
int *cycle;
int vertex;
int edge_n = 0;
int sum = 0;
void addEdge(int v1, int v2, int w)
{
	struct node*cur = graph[v1];
	struct node*new = (struct node*)malloc(sizeof(struct node));
	new->v = v2;
	new->w = w;
	new->next = 0;
	if (cur == 0)
	{
		graph[v1] = new;
	}
	else
	{
		while (cur->next != 0)
		{
			cur = cur->next;
		}
		cur->next = new;
	}
}
void swap(int i, int j)
{
	struct edges temp;
	temp = edge[i];
	edge[i] = edge[j];
	edge[j] = temp;
}
void sort()
{
	int i;
	int cnt = 0;
	for (i = 0; i < vertex; i++)
	{
		struct node *cur = graph[i];
		while (cur != 0)
		{
			edge[cnt].from = i;
			edge[cnt].to = cur->v;
			edge[cnt].w = cur->w;
			cnt++;
			cur = cur->next;
		}
	}
	int j;
	for (i = 0; i < edge_n; i++)
	{
		for (j = 0; j < edge_n - 1 - i; j++)
		{
			if (edge[j].w > edge[j + 1].w)
			{
				swap(j, j + 1);
			}
		}
	}
}
void group(int v1, int v2)
{
	int big = 0;
	int small = 0;
	if (v1 > v2)
	{
		big = v1;
		small = v2;
	}
	else
	{
		big = v2;
		small = v1;
	}
	int i;
	for (i = 0; i < vertex; i++)
	{
		if (cycle[i] == big)
		{
			cycle[i] = small;
		}
	}
}
void doMST()
{
	int cnt = 0;
	int i;
	for (i = 0; i < edge_n; i++)
	{
		while (cycle[edge[i].from] != cycle[edge[i].to])
		{
			group(cycle[edge[i].from], cycle[edge[i].to]);
			cnt++;
			printf("%d", edge[i].w);

			sum = sum + edge[i].w;
			if (cnt == vertex - 1)
			{
				return;
			}
		}
	}
}
int main(void)
{
	scanf("%d", &vertex);
	graph = (struct node*)malloc(sizeof(struct node)*vertex);
	cycle = (int*)malloc(sizeof(int)*vertex);
	int i;
	int v1, v2, w;
	for (i = 0; i < vertex; i++)
	{
		graph[i] = 0;
		cycle[i] = i;
	}
	while (1)
	{
		scanf("%d %d %d", &v1, &v2, &w);
		if (v1 == -1 && v2 == -1 && w == -1)
		{
			break;
		}
		addEdge(v1, v2, w);
		edge_n++;
	}
	edge = (struct edges*)malloc(sizeof(struct edges)*edge_n);
	sort();
	doMST();
	printf("%d", sum);
}
#endif

#if 0
#include<stdio.h>
#include<string.h>
#include<math.h>
int sz;
int **board;
int cnt = 0;

void clearRow(int _r) {
	memset(&board[_r][0], 0, sizeof(int)*sz);
}
int OK(int _r, int _c) {
	for (int i = 0; i < _r; i++)
	{
		if (board[i][_c] != 0)
		{
			return 0;
		}
	}
	for (int i = 0; i < _c; i++)
	{
		if (board[_r][i] != 0)
		{
			return 0;
		}
	}
	for (int i = 0; i < _r; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (board[i][j] != 0 && abs(i - _r) == abs(j - _c))
			{
				return 0;
			}
		}
	}
	return 1;
}
void show() {
	cnt++;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			printf("%d ", board[i][j]);
		}printf("\n");
	}printf("\n");
}
void checknext(int _r) {
	for (int i = 0; i < sz; i++)
	{
		clearRow(_r);
		if (OK(_r, i) == 1)
		{
			board[_r][i] = 1;
			if (_r == sz - 1)
			{
				show();
				return;
			}
			checknext(_r + 1);
		}
	}
}
int main() {
	scanf("%d", &sz);
	board = (int**)malloc(sizeof(int*)*sz);
	for (int i = 0; i < sz; i++)
	{
		board[i] = (int*)malloc(sizeof(int)*sz);
		memset(board[i], 0, sizeof(int*)*sz);
	}

	for (int c = 0; c < sz; c++)
	{
		clearRow(0);
		if (OK(0, c) == 1)
		{
			board[0][c] = 1;
			checknext(1);
		}
	}
	printf("cnt = %d", cnt);
}
#endif

#if 0
#include<stdio.h>
#include<string.h>
#include<math.h>
#define sz 8
int board[sz][sz];
int row;
int col;
int cnt = 0;


int OK() {
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (board[i][j] == '*')
			{
				int _r = i;
				int _c = j;

				for (int k = 0; k < sz; k++)
				{
					if (board[k][_c] != '.' && k != _r)
					{
						return 1;
					}
				}
				for (int k = 0; k < sz; k++)
				{
					if (board[_r][k] != '.' &&k != _c)
					{
						return 1;
					}
				}
				for (int k = 0; k < sz; k++)
				{
					for (int l = 0; l < sz; l++)
					{
						if (board[k][l] != '.' && abs(k - _r) == abs(l - _c) && k != _r && l != _c)
						{
							return 1;
						}
					}
				}
			}
		}
	}
	return -1;
	
}
void find() {
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (board[i][j] == '*')
			{
				row = i;
				col = j;
			}
		}
	}
}
int main() {

	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			scanf("%c", &board[i][j]);
		}
	}
		//find();
		////printf("%d", OK(row, col));
		if (OK()==-1)
		{
			printf("valid");
			//break;
		}
		if (OK()==1)
		{
			printf("invalid");
		//	break;
		}


}

#if 0
#include<stdio.h>
#define sz 5
int cnt = 0;
int n;
int m;
int map[sz][sz];
struct stra_info {
	int found;
	int d;
	int pre_r;
	int pre_c;
};
struct stra_info table[sz][sz];

struct coord {
	int row;
	int col;
};

void initTable() {
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			table[i][j].found = 0;
			table[i][j].d = 9999;
			table[i][j].pre_r = -1;
			table[i][j].pre_c = -1;
		}
	}
}

struct coord find() {
	struct coord s_coord;
	int s_d = 9999;

	s_coord.row = -1;
	s_coord.col = -1;

	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (table[i][j].found == 0 && table[i][j].d < s_d)
			{
				s_d = table[i][j].d;
				s_coord.row = i;
				s_coord.col = j;
			}
		}
	}
	return s_coord;
}

void check(int r, int c, int nr, int nc) {
	if (nr < 0 || nr >= sz || nc < 0 || nc >= sz)
	{
		return;
	}
	if (map[nr][nc] == 1)
	{
		return;
	}
	if (table[nr][nc].d > table[r][c].d + 1)
	{
		table[nr][nc].d = table[r][c].d + 1;
		table[nr][nc].pre_r = r;
		table[nr][nc].pre_c = c;
	}
}

void update(int r, int c) {
	check(r, c, r + 1, c);
	check(r, c, r - 1, c);
	check(r, c, r, c + 1);
	check(r, c, r, c - 1);
}

void show() {
	printf("1");
}

int main() {
	scanf("%d %d", &m, &n);
	int r, c, n;
	while (1)
	{
		scanf("%d %d %d", &r, &c, &n);
		if (r == -1 && c == -1 && n == -1)
		{
			break;
		}
		map[r][c] = n;
	}
	int start_r, start_c;
	scanf("%d %d", &start_r, &start_c);

	int end_r, end_c;
	scanf("%d %d", &end_r, &end_c);

	initTable();
	table[start_r][start_c].found = 1;
	table[start_r][start_c].d = 0;
	update(start_r, start_c);

	while (1)
	{
		struct coord small = find();
		if (small.row == -1 && small.col == -1)
		{
			break;
		}
		table[small.row][small.col].found = 1;
		update(small.row, small.col);
	}

	int tr = end_r;
	int tc = end_c;
	while (1)
	{
		if (map[tr][tc] == 0)
		{
			cnt++;
		}

		int temp_r = table[tr][tc].pre_r;
		int temp_c = table[tr][tc].pre_c;

		tr = temp_r;
		tc = temp_c;
		if (tr == -1 && tc == -1)
		{
			break;
		}
	}
	printf("%d", cnt - 1);
}
#endif

#if 0
#include <stdio.h>
int m, n;
unsigned int ** map;
int cnt = 0;

void ccheck(int v1, int v2)
{
	if (v1 >= m || v2 >= n || v1 < 0 || v2 < 0)
	{
		return;
	}
	if (map[v1][v2] == 0)
	{
		cnt++;
	}
	return;
}

void check(int v1, int v2)
{
	ccheck(v1 + 1, v2);
	ccheck(v1 - 1, v2);
	ccheck(v1, v2 + 1);
	ccheck(v1, v2 - 1);
}

int main(void)
{
	scanf("%d %d", &m, &n);

	map = (unsigned int **)malloc(sizeof(unsigned int*)*m);
	for (int i = 0; i < m; i++)
	{
		map[i] = (int*)malloc(sizeof(unsigned int)*n);
		memset(map[i], 0, sizeof(unsigned int)*n);
	}

	int v1, v2, v3;
	while (1)
	{
		scanf("%d %d %d", &v1, &v2, &v3);
		if (v1 == -1 && v2 == -1 && v3 == -1)
		{
			break;
		}
		map[v1][v2] = v3;
	}

	scanf("%d %d", &v1, &v2);
	check(v1, v2);
	printf("%d", cnt);
}
#endif

#if 0
#include <stdio.h>
int vertex;
struct node {
	int v;
	int w;
	struct node* next;
};
struct node ** graph;
struct dijkstra {
	int found;
	int d;
	int prev_v;
};
struct dijkstra *table;
void _putEdge(int v1, int v2, int w)
{
	struct node * new_one = (struct node *)malloc(sizeof(struct node));
	new_one->v = v2;
	new_one->w = w;
	new_one->next = 0;

	struct node * cur = graph[v1];
	if (cur == 0)
	{
		graph[v1] = new_one;
		return;
	}
	else
	{
		while (cur->next != 0)
		{
			cur = cur->next;
		}
		cur->next = new_one;
		return;
	}
}

void addEdge(int v1, int v2, int w)
{
	_putEdge(v1, v2, w);
	_putEdge(v2, v1, w);
}
void inittable()
{
	int i;
	for (i = 0; i < vertex; i++)
	{
		table[i].found = 0;
		table[i].d = 99999;
		table[i].prev_v = -1;
	}
}
void show()
{
	int i;
	for (i = 0; i < vertex; i++)
	{
		printf("%d : %d %d %d\n", i, table[i].found, table[i].d, table[i].prev_v);
	}
}

void update(int v)
{
	struct node *cur = graph[v];
	while (cur != 0)
	{
		if (table[cur->v].found == 0 && table[cur->v].d > table[v].d + cur->w)
		{
			table[cur->v].d = table[v].d + cur->w;
			table[cur->v].prev_v = v;
		}
		cur = cur->next;
	}
}

int find()
{
	int small_v = -1;
	int small_d = 99999;
	int i;
	for (i = 0; i < vertex; i++)
	{
		if (table[i].found == 0 && table[i].d < small_d)
		{
			small_d = table[i].d;
			small_v = i;
		}
	}
	return small_v;
}

void Dijkstra(int v)
{
	int next_v = -1;
	table[v].d = 0;
	while ((next_v = find()) != -1)
	{
		table[next_v].found = 1;
		update(next_v);
	}
	show();
}

int main()
{
	int v1, v2, w;
	scanf("%d", &vertex);
	graph = (struct node **)malloc(sizeof(struct node*)*vertex);
	memset(graph, 0, sizeof(struct node*)*vertex);

	while (1)
	{
		scanf("%d %d %d", &v1, &v2, &w);
		if (v1 == -1 && v2 == -1 && w == -1)
		{
			break;
		}
		addEdge(v1, v2, w);
	}

	table = (struct dijkstra *)malloc(sizeof(struct dijkstra)*vertex);
	memset(table, 0, sizeof(struct dijkstra)*vertex);

	inittable();
	Dijkstra(0);
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void *show(char *p_str) {
	int *lps = (int *)malloc(sizeof(int)*strlen(p_str));
	memset(lps, 0, sizeof(int)*strlen(p_str));

	int p_len = strlen(p_str);

	int j = 0;
	for (int i = 1; i < p_len; i++)
	{
		while (j>0 && p_str[i]!=p_str)
		{
			j = lps[j - 1];
		}
		if (p_str[i]==p_str[j])
		{
			j++;
			lps[i] = j;
		}
	}
	return lps;
}
void main() {
	char t_str[1000] = "";
	scanf("%s", t_str);
	char p_str[1000] = "";
	scanf("%s", p_str);

	int t_len = strlen(t_str);
	int p_len = strlen(p_str);

	int *lps = show(p_str);
	int j = 0;
	for (int i = 0; i < t_len; i++)
	{
		while (j>0 && t_str[i]!=p_str[j])
		{
			j = lps[j - 1];
		}
		if (p_str[j]==t_str[i])
		{
			if (j==p_len-1)
			{
				printf("%d\n", i - j);
				j = 0;
			}
			else
			{
				j++;
			}
		}
	}
}
#endif
