/*
Time complexity - O(N)
Space complexity - O(1)
 */
#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

node* newnode(int val)
{
	node *temp = new node;
	temp->data = val;
	temp->next = NULL;
	return temp;
}

node* sum_lists(node *head, node *start)
{
	return NULL;
}

int main()
{
	node *head = NULL, *start = NULL;
	head = newnode(7);
	head->next = newnode(1);
	head->next->next = newnode(6);	
	// head->next->next->next = newnode(12);
	// head->next->next->next->next = newnode(9);
	start = newnode(5);
	start->next = newnode(9);
	start->next->next = newnode(2);	
	// start->next->next->next = newnode(12);
	// start->next->next->next->next = newnode(9);
	
	return 0;
}