// count no. of leaf nodes in Binary tree.
#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

node* insert(int value)
{
	/*
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
	*/
	struct node *temp = new node;
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int main()
{
	//node *head = NULL;
	/*create a tree*/ 
	struct node *root = insert(1);
	root->left        = insert(2);
	root->right       = insert(3);
	root->left->left  = insert(4);
	root->left->right = insert(5);

	cout << root->left->data;
	return 0;
}