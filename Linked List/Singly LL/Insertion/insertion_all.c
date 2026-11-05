#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert_at_beg(int x)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next = head;
    head=newNode;
}

void insert_at_end(int x)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data=x;
    newNode->next=NULL;

    if(head==NULL)
    {
        head=newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

void insert_at_pos(int x, int pos)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;

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

    struct Node *temp = head;
    int i=1;
    while(i<(pos-1) && temp!=NULL)
    {
        temp=temp->next;
        i++;
    }

    if(temp==NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next=temp->next;
    temp->next=newNode;
}

void display()
{
    if(head==NULL)
    {
        printf("LL is empty!!");
        return;
    }

    struct Node* temp= head;
    while(temp!=NULL)
    {
        printf("%d \n",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    insert_at_beg(10);
    insert_at_pos(20,2);
    insert_at_end(30);
    display();
}