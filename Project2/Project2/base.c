//#include<stdio.h>
//#include<stdlib.h>
//struct node {
//	int data;
//	struct node*next;
//	struct node*pre;
//};
//struct node*head = 0;
//void addtodll(int _data) {
//	struct node*new = (struct node*)malloc(sizeof(struct node));
//	new->data = _data;
//	new->pre = new->next = 0;
//	struct node*temp = head;
//	if (head==0)
//	{
//		head = new;
//		return;
//	}
//	while (temp->next!=0)
//	{
//		temp = temp->next;
//	}
//	temp->next = new;
//	new->pre = temp;
//}
//void reverselist() {
//	struct node*temp = head;
//	struct node*pre = 0, *cur = 0;
//	while (temp!=0)
//	{
//		cur = temp->next;
//		temp->next = pre;
//		pre = temp;
//		temp = cur;
//	}
//	head = pre;
//}
//void showdll() {
//	struct node*temp = head;
//	while (temp!=0)
//	{
//		printf("%d ", temp->data);
//		temp = temp->next;
//	}
//}
//int main() {
//	int num;
//	int data;
//	while (1)
//	{
//		scanf("%d", &data);
//		if (data==-999)
//		{
//			break;
//		}
//		addtodll(data);
//	}
//	reverselist();
//	showdll();
//}