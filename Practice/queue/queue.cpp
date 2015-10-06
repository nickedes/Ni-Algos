#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
	int data;
	node *next;
};

struct queue
{
	node *front, *rear;
};

node* newNode(int key)
{
	node *ptr = new node;
	ptr->data = key;
	ptr->next = NULL;
	return ptr;
}

void enqueue(queue *q, int key)
{
	node *temp = newNode(key);
	if(q->front == NULL)
	{
		q->front = temp;
		q->rear = q->front;
		return;
	}
	q->rear->next = temp;
	q->rear = temp;
}

int dequeue(queue *q)
{
	node *ptr = q->rear;
	//underflow
	if(q->rear == NULL)
		return -1;
	else if(q->rear == q->front)
	{
		node *temp = q->rear;
		q->rear = q->front = NULL;
		return temp->data;
	}
	node *temp = q->front;
	q->front = q->front->next;
	int key = temp->data;
	delete temp;
	return key;
}


void printQ(queue *q)
{
	node *ptr = q->front;
	if(q->front == NULL)
	{
		cout << "Empty!";
		return;
	}
	cout << ptr->data << "->";
	while(ptr!=q->rear)
	{
		ptr = ptr->next;
		cout << ptr->data << "->";
	}
	cout << endl;
}

int main()
{
	queue *q = new queue;
	q->front = q->rear = NULL;
	enqueue(q, 2);
	printQ(q);
	enqueue(q, 4);
	printQ(q);
	dequeue(q);
	printQ(q);
	dequeue(q);
	printQ(q);
	return 0;
}