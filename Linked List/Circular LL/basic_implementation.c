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
        struct Node *newNode  = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next=NULL;

        if(head==NULL)
        {
            head = temp=newNode;
        }
        else
        {
            temp->next=newNode;
            temp=temp->next; // or temp=newNode;
        }
        temp->next = head; // creates circular connection

        printf("DO u want to continue ? ");
        scanf("%d", &choice);
    }
}

void display()
{
    if(head==NULL)
    {
        printf("LL is empty");
        return;
    }
    struct Node *temp = head;

    while(temp->next!=head)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("%d -> HEAD\n", temp->data);
}
int main()
{
    create();
    display(); 
}