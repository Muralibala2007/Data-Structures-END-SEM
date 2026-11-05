#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void insert_at_begg(int x)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

void reverse()
{
    struct Node *prevNode = NULL;
    struct Node *currentNode = head;
    struct Node *nextNode = head;
    while(nextNode!=NULL)
    {
        nextNode=nextNode->next;
        currentNode->next = prevNode;
        prevNode=currentNode;
        currentNode=nextNode;
    }
    head = prevNode;
}

void display()
{
    if(head == NULL)
    {
        printf("Linked list is empty!!\n");
        return;
    }

    struct Node *temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    insert_at_begg(30);
    insert_at_begg(20);
    insert_at_begg(10);

    printf("Original Linked List:\n");
    display();

    reverse();

    printf("Reversed Linked List:\n");
    display();

}