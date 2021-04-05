////quick sort는 시간 복잡도는 O(nlogn), 나머지 sort들은 O(n^2)
//#include<stdio.h>
//#define SZ 10
//int number[SZ] = {50,100,20,65,89,13,45,34,10,76};
//
//void swap(int left, int right) {
//	int temp = number[left];
//	number[left] = number[right];
//	number[right] = temp;
//}
//
//void quicksort(int _pivot, int _left, int _right) {
//	int left = _left;
//	int right = _right;
//
//	//left는 right보다 항상 작아야함(탈출 조건), 같을 수도 있기 때문에 _left>_right로 해줘야 함
//	if (_left > _right) return;
//
//	while (1)
//	{
//		while (number[left] < number[_pivot])
//		{
//			left++;
//		}
//		while (number[right] > number[_pivot])
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			swap(left, right);
//		}
//		else //cross가 된 경우
//		{
//			swap(_pivot, right);
//			quicksort(_pivot,_pivot+1,right-1);	//왼쪽
//			quicksort(right+1,right+2,_right);	//오른쪽
//			return;
//		}
//	}
//}
//
//int main() {
//	quicksort(0,1,SZ-1);
//	for (int i = 0; i < SZ; i++)
//	{
//		printf("%d ", number[i]);
//	}
//	printf("\n");
//	return 0;
//}