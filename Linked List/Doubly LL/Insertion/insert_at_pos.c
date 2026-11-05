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

void insert_at_pos(int x, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;

    if (pos < 1)
    {
        printf("Invalid position");
        return;
    }

    if (pos == 1)
    {
        newNode->prev = NULL;
        newNode->next = head;
//This condition is needed to handle both an empty DLL and a non-empty DLL when inserting at position 1.
        if (head != NULL)
        {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    struct Node *temp = head;
    int i = 1;
    // If the requested position is beyond the list length, temp can become NULL.
    while (i < (pos - 1) && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    newNode->prev = temp;
    newNode->next = temp->next;
    //This fails when inserting at the end because temp->next is NULL.
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void display()
{
    if (head == NULL)
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

    insert_at_pos(30, 3);

    printf("\n After insertion at position: \n");
    display();
}