/*
Time complexity - O(N^2)
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

int remove_dups(node *head)
{
	node *temp = head;
	node *ptr, *dup;
	while(temp!= NULL && temp->next!=NULL)
	{
		ptr = temp;
		while(ptr->next!=NULL)
		{
			if(temp->data == ptr->next->data)
			{
				dup = ptr->next;
				ptr->next = ptr->next->next;
				delete dup;
			}
			else
				ptr = ptr->next;
		}
		temp = temp->next;
	}
}

int main()
{
	node *head = NULL;
	head = newnode(2);
	head->next = newnode(2);
	head->next->next = newnode(2);	
	head->next->next->next = newnode(9);
	head->next->next->next->next = newnode(9);
	remove_dups(head);
	return 0;
}