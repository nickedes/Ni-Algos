/*

Problem : https://www.hackerrank.com/challenges/tree-level-order-traversal

struct node
{
    int data;
    node* left;
    node* right;
}*/

int height(node * root)
{
	int h_left = 0, h_right = 0;
	if(root->left)
		h_left = 1 + height(root->left);
	if(root->right)
		h_right = 1 + height(root->right);
	if(!root->left && !root->right)
		return 1;
	if(h_left >= h_right)
		return h_left;
	else
		return h_right;
}

void printGivenLevel(node * root, int depth)
{
	if(root)
	{
		if(depth == 1)
			cout << root->data<< " ";
		else
		{
			printGivenLevel(root->left, depth-1);
			printGivenLevel(root->right, depth-1);
		}
	}
	return;
}

void LevelOrder(node * root)
{
	int h = height(root);
	for (int i = 1; i <= h; ++i)
		printGivenLevel(root, i);
	return;
}