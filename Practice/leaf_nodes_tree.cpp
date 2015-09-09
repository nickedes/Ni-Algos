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

int count_leaf(struct node *temp)
{
	if(temp == NULL)
		return 0;

	// This node is a leaf node!
	else if(temp->left == NULL && temp->right == NULL)
		return 1;
	else
	{
		int left_leaf = 0,right_leaf = 0;
		left_leaf = count_leaf(temp->left);
		right_leaf = count_leaf(temp->right);
		return right_leaf+left_leaf;
	}
}

int depth(struct node *temp)
{
	if(temp == NULL)
		return 0;
	else
		return 1 + max(depth(temp->left),depth(temp->right));
}
int main()
{
	//node *head = NULL;
	/*create a tree*/ 
	struct node *root ;
	root = insert(1);
	root->left = insert(2);
	root->right = insert(3);
	root->left->left = insert(4);
	root->left->right = insert(5);

	cout << root->left->data;

	cout << count_leaf(root);
	return 0;
}