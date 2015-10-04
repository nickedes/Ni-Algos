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
int insert(node *root, int key)
{
	node *temp = newNode(key);
	if(root->left == NULL)
	{
		root->left = temp;
		return 1;
	}
	else if(root->right == NULL)
	{
		root->right = temp;
		return 1;
	}
	else
	{
		// complete tree insertion way!!!!
		// use queue!
	}
}

// heapify - reach appropriate position in tree.
// void heapify(node *root);

void inorder(node *root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main()
{
	node *root = NULL;
	int ch;
	while(1)
	{
		cout << endl << "1. Insert" << endl << "2. Display" << endl << "3. exit" << endl << "Enter ur choice:";
		cin >> ch;
		switch(ch)
		{
			case 1: //insert
				int key;
				cout << "enter data:";
				cin >> key;
				if(root == NULL)
				{
					root = newNode(key);
				}
				else
					insert(root, key);
				break;
			case 2:
				//display
				inorder(root);
				break;
			case 3:
				//exit
				return 0;
				break;
			default:
				break;
		}
	}
	return 0;
}