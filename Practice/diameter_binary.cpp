// Diameter of a binary tree.
#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

node* getNode(int value)
{
	struct node *temp = new node;
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int main()
{
	struct node *root = getNode(1);
	root->left        = getNode(2);
	root->right       = getNode(3);
	root->left->left  = getNode(4);
	root->left->right = getNode(5);

}