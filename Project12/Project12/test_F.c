#if 0
#include<stdio.h>
struct node {
	int data;
	struct node*left;
	struct node*right;
};
struct node*root = 0;

void addToBST(int _data) {
	struct node*new = (struct node*)malloc(sizeof(struct node));
	new->data = _data;
	new->left = new->right = 0;
	struct node*temp = root;

	if (root==0)
	{
		root = new;
		return;
	}
	while (1)
	{
		if (new->data<temp->data)
		{
			if (temp->left==0)
			{
				temp->left = new;
				return;
			}temp = temp->left;
		}
		else
		{
			if (temp->right==0)
			{
				temp->right = new;
				return;
			}temp = temp->right;
		}
	}
}
struct node*del(struct node*node, int _data) {
	if (node == 0) return 0;
	if (_data==node->data)
	{
		if (node->left==0&&node->right==0)
		{
			free(node);
			return;
		}
		else if (node->left==0)
		{
			struct node*temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right==0)
		{
			struct node*temp = node->left;
			free(node);
			return temp;
		}
		else
		{
			struct node*temp = node->right;
			while (temp->left!=0)
			{
				temp = temp->left;
			}
			node->data = temp->data;
			node->right = del(node->right, temp->data);
			return node;
		}
	}
	else if (_data<node->data)
	{
		node->left = del(node->left, _data);
		return node;
	}
	else
	{
		node->right = del(node->right, _data);
		return node;
	}
}
void inorder(struct node*node) {
	if (node == 0) return;
	inorder(node->left);
	printf("%d ", node->data);
	inorder(node->right);
}
int main() {
	int num;
	int data;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &data);
		addToBST(data);
	}
	inorder(root);
	scanf("%d", &data);
	del(root, data);
	inorder(root);
	return 0;
}
#endif

#if 0
#include<stdio.h>
#define SZ 100
int heap[SZ];
int last = 0;

void swap(int i, int j) {
	int temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
}
void enque(int _data) {
	if (last - 1 == SZ)return 0;
	last = last + 1;
	heap[last] = _data;

	int cur = last;
	int par = cur / 2;

	while (1)
	{
		if (cur==1||heap[cur]<heap[par])
		{
			return;
		}
		swap(cur, par);
		cur = par;
		par = cur / 2;
	}
}
int check(int cur) {
	int left = cur * 2;
	int right = left + 1;

	if (left > last)return 0;
	else if (left==last)
	{
		if (heap[left]>heap[cur])
		{
			swap(left, cur);
			return left;
		}
		else return 0;
	}
	else
	{
		if (heap[left] > heap[cur]&& heap[right] > heap[cur])
		{
			if (heap[left] > heap[right])
			{
				swap(left, cur);
				return left;
			}
			else
			{
				swap(right, cur);
				return right;
			}
		}
		else if (heap[left] > heap[cur])
		{
			swap(left, cur);
			return left;
		}
		else if (heap[right] > heap[cur])
		{
			swap(right, cur);
			return right;
		}
		else return 0;
	}
}
void deque() {
	int c_idx = 1;
	int ret = heap[1];
	heap[1] = heap[last];
	last = last - 1;

	while (1)
	{
		c_idx = check(c_idx);
		if (c_idx==0)
		{
			printf("%d ", ret);
			return;
		}
	}
}
int main() {
	int num;
	int data;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &data);
		enque(data);
	}
	for (int i = 0; i < num; i++)
	{
		deque();
	}return 0;
}
#endif

#if 0
#include<stdio.h>
void printfALL(int *play, int sz) {
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", play[i]);
	}printf("\n");
}
int bubble(int *play, int sz) {
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz-1-i; j++)
		{
			if (play[j]>play[j+1])
			{
				int temp = play[j];
				play[j] = play[j + 1];
				play[j + 1] = temp;
			}
		}
		printfALL(play, sz);
	}
}
int main() {
	int data[10] = { 31,24,56,1,4,10,6,76,87,30 };
	printfALL(data, 10);
	printf("\n\n");
	bubble(data, 10);
}
#endif

#if 0
#include<stdio.h>
void printfALL(int *play, int sz) {
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", play[i]);
	}printf("\n");
}
int find(int *arr, int idx, int sz) {
	int small_idx = idx;
	int small = arr[idx];
	for (int i = idx; i < sz; i++)
	{
		if (arr[i]<small)
		{
			small = arr[i];
			small_idx = i;
		}
	}
	return small_idx;
}
int select(int *play, int sz) {
	for (int i = 0; i < sz; i++)
	{
		int j = find(play, i, sz);
		int temp = play[i];
		play[i] = play[j];
		play[j] = temp;
		printfALL(play, sz);
	}
}
int main() {
	int data[10] = { 31,24,56,1,4,10,6,76,87,30 };
	printfALL(data, 10);
	printf("\n\n");
	select(data, 10);
}
#endif

#if 0
#include<stdio.h>
void printfALL(int *play, int size) {
	for (int i = 0; i < size; i++)
	{
		printf("%d ", play[i]);
	}
	printf("\n");
}
void insert(int *play, int sz) {
	for (int i = 1; i < sz; i++)
	{
		int j = i;
		while (j-1>=0&&play[j-1]>play[j])
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
	insert(data, 10);
}
#endif

#if 0
#include<stdio.h>
#define SZ 10
int num[SZ] = { 10,25,46,1,64,35,95,37,57,84 };
void swap(int i, int j) {
	int temp = num[i];
	num[i] = num[j];
	num[j] = temp;
}
void sort(int pi, int _left, int _right) {
	int left = _left;
	int right = _right;

	if (_left > _right)return;
	while (1)
	{
		while (num[left]<num[pi])
		{
			left++;
		}
		while (num[right]>num[pi])
		{
			right--;
		}
		if (left<right)
		{
			swap(left, right);
		}
		else
		{
			swap(pi, right);
			sort (pi, pi + 1, right - 1);
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
	}return 0;
}
#endif

#if 0
#include<stdio.h>
#define SZ 30
struct node {
	char name[SZ];
	int num;
	unsigned short age;
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
	return(sum%SZ);
}
void addTohash(char *name, int num, unsigned short age) {
	struct node*new = (struct node*)malloc(sizeof(struct node));
	strcpy(new->name, name);
	new->num = num;
	new->age = age;
	new->next = 0;

	int idx = hash(name);
	struct node*temp = table[idx];
	if (table[idx]==0)
	{
		table[idx] = new;
		return;
	}
	while (temp->next!=0)
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
	while (strcmp(temp->name,name)!=0)
	{
		temp = temp->next;
		if (temp == 0)return;
	}
	printf("%s %d %d", temp->name, temp->num, temp->age);
}
int main() {

}
#endif