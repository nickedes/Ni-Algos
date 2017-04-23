/*
 * For Directed graph
 */

#include <stdio.h>
#define num_node 100

struct node
{
	int val;
	int weight;
	struct node *next;
};

struct node *graph[num_node+1];
int visited[num_node+1];

struct node * createNode(int j)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	if(newNode)
	{
		newNode->val = j;
		newNode->next = NULL;
	}
	else
	{
		printf("\n Node can't be allocated");
	}
	return newNode;
}

void addEdge(int i, int j)
{
	struct node *currentNode = graph[i];
	if(!currentNode)
	{
		graph[i] = createNode(j);
	}
	else
	{
		while(currentNode->next)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = createNode(j);
	}
}
int onStack[num_node + 1];
void dfs(struct node * current)
{
    if(!current) return;
    onStack[current->val] = 1;
    visited[current->val] = 1;
    struct node *temp = current->next;
    while(temp){
        if(onStack[temp->val] == 1){
           printf("\n Cycle detected at node %d", temp->val);
        }
        else if(visited[temp->val] != 1){
             dfs(graph[temp->val]);
        }
        temp = temp->next;
    }
    onStack[current->val] = 0;
}

int main()
{

	int i;
	for (i = 0; i < num_node; ++i)
	{
		graph[i] = createNode(i);
	}

	addEdge(1,2);
    addEdge(1,5);
    addEdge(2,3);
    addEdge(2,4);
    addEdge(4,1);
    addEdge(3,4);
    addEdge(4,6);
    addEdge(5,4);
    addEdge(5,6);
    addEdge(6,5);

	for(i = 0; i < num_node; ++i)
	{
		visited[i] = 0;
	}
	dfs(graph[5]);
	printf("lol\n");
	return 0;
}