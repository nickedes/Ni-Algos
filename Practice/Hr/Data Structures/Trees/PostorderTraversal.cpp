/*
Problem : https://www.hackerrank.com/challenges/tree-postorder-traversal

Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void Postorder(node *root) {
	if(root->left)
		Postorder(root->left);
	if(root->right)
		Postorder(root->right);	
	cout << root->data << " ";
	return;
}