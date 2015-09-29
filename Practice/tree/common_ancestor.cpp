/*
Design an algorithm and write code to find the first common ancestor of two nodes
in a binary tree. Avoid storing additional nodes in a data structure. 
NOTE: This is not necessarily a binary search tree.
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

node* newnode(int key)
{
    node *temp = new node;
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

node *findLCA(node *root, int n1, int n2)
{
	// finding LCA
	// Assuming n1 and n2 exist in tree.
}

int main()
{
	return 0;
}