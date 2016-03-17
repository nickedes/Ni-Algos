/*
Problem : https://www.hackerrank.com/challenges/tree-preorder-traversal

Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void Preorder(node *root) {
	cout << root->data << " ";
	if(root->left)
		Preorder(root->left);
	if(root->right)
		Preorder(root->right);	
	return;
}