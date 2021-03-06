#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

void new_node(struct node **head,int data)
{
    struct node *ptr,*temp;
    temp = *head;
    ptr = new node;
    ptr->data = data;
    ptr->next = NULL;
    if(*head == NULL)
    {
        *head = ptr;
    }
    else
    {
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = ptr;
    }
}

void loop(struct node *head,int b)
{
    struct node *temp = head;
    int c=0;

    while(head->next !=NULL)
    {
        if(c == (b-1))
            temp = head;
        head = head->next;
        c++;
    }
    head -> next = temp;
}

void display(struct node *head)
{
 int c=0;
  while(c<=10 && head!=NULL)
  {
      cout<<head->data<<"-->";
      head = head->next;
      c++;
  }
}


int loopdetect(struct node *head)
{
    struct node *slow,*fast,*temp;
    slow = head;
    fast = head;
    slow=slow->next;
    fast=(fast->next)->next;

    while(slow != fast && fast->next!=NULL && fast->next->next!=NULL)
    {
        slow = slow->next;
        fast = (fast->next)->next;
    }

    if(slow == fast)
        {
            slow = head;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            cout <<"\n"<<slow->data;
        }
    else
        return 0;
}


int main()
{
    struct node *head,*ptr;
    int ch,data,b=0;
    head = NULL;

    do
    {
        cout<<"Enter choice:";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cin>>data;
                new_node(&head,data);
                display(head);
                break;

            case 2:
                cin>>b;
                loop(head,b);
                display(head);
                break;
            case 3:
                // loop detection
                int loopexist=0;
                loopexist = loopdetect(head);
                if(loopexist == 0)
                    cout<<"no loop";
                else
                    cout << "Loop detected!";
        }
    }
    while(ch!=4);
    return 0;
}
