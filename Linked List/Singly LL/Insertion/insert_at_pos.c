#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
 
void insert_at_pos(int x, int pos)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = x;

    if(pos < 1)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    if(pos==1)
    {
        newNode->next = head;
        head=newNode;
        return;
    }

    struct Node *temp=head;

    int i=1;
    //If the requested position is beyond the list length, temp can become NULL.
    while(i<(pos-1) && temp!=NULL)
    {
        temp=temp->next;
        i++;
    }

    // to prevent error when trying to insert at position 5 when the list only has 1 node
     if(temp == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next=newNode;
}

void display()
{
    if(head == NULL)
    {
        printf("LL is empty");
        return;
    }

    struct Node* temp = head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp= temp->next;
    }
    printf("\n");
}
int main()
{
    insert_at_pos(10,1);
    display();
}