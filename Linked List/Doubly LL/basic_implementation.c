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

void display()
{
    struct Node *temp = head;
    while(temp!=NULL)
    {
        printf("%d->", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    create();
    display();
}