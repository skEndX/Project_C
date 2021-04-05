
#include<stdio.h>
#include<string.h>
#define sz 9
int sdk[sz][sz] = {0};
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
	if (_r==sz-1&&_c==sz-1)
	{
		show();
		return;
	}
	_c++;
	if (_c==sz)
	{
		_c = 0;
		_r++;
	}
	solve(_r, _c);
}
int OK(int _r, int _c, int value) {
	for (int i = 0; i < sz; i++)
	{
		if (sdk[i][_c]==value&&i!=_r)
		{
			return 0;
		}
	}
	for (int i = 0; i < sz; i++)
	{
		if (sdk[_r][i]==value&&i!=_c)
		{
			return 0;
		}
	}
	int row = _r / 3;
	int col = _c / 3;
	for (int i = row*3; i < row*3+2; i++)
	{
		for (int j = col*3; j < col*3+2; j++)
		{
			if (sdk[i][j]==value&&i!=_r&&j!=_c)
			{
				return 0;
			}
		}
	}
	return 1;
}
void solve(int _r, int _c) {
	if (sdk[_r][_c]>0)
	{
		checknext(_r, _c);
		return;
	}
	for (int i = 1; i < 10; i++)
	{
		memcpy(&sdk[_r][_c], &readsdk[_r][_c], sizeof(int)*sz*sz - sizeof(int)*(_r*sz + _c));
		if (OK(_r,_c,i)==1)
		{
			sdk[_r][_c] = i;
			checknext(_r, _c);
		}
	}
}

int main() {

	scanf("%s\n", sdk);
	read();
	solve(0, 0);
	return 0;
}

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
	for (int i = 0; i < _c; i++)
	{
		if (board[_r][i]!=0)
		{
			return 0;
		}
	}
	for (int i = 0; i < _r; i++)
	{
		if (board[i][_c]!=0)
		{
			return 0;
		}
	}
	for (int i = 0; i < _r; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (abs(i-_r)==abs(j-_c)&&board[i][j]!=0)
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
	}printf("\n");
}
void checknext(int _r) {
	for (int i = 0; i < sz; i++)
	{
		clearRow(_r);
		if (OK(_r,i)==1)
		{
			board[_r][i] = 1;
			if (_r==sz-1)
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
		if (OK(0,c)==1)
		{
			board[0][c] = 1;
			checknext(1);
		}
	}
}
#endif