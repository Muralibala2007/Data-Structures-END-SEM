#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert_at_begg(int x)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

void delete_from_pos(int pos)
{
    if(head == NULL)
    {
        printf("LL is empty");
        return;
    }

    if(pos < 1)
    {
        printf("Invalid position");
        return;
    }

    if(pos==1)
    {
        struct Node *temp = head;
        head = head->next;

        free(temp);
    }

    struct Node *temp = head;
    struct Node *nextNode;
    int i=1;

    while(i < (pos-1) && temp != NULL)
    {
        temp=temp->next;
        i++;
    }

     if(temp == NULL || temp->next == NULL)
    {
        printf("Invalid position");
        return;
    }

    nextNode = temp->next;
    temp->next=nextNode->next;

    free(nextNode);

}

void display()
{
    if(head==NULL)
    {
        printf("Linked list is empty!!\n");
        return;
    }

    struct Node *temp = head;

    while(temp!=NULL){
        printf("%d \n",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insert_at_begg(30);
    insert_at_begg(20);
    insert_at_begg(10);
    delete_from_pos(2);
    display();
}

/*

1. temp == NULL
This checks whether temp itself is pointing to a valid node.
You try:
delete_from_pos(5);

2. temp->next == NULL
This checks whether there is a node after temp to delete.

You try:
delete_from_pos(4);

Here:
- temp != NULL → TRUE
- temp->next == NULL → TRUE
There is no next node to delete, so position 4 is invalid.

*/