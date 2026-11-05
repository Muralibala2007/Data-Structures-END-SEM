
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
    struct Node *temp = NULL;

    while(choice)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->prev = NULL;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = temp->next;
        }

        printf("Do u want to continue? ");
        scanf("%d", &choice);
    }
}

void delete_from_beg()
{
    if(head == NULL)
    {
        printf("DLL is empty\n");
        return;
    }

    struct Node *temp = head;

    head = head->next;

    if(head != NULL)
    {
        head->prev = NULL;
    }

    free(temp);
}

void display()
{
    if(head == NULL)
    {
        printf("DLL is empty!!\n");
        return;
    }

    struct Node *temp = head;

    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    create();

    printf("\nOriginal doubly LL:\n");
    display();

    delete_from_beg();

    printf("\nAfter deletion from beginning:\n");
    display();

}
