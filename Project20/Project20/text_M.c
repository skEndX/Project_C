#if 0
#include<stdio.h>
#include<string.h>
#include<math.h>
int sz;
int **board;

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
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
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
	board = (int**)malloc(sizeof(int *)*sz);
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
}
#endif

#if 0
#include<stdio.h>
#include<string.h>
#include<math.h>
#define sz 8
int board[sz][sz];

int OK(int _r, int _c) {
	for (int i = 0; i < sz; i++)
	{
		if (board[i][_c] != 0 && i != _r)
		{
			return 1;
		}
	}
	for (int i = 0; i < sz; i++)
	{
		if (board[_r][i] != 0 && i != _c)
		{
			return 1;
		}
	}
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (board[i][j] != 0 && abs(i - _r) == abs(j - _c) && i != _r && j != _c)
			{
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	board[a][b] = 1;
	int a1, b1;
	scanf("%d %d", &a1, &b1);
	board[a1][b1] = 1;

	printf("%d", OK(a, b));
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

void initBoard() {
	memset(board, -1, sizeof(int)*sz*sz);
}

int OK(int _r, int _c) {
	for (int i = 0; i < sz; i++)
	{
		if (board[i][_c] != -1 && i != _r)
		{
			cnt++;
		}
	}
	for (int i = 0; i < sz; i++)
	{
		if (board[_r][i] != -1 && i != _c)
		{
			cnt++;
		}
	}
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (board[i][j] != -1 && abs(i - _r) == abs(j - _c) && i != _r && j != _c)
			{
				cnt++;
			}
		}
	}
	return cnt;
}

void find(int n) {
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (board[i][j] == n)
			{
				row = i;
				col = j;
			}
		}
	}
}

int main() {
	initBoard();
	int n, v1, v2;
	while (1)
	{
		scanf("%d %d %d", &n, &v1, &v2);
		if (n == -1 && v1 == -1 && v2 == -1)
		{
			break;
		}
		board[v1][v2] = n;
	}
	scanf("%d", &n);
	find(n);
	printf("%d", OK(row, col));
}
#endif

#if 0
#include<stdio.h>
#include<string.h>
#define sz 9
int sdk[sz][sz] = {
	4,0,7,5,0,0,0,0,8,
	0,5,0,7,0,0,4,0,9,
	0,0,6,0,0,4,0,7,0,
	9,0,0,6,0,0,2,4,3,
	0,4,0,9,0,3,0,8,0,
	7,3,1,0,0,2,0,0,5,
	0,2,0,8,0,0,7,0,0,
	3,0,9,0,0,6,0,5,0,
	5,0,0,0,0,7,3,0,4
};
int readsdk[sz][sz];
void solve(int _r, int _c);

void read() {
	memcpy(readsdk, sdk, sizeof(int)*sz*sz);
}

void show() {
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			printf("%d ", sdk[i][j]);
		}
		printf("\n");
	}
}

void checknext(int _r, int _c) {
	if (_r == sz - 1 && _c == sz - 1)
	{
		show();
		return;
	}
	_c++;
	if (_c == sz)
	{
		_c = 0;
		_r++;
	}
	solve(_r, _c);
}

int OK(int _r, int _c, int value) {
	for (int i = 0; i < sz; i++)
	{
		if (sdk[i][_c] == value && i != _r)
		{
			return 0;
		}
	}
	for (int i = 0; i < sz; i++)
	{
		if (sdk[_r][i] == value && i != _c)
		{
			return 0;
		}
	}
	int row = _r / 3;
	int col = _c / 3;
	for (int i = row * 3; i < row * 3 + 2; i++)
	{
		for (int j = col * 3; j < col * 3 + 2; j++)
		{
			if (sdk[i][j] == value && i != _r && j != _c)
			{
				return 0;
			}
		}
	}
	return 1;
}

void solve(int _r, int _c) {
	if (sdk[_r][_c] > 0)
	{
		checknext(_r, _c);
		return;
	}
	for (int i = 1; i <= sz; i++)
	{
		memcpy(&sdk[_r][_c], &readsdk[_r][_c], sizeof(int)*sz*sz - sizeof(int)*(_r*sz + _c - 1));
		if (OK(_r, _c, i) == 1)
		{
			sdk[_r][_c] = i;
			checknext(_r, _c);
		}
	}
}

int main() {
	read();
	solve(0, 0);
	return 0;
}
#endif

