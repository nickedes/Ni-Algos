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

int main()
{
	node *root = newNode(50);
	root->left = newNode(7);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(5);
	root->right->left = newNode(1);
	root->right->right = newNode(30);

}