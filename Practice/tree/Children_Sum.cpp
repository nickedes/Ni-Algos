/*
Convert an arbitrary Binary Tree to a tree that holds Children Sum Property.
You can only increment data values in any node (You cannot change structure of tree
and cannot decrement value of any node). 
 */
#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *left;
	node *right;
};

node* newNode(int data)
{
	node *ptr;
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	return(ptr);
}

void children_sum(node *root)
{
	if(root == NULL)
		return ;
	// cout << root -> data;
	if(root->left != NULL)
	{
		children_sum(root->left);
		root->data += root->left->data;
	}
	if(root->right != NULL)
	{
		children_sum(root->right);
		root->data += root->right->data;
	}
}

int main()
{
	node *root = newNode(50);
	root->left = newNode(7);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(5);
	root->right->left = newNode(1);
	root->right->right = newNode(30);
	children_sum(root);
	// cout << root->data;
	return 0;
}