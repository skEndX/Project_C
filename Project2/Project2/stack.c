//stack�� ����� 5�� 5��, queue�� 4��
//stack LIFO, queue FIFO
//stack (top), queue (front rear)

#if 0
#include<stdio.h>

#define SZ 5
int stack[SZ];
int top = -1;

int pop() {
	/*if (top==-1)
	{
		printf("STACK EMPTY\n");
		return -999;
	}
	top = top - 1;
	return stack[top+1];*/	//�Ʒ� �ڵ尡 ���
	int result;
	if (top == -1)
	{
		printf("STACK EMPTY\n");
		return;
	}
	result = stack[top];
	top = top - 1;
	return result;
}

void push(int n) {
	if (top==SZ-1)
	{
		printf("STACK FULL\n");
		return;
	}
	top = top + 1;
	stack[top] = n;	//�� �ڵ�� overflow�� ó������.
	return;			//�׷��� if���� ����� ��.
}

int main() {
	int num;
	int data;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &data);
		push(data);
	}
	if (num>5)
	{
		for (int i = 0; i < 5; i++)
		{
			printf("%d ", pop());
		}
		return;
	}
	for (int i = 0; i < num; i++)
	{
		printf("%d ", pop());
	}
	return 0;
}
#endif

#if 0
#include<stdio.h>
//enqueue 0 1 2 3 4
//denqueue 0 1 2 3 4

#define SZ 5

int que[SZ];
int front = 0;
int rear = 0;

void enque(int n) {
	//queue full check
	if (rear+1==front)	//����ó��
	{
		printf("QUEUE FULL");
		return;
	}
	que[rear] = n;
	rear = (rear + 1) % SZ;	//�ٽ� �Ųٷ� ���ư��� ���� ó���ϱ� ���ؼ�
}

int deque() {
	int result = 0;
	//empty queue
	if (front==rear)
	{
		printf("QUEUE EMPTY");
		return -999;
	}
	result = que[front];
	front = (front + 1) % SZ;
	return result;
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
	if (num>4)
	{
		for (int i = 0; i < 4; i++)
		{
			printf("%d ", deque());
		}
		return;
	}
	for (int i = 0; i < num; i++)
	{
		printf("%d ", deque());
	}
	return 0;
}
#endif

#include<stdio.h>
#define size 5
int qeue[size];
int front = 0, rear = 0;

int enque(int _data) {
	if ((rear+1)%size==front)
	{
		return;
	}
	qeue[rear] = _data;
	rear = (rear + 1) % size;
	return;
}
int deque() {
	int result = 0;
	if (rear==front)
	{
		return;
	}
	result = qeue[front];
	front = (front + 1) % size;
	return result;
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
	if (num<5)
	{
		for (int i = 0; i < num; i++)
		{
			printf("%d ", deque());
		}
	}
	if (num >= 5)
	{
		for (int i = 0; i < 4; i++)
		{
			printf("%d ", deque());
		}
	}
}