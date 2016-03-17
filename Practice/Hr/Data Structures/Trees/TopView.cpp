/*
Problem : https://www.hackerrank.com/challenges/tree-top-view

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void printLeft(node * root)
{
	if(root)
	{
		printLeft(root->left);
		cout << root->data << " ";
	}
	return;	
}

void printRight(node * root)
{
	if(root)
	{
		cout << root->data << " ";
		printRight(root->right);
	}
	return;
}

void top_view(node * root)
{
	if(root)
	{
		printLeft(root->left);
		cout << root->data << " ";
		printRight(root->right);
	}
	return;
}
