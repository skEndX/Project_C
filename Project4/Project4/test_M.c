#include<stdio.h>
#define size 5
int stack[size];
int top = -1;

int push(int _data) {
	int add = 0;
	if (top==size-1)
	{
		return;
	}
	if (_data==-1)
	{
		while (top!=-1)
		{
			add = add + pop();
		}
		push(add);
		return;
	}
	if (_data>0)
	{
		top = top + 1;
		stack[top] = _data;
		return;
	}
}
int pop() {
	int result = 0;
	if (top==-1)
	{
		return;
	}
	result = stack[top];
	top = top - 1;
	return result;
}
int main() {
	int data;
	while(1)
	{
		scanf("%d", &data);
		if (data == -100)
		{
			if (top==-1)
			{
				return;
			}
			printf("%d", pop());
			return;
		}
		push(data);
	}
}


#if 0
#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node*next;
	struct node*pre;
};
struct node*head = 0;
void addToDLL(int _data) {
	struct node*new = (struct node*)malloc(sizeof(struct node));
	new->data = _data;
	new->next = new->pre = 0;
	struct node*temp = head;
	if (head==0)
	{
		head = new;
		return;
	}
	while (temp->next!=0)
	{
		temp = temp->next;
	}
	temp->next = new;
	new->pre = temp;
}
int pop() {
	struct node*temp = head;
	if (head==0)
	{
		return;
	}
	if (head->next==0)
	{
		head = head->next;
		free(temp);
		return;
	}
	while (temp->next!=0)
	{
		temp = temp->next;
	}
	temp->pre->next = 0;
	free(temp);
	return;
}
void showDLL() {
	struct node*temp = head;
	if (head==0)
	{
		printf("Nothing");
		return;
	}
	while (temp!=0)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}
int main() {
	int cmd;
	int value;
	while (1)
	{
		scanf("%d %d", &cmd, &value);
		if (cmd==-1)
		{
			addToDLL(value);
		}
		if (cmd==-2 && value==-2)
		{
			pop();
		}
		if (cmd==-999&&value==-999)
		{
			showDLL();
			break;
		}
	}
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node*next;
	struct node*pre;
};
struct node*head = 0;
void addToDLL(int _data) {
	struct node*new = (struct node*)malloc(sizeof(struct node));
	new->data = _data;
	new->next = new->pre = 0;
	struct node*temp = head;
	if (head == 0)
	{
		head = new;
		return;
	}
	while (temp->next != 0)
	{
		temp = temp->next;
	}
	temp->next = new;
	new->pre = temp;
}
int stack_pop() {
	struct node*temp = head;
	if (head == 0)
	{
		return;
	}
	if (head->next == 0)
	{
		head = head->next;
		free(temp);
		return;
	}
	while (temp->next != 0)
	{
		temp = temp->next;
	}
	temp->pre->next = 0;
	free(temp);
	return;
}
int pop() {
	struct node*temp = head;
	if (head == 0)
	{
		return;
	}
	if (head->next == 0)
	{
		head = head->next;
		free(temp);
		return;
	}
	head = head->next;
	free(temp);
	return;
}
void showDLL() {
	struct node*temp = head;
	if (head == 0)
	{
		printf("Nothing");
		return;
	}
	while (temp != 0)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}
int main() {
	int cmd;
	int value;
	while (1)
	{
		scanf("%d %d", &cmd, &value);
		if (cmd == -1)
		{
			addToDLL(value);
		}
		if (cmd == -2 && value == -2)
		{
			stack_pop();
		}
		if (cmd == -3)
		{
			addToDLL(value);
		}
		if (cmd == -4 && value == -4)
		{
			pop();
		}
		if (cmd == -999 && value == -999)
		{
			showDLL();
			break;
		}
	}
	return 0;
}
#endif