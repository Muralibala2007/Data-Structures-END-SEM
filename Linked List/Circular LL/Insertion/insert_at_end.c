#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node *head = NULL;

void create()
{
    int choice = 1;
    struct Node *temp=NULL;
    while(choice)
    {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d",&newNode->data);

        newNode->next = NULL;
        if(head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next=newNode;
            temp=temp->next;
        }
        temp->next=head;

        printf("Do u want to continue? ");
        scanf("%d", &choice);
    }
}

void insert_at_end(int x)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data = x;

    if(head == NULL)
    {
        head= newNode;
        newNode->next=head;
        return;
    }

    struct Node *temp=head;

    while(temp->next!=head)
    {
        temp=temp->next;
    }
    newNode->next=head;
    temp->next = newNode;
    
}

void display()
{
    if(head == NULL)
    {
        printf("CLL is empty");
        return;
    }

    struct Node* temp = head;

    while(temp->next!=head)
    {
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("%d -> HEAD", temp->data);
}

int main()
{
    create();
    
    printf("\nCLL before insert at end\n");
    display();

    insert_at_end(40);

    printf("\nCLL after insert at end\n");
    display();
}