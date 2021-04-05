#include<stdio.h>
#define SZ 10
int num[SZ] = {10,25,46,1,64,35,95,37,57,84};

void swap(int left, int right) {
	int temp = num[left];
	num[left] = num[right];
	num[right] = temp;
}

void sort(int _pi, int _left, int _right) {
	int left = _left;
	int right = _right;

	if (_left > _right) return;

	while (1)
	{
		while (num[left]<num[_pi])
		{
			left++;
		}
		while (num[right] > num[_pi])
		{
			right--;
		}
		if (left<right)
		{
			swap(left, right);
		}
		else
		{
			swap(_pi, right);
			sort(_pi, _pi + 1, right-1);
			sort(right + 1, right + 2, _right);
			return;
		}
	}
}

int main() {
	sort(0, 1, SZ - 1);
	for (int i = 0; i < SZ; i++)
	{
		printf("%d ", num[i]);
	}
	return 0;
}