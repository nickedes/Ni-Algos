/*
Time complexity - O(N)
Space complexity - O(1)
 */
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node* newnode(int val)
{
    node *temp = new node;
    temp->data = val;
    temp->next = NULL;
    return temp;
}

node* sum_lists(node *head, node *start)
{
    node *list = NULL;
    if(head == NULL && start == NULL)
        return list;
    else
    {
        int carry = 0;
        node *temp = head;
        node *ptr = start;
        node *add = NULL, *last = NULL;
        while(temp!=NULL && ptr!=NULL)
        {
            // sum of nodes
            if(temp->data + ptr->data + carry > 9)
            {
                add = newnode(temp->data + ptr->data + carry - 10);
                carry = 1;
            }
            else
            {
                add = newnode(temp->data + ptr->data + carry);
                carry = 0;
            }

            // add node to a linked list
            if(list == NULL)
            {
                list = add;
                // track of last added node
                last = list;
            }
            else
            {
                last->next = add;
                last = add;
            }

            temp = temp->next;
            ptr = ptr->next;
        }

        // first list ends
        if(!temp && ptr)
        {
            last->next = ptr;
            while(ptr->next!=NULL)
            {
                if(ptr->data + carry > 9)
                {
                    ptr->data = ptr->data + carry - 10;
                    carry = 1;
                }
                else
                {
                    ptr->data = ptr->data + carry;
                    carry = 0;
                }
                ptr = ptr->next;
            }

            // for the last node
            if(ptr != NULL)
            {
                if(ptr->data + carry > 9)
                {
                    ptr->data = ptr->data + carry - 10;
                    carry = 1; //last node is 1
                    ptr->next = newnode(carry);
                }
                else
                {
                    ptr->data = ptr->data + carry;
                    carry = 0;
                }
            }
        }

        else if(temp && !ptr)
        {
            last->next = temp;
            while(temp->next!=NULL)
            {
                if(temp->data + carry > 9)
                {
                    temp->data = temp->data + carry - 10;
                    carry = 1;
                }
                else
                {
                    temp->data = temp->data + carry;
                    carry = 0;
                }
                temp = temp->next;
            }

            // for the last node
            if(temp != NULL)
            {
                if(temp->data + carry > 9)
                {
                    temp->data = temp->data + carry - 10;
                    carry = 1; //last node is 1
                    temp->next = newnode(carry);
                }
                else
                {
                    temp->data = temp->data + carry;
                    carry = 0;
                }
            }
        }

        else
        {
            if(carry)
                last->next = newnode(carry);
        }
    }
    return list;
}

// prints linked list in reverse order
void printREV(node *head)
{
    if(head)
    {
        printREV(head->next);
        cout << head->data << " ";
    }
}

int main()
{
    node *head = NULL, *start = NULL;
    head = newnode(7);
    head->next = newnode(1);
    head->next->next = newnode(9);
    head->next->next->next = newnode(9);
    head->next->next->next->next = newnode(9);
    start = newnode(5);
    start->next = newnode(9);
    // start->next->next = newnode(5);
    // start->next->next->next = newnode(12);
    // start->next->next->next->next = newnode(9);
    node *added = sum_lists(head, start);
    printREV(added);
    return 0;
}