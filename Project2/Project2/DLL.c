//#include <stdio.h>
//typedef struct node {
//	int data;
//	struct node *next;
//	struct node *prev;
//}NODE;
//NODE *head = 0;
//
//NODE *findDLL(int _data)
//{
//	NODE *temp = head;
//	while (temp != 0)
//	{
//		if (temp->data == _data)
//		{
//			return temp;
//		}
//		temp = temp->next;
//	}
//	return 0;
//}
//
//void addDLL(int _data)
//{
//	NODE *new_one =(NODE *)malloc(sizeof(NODE));
//	new_one->data = _data;
//	new_one->next = new_one->prev = 0;
//	if (head == 0)
//	{
//		head = new_one;
//		return;
//	}
//	NODE *check = findDLL(_data);
//
//	if (check == 0)
//	{
//		NODE *temp = head;
//
//		while (temp->next != 0)
//		{
//			temp = temp->next;
//		}
//		temp->next = new_one;
//		new_one->prev = temp;
//	}
//	else
//	{
//		NODE *temp2 = head;
//		if (check == head)
//		{
//			return;
//		}
//		if (check->next != 0)
//		{
//			check->next->prev = check->prev;
//		}
//		check->prev->next = check->next;
//
//		check->next = head;
//		head->prev = check;
//		check->prev = 0;
//
//		head = check;
//
//	}
//}
//
//void showDLL()
//{
//	NODE *temp = head;
//	while (temp->next != 0)
//	{
//		temp = temp->next;
//	}
//	NODE *tail = temp;
//	while (tail != 0)
//	{
//		printf("%d ", tail->data);
//		tail = tail->prev;
//	}
//	return;
//}
//
//int main()
//{
//	int n, i, data, f;
//	while (1)
//	{
//		scanf("%d", &data);
//		if (data == -999)
//		{
//			break;
//		}
//		addDLL(data);
//	}
//	showDLL();
//}