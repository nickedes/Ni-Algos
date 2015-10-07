/*
Implement a function to check if a binary tree is a binary search tree.
 */
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

int main()
{
	node *root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(5);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	return 0;
}