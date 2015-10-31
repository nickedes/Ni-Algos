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

node* k_last(node *head, int k)
{
	// returns kth element to last
	node *temp = head;

	while(temp->next!=NULL && k > 1)
	{
		temp = temp->next;
		k--;
	}
	if(k>1)
	{
		// k larger than the list 
		return NULL;
	}
	node *ptr = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
		ptr = ptr->next;
	}
	return ptr;
} 

int main()
{
	int k;
	node *head = NULL;
	head = newnode(2);
	head->next = newnode(3);
	head->next->next = newnode(4);	
	head->next->next->next = newnode(12);
	head->next->next->next->next = newnode(9);
	
	cout << "Enter K :";
	cin >> k;
	
	node *ptr = k_last(head,k);
	if(ptr)
		cout << ptr->data;
	else
		cout << "K larger than list";
	return 0;
}