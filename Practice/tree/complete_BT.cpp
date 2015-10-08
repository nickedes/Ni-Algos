// implement insertion in complete binary tree.
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
