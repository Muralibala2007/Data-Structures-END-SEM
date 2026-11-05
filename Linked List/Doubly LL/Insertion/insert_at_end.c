#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;
void create()
{
    int choice = 1;
    struct Node *temp = head;
    // OR struct Node *temp = NULL;
    while (choice)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data : ");
        scanf("%d", &newNode->data);

        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = temp->next; // OR temp = newNode;
        }
        printf("Do u want to continue? ");
        scanf("%d", &choice);
    }
}

void insert_at_end(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next=newNode;
    newNode->prev= temp;
}

void display()
{
    if(head == NULL)
    {
        printf("DLL is empty!!\n");
        return;
    }

    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    create();
    
    printf("\nOriginal doubly LL\n");
    display();
 
    insert_at_end(40);

    printf("\n After insertion at end: \n");
    display();
}