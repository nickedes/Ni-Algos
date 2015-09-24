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

node* inorderSucc(node* temp)
{
	return temp;
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
	struct node* root = NULL;
	root = newNode(20);
	root->left = newNode(10);
	root->right = newNode(30);
	root->left->left = newNode(5);
	root->right->right = newNode(40);
	temp = root->left->left;
	succ = inorderSucc(temp);
	cout << succ->data;
	return 0;
}