/*
Problem : https://www.hackerrank.com/challenges/tree-inorder-traversal

The tree node has data, left child and right child 
struct node
{
    int data;
    node* left;
    node* right;
};

*/
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