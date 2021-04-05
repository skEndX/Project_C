#include<stdio.h>
int front = 0;
int rear = 0;
int queue[10];

void enqueue(int v) {
	if ((rear+1)%10==front)
	{
		return;
	}
	queue[rear] = v;
	rear = (rear + 1) % 10;
}
int dequeue() {
	if (front==rear)
	{
		return -999;
	}
	int temp = front;
	front = (front + 1) % 10;
	return queue[temp];
}

