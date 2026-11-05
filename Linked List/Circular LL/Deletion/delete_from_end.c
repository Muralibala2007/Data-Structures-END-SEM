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

void delete_from_end()
{
    if(head == NULL)
    {
        printf("CLL is empty\n");
        return;
    }

    struct Node *temp = head;

    if(head->next == head)
    {
        head = NULL;
        free(temp);
        return;
    }

    while(temp->next->next!=head)
    {
        temp=temp->next;
    }

    struct Node *nextNode = temp->next;

    temp->next = head;
    free(nextNode);

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
    
    printf("\nCLL before delete from end\n");
    display();

    delete_from_end();

    printf("\nCLL after delete from end\n");
    display();
}