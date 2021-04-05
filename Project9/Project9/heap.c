//#include <stdio.h>
//
//#define SIZE 10
//
//int heap[SIZE];
//int last = 0;
//
//void swap(int a, int b) {
//	int temp = heap[a];
//	heap[a] = heap[b];
//	heap[b] = temp;
//}
//
//void enque(int _data) {
//	if (last - 1 == SIZE) {
//		return;
//	}
//	last = last + 1;
//	heap[last] = _data;
//
//	int cur = last;
//	int par = cur / 2;
//
//	while (1) {
//		if (cur == 1 || heap[cur] < heap[par]) {
//			return;
//		}
//		swap(cur, par);
//		cur = par;
//		par = cur / 2;
//	}
//}
//
//int check(int cur) {
//	int left = cur * 2;
//	int right = left + 1;
//
//	if (left > last) return 0;
//	else if (last == left) {
//		if (heap[left] > heap[cur]) {
//			swap(left, cur);
//			return left;
//		}
//		else return 0;
//	}
//	else {
//		if (heap[left] > heap[cur] && heap[right] > heap[cur]) {
//			if (heap[left] > heap[right]) {
//				swap(cur, left);
//				return left;
//			}
//			else {
//				swap(cur, right);
//				return right;
//			}
//		}
//		else if (heap[left] > heap[cur]) {
//			swap(cur, left);
//			return left;
//		}
//		else if (heap[right] > heap[cur]) {
//			swap(cur, right);
//			return right;
//		}
//		else return 0;
//	}
//}
//
//void deque() {
//	if (last == 0) return;
//	else {
//		int c_idx = 1;
//		int ret = heap[1];
//		heap[1] = heap[last--];
//
//		while (1) {
//			c_idx = check(c_idx);
//			if (c_idx == 0) {
//				printf("%d ", ret);
//				return;
//			}
//		}
//	}
//}
//
//void main() {
//	int num;
//	int data;
//	scanf("%d", &num);
//	for (int i = 0; i < num; i++)
//	{
//		scanf("%d", &data);
//		enque(data);
//	}
//	for (int i = 0; i < num; i++)
//	{
//		deque();
//	}
//}
