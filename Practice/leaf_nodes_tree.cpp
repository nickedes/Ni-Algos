// count no. of leaf nodes in Binary tree.
#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

node* insert(struct node* head, int value)
{
	if (head == NULL)
	{
		head->data = value;
		head->left = NULL;
		head->right = NULL;
	}
	else
	{
		// insert in appropriate subtree.
	}
	return head;
}

int main()
{
	node *head = NULL;

	return 0;
}