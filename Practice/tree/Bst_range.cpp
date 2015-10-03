/*
Remove BST keys outside the given range
Given a Binary Search Tree (BST) and a range [min, max], remove all keys which
are outside the given range.
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
	node *ptr = new node;
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	return(ptr);
}

node* insert(node* root, int key)
{
	// bst node insertion
}

int main()
{

}