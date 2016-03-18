/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/

node * newNode(int data)
{
	node *ptr = new node;
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	return(ptr);
}

node * insert(node * root, int value)
{
	if(!root)
		return newNode(value);
	if(root->data > value)
	{
		if(root->left)
			root->left = insert(root->left, value);
		else
			root->left = newNode(value);
	}
	else
	{
		if(root->right)
			root->right = insert(root->right, value);
		else
			root->right = newNode(value);
	}
	return root;
}
