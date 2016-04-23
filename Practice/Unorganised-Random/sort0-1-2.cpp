#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

void push (struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node;
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

void printList(struct node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void sortList(struct node *head)
{
   //Add code here
   struct node *first = head;
   int c0 = 0, c1 = 0, c2 = 0;
   while(first!=NULL)
   {
        if(first->data == 0)
            c0 ++;
        else if(first->data == 1)
            c1 ++;
        else
            c2 ++;
        first = first->next;
   }
   struct node *start = head;
//   while(start!=NULL)
//   {
        while(c0)
        {
            start->data = 0;
            start = start->next;
            c0 --;
        }
        while(c1)
        {
            start->data = 1;
            start = start->next;
            c1 --;
        }
        while(c2)
        {
            start->data = 2;
            start = start->next;
            c2 --;
        }
//   }
}

int main()
{
    struct node *head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);

    cout << "Input : ";
    printList(head);

    sortList(head);

    cout << "Output : ";
    printList(head);
    return 0;
}