#include<stdio.h>

#if 0
int main() {
	int arrA[5][6] = { {1,2,3,4,5,6}, {1,2,3,4,5,6}, {1,2,3,4,5,6}, {1,2,3,4,5,6}, {1,2,3,4,5,6}};
	int arrB[5][6] = { {6,5,4,3,2,1}, {6,5,4,3,2,1}, {6,5,4,3,2,1}, {6,5,4,3,2,1}, {6,5,4,3,2,1}};
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			arrA[i][j] = arrA[i][j] + arrB[i][j];
			printf("%d ", arrA[i][j]);
		}
		printf("\n");
	}
}
#endif

#if 0
int main() {
	int row, col;
	scanf("%d %d", &row, &col); //가로 세로 입력
	char a[8][8];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			a[i][j] = '*'; //2차원 배열에 * 저장

	for (int i = 2; i < row - 2; i++)
		for (int j = 2; j < col - 2; j++)
			a[i][j] = '#'; //2줄짜리 테두리 이외는 #으로 다시 저장

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%c", a[i][j]); //저장한 2차원 배열 출력
		printf("\n");
	}
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int arr[8][8];

	for (int i = 0; i < a; i++) 
		for (int j = 0; j < b; j++){
			arr[i][j] = '*';
			if (i>1 && i<a-2 && j>1 && j<b-2)
				arr[i][j] = '#';
		}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
			printf("%c ", arr[i][j]);
		printf("\n");
	}
}

int main() {
	int row, col;
	scanf("%d %d", &row, &col);

	int a[8] = { 0, };
	int flag = 1;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i > 1 && i < row - 2 && j>1 && j < col - 2) a[i] = a[i] + flag;
			flag = flag << 1;
		}
		flag = 1;
	}

	flag = 1;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if ((a[i] & flag) > 0) printf("#");
			else printf("*");
			flag = flag << 1;
		}
		printf("\n");
		flag = 1;
	}
}
#endif

#if 0
int main() {
	int row, col;
	scanf("%d %d", &row, &col);
	char a[8];

	for (int i = 0; i < row; i++)	//세로
	{
		for (int j = 0; j < col; j++) //가로
		{
			a[j] = '*'; //1차원 배열에 세로 입력값만큼 * 저장
			if (i > 1 && j > 1 && j < col - 2 && i < row - 2)
				a[j] = '#'; //2줄짜리 테두리 이외는 #으로 다시 저장
			printf("%c", a[j]);
		}printf("\n");
	}
}
#endif