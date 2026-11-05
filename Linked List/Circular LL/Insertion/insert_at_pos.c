#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void create()
{
    int choice = 1;
    struct Node *temp = NULL;
    while (choice)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;
        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
        temp->next = head;

        printf("Do u want to continue? ");
        scanf("%d", &choice);
    }
}

void insert_at_pos(int x, int pos)
{
    if (pos < 1)
    {
        printf("Invalid position");
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;

    if (pos == 1)
    {
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        struct Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newNode->next = head;
        head = newNode;
        temp->next = head;

        return;
    }

    if (head == NULL)
    {
        printf("Invalid Position");
        free(newNode);
        return;
    }

    struct Node *temp = head;
    int i = 1;
    // temp->next != head checks whether we haven't reached the last node.
    // Because in CLL, the last node points back to head. We must not continue traversing beyond the last node.
    while (i < (pos - 1) && temp->next != head)
    {
        temp = temp->next;
        i++;
    }
    //This checks whether we successfully reached the node just before the required position. Insert 40 at position 10
    if (i != pos - 1)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void display()
{
    if (head == NULL)
    {
        printf("CLL is empty");
        return;
    }

    struct Node *temp = head;

    while (temp->next != head)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d -> HEAD", temp->data);
}

int main()
{
    create();

    printf("\nCLL before insert at position\n");
    display();

    insert_at_pos(30, 3);

    printf("\nCLL after insert at position\n");
    display();
}