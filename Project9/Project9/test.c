#include<stdio.h>

void printfALL(int *play, int size) {
	for (int i = 0; i < size; i++)
	{
		printf("%d ", play[i]);
	}
	printf("\n\n");
}

void insertsort(int *play, int sz) {
	for (int i = 1; i < sz; i++)
	{
		int j = i;
		while ((j-1)>=0 && play[j-1]>play[j])
		{
			int temp = play[j - 1];
			play[j - 1] = play[j];
			play[j] = temp;
			j--;
		}
		printfALL(play, sz);
	}
}

int main() {
	int data[10] = { 31,24,56,1,4,10,6,76,87,30 };
	printfALL(data, 10);
	printf("\n\n");
	insertsort(data, 10);
}