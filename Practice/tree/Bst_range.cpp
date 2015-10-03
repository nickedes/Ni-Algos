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
	if(root == NULL)
		return newNode(key);
	else if(root->data > key)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);
	return root;
}

void inorderTraversal(node *root)
{
	if(root->left)
		inorderTraversal(root->left);
	cout<<root->data<<" ";
	if(root->right)
		inorderTraversal(root->right);
}

node* modify_range(node* root, int min, int max)
{

	root->left = modify_range(root->left, min, max);
	root->right = modify_range(root->right, min, max);

	if(root->data > max)
	{
		node *ptr = root->left;
		root = NULL;
		return ptr;
	}
	else if(root->data < min)
	{
		node *ptr = root->right;
		// delete root;
		root = NULL;
		return ptr;
	}
	return root;
}

int main()
{
	int min, max;
	node *root = NULL;
	root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);

    cout << "Inorder traversal of the given tree is: ";
    inorderTraversal(root);

    // cout << "Enter the range [min, max] : ";
    // cin >> min >> max;
    min = -10; max = 13;
    root = modify_range(root, min, max);

    cout << endl <<"Inorder traversal of the modified tree is: ";
    inorderTraversal(root);
    return 0;
}