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

int isBSTUtil(node* node, int min, int max);

/* Returns true if the given tree is a binary search tree 
 (efficient version). */
int isBST(struct node* root)
{ 
  return(isBSTUtil(root, INT_MIN, INT_MAX));
}

int isBSTUtil(node *root, int min, int max)
{
	//code for bst check
}

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