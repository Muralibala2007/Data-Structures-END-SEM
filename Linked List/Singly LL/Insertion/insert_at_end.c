#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* head = NULL;

void insert_at_end(int x)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if(head==NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void display()
{   
    if(head == NULL)
    {
        printf("LL is empty");
    }

    struct Node *temp = head;
    while(temp!=NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insert_at_end(10);
    display();
}