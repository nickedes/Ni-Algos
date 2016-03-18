#include <iostream>
#include <queue>
using namespace std;

struct node
{
   int data;
   node * left;
   node * right;
};

node * newNode(int data)
{
	node *ptr = new node;
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	return(ptr);
}

int main()
{
	int N;
	cin >> N;
	queue<node *> q;
	node *root = newNode(1);
	q.push(root);
	while(N-- && !q.empty())
	{
		int a, b;
		node *head = q.front();
		node *l_child = NULL, *r_child = NULL;
		cin >> a >> b;
		if(a!=-1)
			l_child = newNode(a);
		if(b!=-1)
			r_child = newNode(b);
		head->left = l_child;
		head->right = r_child;
		if(l_child)
			q.push(l_child);
		if(r_child)
			q.push(r_child);
		q.pop();
	}
	
	return 0;
}