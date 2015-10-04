/*
k largest(or smallest) elements in an array.
 */
#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *left;
	node *right;
};

// add to heap tree
void insert(node *root);

// heapify - reach appropriate position in tree.
void heapify(node *root);

int main()
{
	node *root = NULL;
	return 0;
}