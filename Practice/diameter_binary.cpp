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

int height(struct node *temp)
{
	if(temp == NULL)
		return 0;
	else
		return 1 + max(height(temp->left),height(temp->right));
}

int diameter(struct node* temp)
{
	if(temp == NULL)
		return 0;

	/* get the diameter of left and right sub-trees */
	int left_dia = diameter(temp->left);
	int rig_dia = diameter(temp->right);

	/* get the height of left and right sub-trees */
	int left_ht = height(temp->left);
	int right_ht = height(temp->right);

	return max(left_ht+right_ht+1,max(left_dia,rig_dia));
}

int main()
{
	struct node *root = getNode(1);
	root->left        = getNode(2);
	root->right       = getNode(3);
	root->left->left  = getNode(4);
	root->left->right = getNode(5);

	cout << "Diameter : " << diameter(root);	
}