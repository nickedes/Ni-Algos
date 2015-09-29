/*
Design an algorithm and write code to find the first common ancestor of two nodes
in a binary tree. Avoid storing additional nodes in a data structure. 
NOTE: This is not necessarily a binary search tree.
 */

// Complexity - O(n)

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
	if (root == NULL)
		return NULL;
	if(root->data == n1 || root->data == n2)
		return root;

	node *left_lca = findLCA(root->left, n1, n2);
	node *right_lca = findLCA(root->right, n1, n2);

	if(left_lca != NULL && right_lca != NULL)
		return root;
	else
		return (left_lca==NULL)?right_lca:left_lca;
}

int main()
{
	node * root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->data;
	return 0;
}