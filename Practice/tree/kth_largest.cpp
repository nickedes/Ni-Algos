/*
kth largest(or smallest) elements in an array.
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

node* newNode(int key)
{
	node *ptr = new node;
	ptr->data = key;
	ptr->left = ptr->right = NULL;
	return ptr;
}

// add to heap tree
void insert(node *root, int key)
{
	node *temp = newNode(key);
	if(root == NULL)
		root = temp;
	else
	{
		if(root->left == NULL)
		{
			root->left = temp;
		}
		else if(root->right == NULL)
		{
			root->right = temp;
		}
		else
		{
			insert(root->left, key);
			insert(root->right, key);
		}
	}
}

// heapify - reach appropriate position in tree.
// void heapify(node *root);

void inorder(node *root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	cout << root->data;
	inorder(root->right);
}

int main()
{
	node *root = NULL;
	int ch;
	while(1)
	{
		cout << "1. Insert" << "2. Display" << "3. exit";
		cin >> ch;
		switch(ch)
		{
			case 1: //insert
			break;
			case 2: //display
			break;
			case 3://exit
			return 0;
			break;
			default:
			break;
		}
	}
	return 0;
}