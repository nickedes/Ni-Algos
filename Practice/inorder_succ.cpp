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

	return 0;
}