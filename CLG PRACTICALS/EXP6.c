#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int x)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = x;

    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node *temp = head;
    while(temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void delete(int x)
{
    if(head == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;
    if(head->data == x)
    {
        while(temp->next != head)
            temp = temp->next;

        if(head->next == head)
            head = NULL;
        else
        {
            head = head->next;
            temp->next = head;
        }
        return;
    }

    temp = head;
    while(temp->next != head && temp->next->data != x)
        temp = temp->next;

    if(temp->next->data == x)
    {
        struct Node *del = temp->next;
        temp->next = del->next;
        free(del);
    }
}

void display()
{
    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    struct Node *temp = head;
    printf("Linked List: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != head);
    printf("\n");
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    display();
    delete(40);
    delete(10);
    display();
}