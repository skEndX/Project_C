//#include<stdio.h>
//
//void swap(int *arr, int i, int j) {
//	int temp = arr[i];
//	arr[i] = arr[j];
//	arr[j] = temp;
//}
//void printfALL(int *play, int size) {
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", play[i]);
//	}
//	printf("\n\n");
//}
//void bubblesort(int *play, int size) {
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size-1-i; j++)
//		{
//			if (play[j]>play[j+1])
//			{
//				int temp = play[j];
//				play[j] = play[j + 1];
//				play[j + 1] = temp;
//			}
//		}
//		printfALL(play, 10);
//	}
//}
//
//int findsmall(int *arr, int idx, int size) {
//	int small_idx = idx;
//	int small = arr[idx];
//
//	for (int i =idx; i < size; i++)
//	{
//		if (arr[i]<small)
//		{
//			small = arr[i];
//			small_idx=i;
//		}
//	}
//	return small_idx;
//}
//
//void selectionsort(int *play, int size) {
//	for (int i = 0; i < size; i++)
//	{
//		int j = findsmall(*play, i, size);
//		/*int temp = play[i];
//		play[i] = play[j];
//		play[j] = temp;*/
//		swap(play, i, j);
//		printfALL(play, size);
//	}
//}
//int main() {
//	int data[10] = {31,24,56,1,4,10,6,76,87,30};
//	printfALL(data, 10);
//	//printf("\n\n");
//	//bubblesort(data, 10);
//	printf("\n\n");
//	selectionsort(data, 10);
//}