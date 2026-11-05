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

void reverse()
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *nextNode;

    if (head == NULL || head->next == head)
    {
        return;
    }

    while (current->next != head)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    current->next = prev;
    head->next = current;
    head = current;
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

    printf("\nCLL before reverse\n");
    display();

    reverse();

    printf("\nCLL after reverse\n");
    display();
}