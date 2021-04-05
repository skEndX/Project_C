//#include<stdio.h>
//#define SZ 10
//int num[SZ];
//void swap(int i, int j) {
//	int temp = num[i];
//	num[i] = num[j];
//	num[j] = temp;
//}
//void sort(int pi, int _left, int _right) {
//	int left = _left;
//	int right = _right;
//
//	if (_left > _right)return;
//	while (1)
//	{
//		while (num[left] < num[pi])
//		{
//			left++;
//		}
//		while (num[right] > num[pi])
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			swap(left, right);
//		}
//		else
//		{
//			swap(pi, right);
//			int data;
//			scanf("%d", &data);
//			printf("%d",num[data]);
//			return;
//		}
//	}
//}
//int main() {
//	int cnt;
//	int data;
//	scanf("%d", &cnt);
//	for (int i = 0; i < cnt; i++)
//	{
//		scanf("%d", &data);
//		num[i] = data;
//	}
//	sort(0, 1, cnt - 1);
//	return 0;
//}
#include<stdio.h>
#define SZ 30
struct node {
	char name[SZ];
	struct node*next;
};
struct node*table[SZ];
int hash(char *str) {
	int sum = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		sum += str[i];
	}
	return(sum%10);
}
void addTohash(char *name) {
	struct node*new = (struct node*)malloc(sizeof(struct node));
	strcpy(new->name, name);
	new->next = 0;

	int idx = hash(name);
	struct node*temp = table[idx];
	if (table[idx] == 0)
	{
		table[idx] = new;
		return;
	}
	while (temp->next != 0)
	{
		temp = temp->next;
	}
	temp->next = new;
	return;
}
void search(char *name) {
	int idx = hash(name);
	struct node*temp = table[idx];
	if (temp == 0)return;
	while (strcmp(temp->name, name) != 0)
	{
		temp = temp->next;
		if (temp == 0)return;
	}
	printf("%s", temp->name);
}
int main() {
	char str[SZ];
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%s", str);
		addTohash(str);
	}
	search("abc");
}