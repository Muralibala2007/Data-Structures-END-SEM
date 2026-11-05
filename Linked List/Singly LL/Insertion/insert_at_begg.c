#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

//Next is a pointer that stores the address of another struct node

struct Node *head = NULL;

void create()
{
    int choice = 1;
    struct Node *temp = NULL;

    while(choice)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if(head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }

        printf("Do u want to continue? ");
        scanf("%d", &choice);
    }
}

void insert_at_begg(int x)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = head;
    head = newNode;
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
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{   create();
    insert_at_begg(10);
    display();
}

//temp!=NULL -> To visit and print every node, including the last node.
//temp->next!=NULL -> To stop at the last node, because the last node's next is NULL.