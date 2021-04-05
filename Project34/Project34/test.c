//#include<stdio.h>
//#include<stdlib.h>
//struct node {
//	int data;
//	struct node*next;
//};
//struct node*head = 0;
//
//void addToSLL(int _data) {
//	struct node*new = (struct node*)malloc(sizeof(struct node));
//	new->data = _data;
//	new->next = 0;
//	struct node*temp = head;
//	if (head == 0)
//	{
//		head = new;
//		return;
//	}
//	else
//	{
//		if (temp->data == _data)return;
//		while (temp->next != 0)
//		{
//			temp = temp->next;
//			if (temp->data == _data)return;
//		}
//		temp->next = new;
//		return;
//	}
//}
//void reverseList() {
//	struct node*temp = head;
//	struct node*pre = 0, *cur = 0;
//	while (temp != 0)
//	{
//		cur = temp->next;
//		temp->next = pre;
//		pre = temp;
//		temp = cur;
//	}
//	head = pre;
//}
//void showSLL() {
//	struct node*temp = head;
//	while (temp != 0)
//	{
//		printf("%d ", temp->data);
//		temp = temp->next;
//	}
//}
//int main() {
//	int data;
//
//	while (1)
//	{
//		scanf("%d", &data);
//		if (data < 0)
//		{
//			reverseList();
//			showSLL();
//			break;
//		}
//		addToSLL(data);
//	}
//}
#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node*next;
};
struct node *head = 0;

void addToSLL(int _data) {
	struct node*new = (struct node*)malloc(sizeof(struct node));
	new->data = _data;
	new->next = 0;
	if (head == 0)
	{
		head = new;
		return;
	}
	else
	{
		struct node *temp = head, *before = head;
		while (temp->next != 0)
		{
			temp = temp->next;
		}
		temp->next = new;
		temp = head;
		while (temp->next != 0)
		{
			if (temp->data == _data)
			{
				if (temp == head)
				{
					head = head->next;
					free(temp);
					return;
				}
				else
				{
					while (before->next != temp)
					{
						before = before->next;
					}
					before->next = temp->next;
					free(temp);
					return;
				}
			}
			temp = temp->next;
		}
	}
}
void reverseList() {
	struct node*temp = head;
	struct node*pre = 0, *cur = 0;
	while (temp != 0)
	{
		cur = temp->next;
		temp->next = pre;
		pre = temp;
		temp = cur;
	}
	head = pre;
}
void showSLL() {
	struct node*temp = head;
	while (temp != 0)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}
int main() {
	int data;
	while (1)
	{
		scanf("%d", &data);
		if (data < 0)
		{
			reverseList();
			showSLL();
			break;
		}
		addToSLL(data);
	}
	return 0;
}