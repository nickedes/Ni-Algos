/*
Problem : https://www.hackerrank.com/challenges/tree-inorder-traversal

Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void Inorder(node *root) {
	if(root->left)
		Inorder(root->left);
	cout << root->data << " ";
	if(root->right)
		Inorder(root->right);	
	return;
}