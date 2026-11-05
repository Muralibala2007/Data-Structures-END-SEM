#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert_at_beg(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

void delete_from_beg()
{
    if (head == NULL)
    {
        printf("LL is empty");
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void delete_from_end()
{
    if (head == NULL)
    {
        printf("LL is empty");
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    struct Node *prevNode;

    while (temp->next != NULL)
    {
        prevNode = temp;
        temp = temp->next;
    }
    prevNode->next = NULL;
    free(temp);
}

void delete_from_pos(int pos)
{
    if (head == NULL)
    {
        printf("LL is empty");
    }
    if (pos < 1)
    {
        printf("Invalid position");
        return;
    }
    if (pos == 1)
    {
        delete_from_beg();
    }
    struct Node *temp = head;
    struct Node *nextNode;
    int i = 1;
    while (i < (pos - 1))
    {
        temp = temp->next;
        i++;
    }
    if (head == NULL || temp->next == NULL)
    {
        printf("Invalid position");
        return;
    }
    nextNode = temp->next;
    temp->next = nextNode->next;

    free(nextNode);
}

void display()
{
    if (head == NULL)
    {
        printf("LL is empty");
    }

    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d \n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insert_at_beg(40);
    insert_at_beg(30);
    insert_at_beg(20);
    insert_at_beg(10);
    delete_from_beg();
    insert_at_beg(10);
    delete_from_end();
    delete_from_pos(3);
    display();
}