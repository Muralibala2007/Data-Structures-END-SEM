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

void delete_from_begg()
{
    if(head == NULL)
    {
        printf("LL is empty");
        return;
    }
    struct Node *temp = head;

    head = head->next;
    free(temp);
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
        printf("%d \n",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insert_at_begg(30);
    insert_at_begg(20);
    insert_at_begg(10);
    delete_from_begg();
    display();
}