#if 0
#include<stdio.h>
int vertex;

struct node {
	int v;
	int w;
	struct node*next;
};
struct node **graph;

struct stra {
	int found;
	int d;
	int pre_v;
};
struct stra *table;

void putEdge(int v1, int v2, int w) {
	struct node*new = (struct node*)malloc(sizeof(struct node));
	struct node*cur = graph[v1];
	new->v = v2;
	new->next = 0;
	new->w = w;

	if (cur == 0)
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

void addEdge(int v1, int v2, int w) {
	putEdge(v1, v2, w);
	putEdge(v2, v1, w);
}

void initTable() {
	for (int i = 0; i < vertex; i++)
	{
		table[i].found = 0;
		table[i].d = 9999;
		table[i].pre_v = -1;
	}
}

int find() {
	int s_v = -1;
	int s_d = 9999;

	for (int i = 0; i < vertex; i++)
	{
		if (table[i].found == 0 && table[i].d < s_d)
		{
			s_d = table[i].d;
			s_v = i;
		}
	}
	return s_v;
}

void update(int v) {
	struct node*cur = graph[v];
	while (cur != 0)
	{
		if (table[cur->v].found == 0 && table[cur->v].d > table[v].d + cur->w)
		{
			table[cur->v].d = table[v].d + cur->w;
			table[cur->v].pre_v = v;
		}
		cur = cur->next;
	}
}

void show() {
	for (int i = 0; i < vertex; i++)
	{
		printf("%d : %d %d %d\n", i, table[i].found, table[i].d, table[i].pre_v);
	}
}

void Dijkstra(int v) {
	int next_v = -1;
	table[v].d = 0;
	while ((next_v = find()) != -1)
	{
		table[next_v].found = 1;
		update(next_v);
	}
	show();
}

int main() {
	scanf("%d", &vertex);
	graph = (struct node**)malloc(sizeof(struct node*)*vertex);
	memset(graph, 0, sizeof(struct node*)*vertex);

	while (1)
	{
		int v1, v2, w;
		scanf("%d %d %d", &v1, &v2, &w);
		if (v1 == -1 && v2 == -1 && w == -1)
		{
			break;
		}
		addEdge(v1, v2, w);
	}

	table = (struct stra*)malloc(sizeof(struct stra)*vertex);
	memset(table, 0, sizeof(struct stra)*vertex);

	initTable();
	Dijkstra(0);
}
#endif



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
	if (nr < 0 || nr >= sz|| nc < 0 || nc >= sz)
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
		if (r==-1 && c==-1 && n==-1)
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
		if (map[tr][tc]==0)
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
	printf("%d",cnt-1);
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
	int a, b;
	scanf("%d %d", &a, &b);

	if (a > 0 && a < sz && b > 0 && b < sz)
	{
		if (map[a][b - 1] == 0)
		{
			cnt++;
		}
		if (map[a][b + 1] == 0)
		{
			cnt++;
		}
		if (map[a - 1][b] == 0)
		{
			cnt++;
		}
		if (map[a + 1][b] == 0)
		{
			cnt++;
		}
	}
	if (a<=0)
	{
		if (map[a + 1][b] == 0)
		{
			cnt++;
		}
		if (map[a][b - 1] == 0)
		{
			cnt++;
		}
		if (map[a][b + 1] == 0)
		{
			cnt++;
		}
		if (b<=0)
		{
			if (map[a][b + 1] == 0)
			{
				cnt++;
			}
			if (map[a + 1][b] == 0)
			{
				cnt++;
			}
		}
	}
	if (b<=0)
	{
		if (map[a][b + 1] == 0)
		{
			cnt++;
		}
		if (map[a - 1][b] == 0)
		{
			cnt++;
		}
		if (map[a + 1][b] == 0)
		{
			cnt++;
		}
	}
	if (a>=sz)
	{
		if (map[a][b - 1] == 0)
		{
			cnt++;
		}
		if (map[a][b + 1] == 0)
		{
			cnt++;
		}
		if (map[a - 1][b] == 0)
		{
			cnt++;
		}
	}
	if (b>=sz)
	{
		if (map[a][b - 1] == 0)
		{
			cnt++;
		}
		if (map[a - 1][b] == 0)
		{
			cnt++;
		}
		if (map[a + 1][b] == 0)
		{
			cnt++;
		}
	}
	printf("%d", cnt);
}
#endif