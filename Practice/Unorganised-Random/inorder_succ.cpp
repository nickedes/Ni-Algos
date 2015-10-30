/*
Inorder Successor in Binary Search Tree
In Binary Search Tree, Inorder Successor of an input node can also
be defined as the node with the smallest key greater than the key of input node.
 */
#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

node* leftest(node* ptr)
{
	while(ptr->left!=NULL)
		ptr = ptr->left;
	return ptr;
}

node* inorderSucc(node* root, node* temp)
{
	node* succ = NULL;
	if(temp->right != NULL)
	{
		return leftest(temp->right);
	}
	else
	{
		while(root != NULL)
		{
			if(temp->data < root->data)
			{
				succ = root;
				root = root->left;
			}
			else if(temp->data > root->data)
				root = root->right;
			else
				break;
		}
	}
	return succ;
}

node* newNode(int key)
{
	node* ptr = new node;
	ptr->data = key;
	ptr->left = ptr->right = NULL;
	return ptr;
}

int main()
{
	struct node *root = NULL, *temp, *succ;
	root = newNode(20);
	root->left = newNode(10);
	root->right = newNode(30);
	root->left->left = newNode(5);
	root->right->right = newNode(40);
	temp = root->right;
	succ = inorderSucc(root, temp);
	if(succ)
		cout << succ->data;
	else
		cout << "NULL";
	return 0;
}