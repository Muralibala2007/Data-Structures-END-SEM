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

void delete_from_beg()
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

    struct Node *current = head;

    while(current->next!=head)
    {
        current=current->next;
    }
    head=head->next;
    current->next=head;

    free(temp);

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
    
    printf("\nCLL before delete from beggining\n");
    display();

    delete_from_beg();

    printf("\nCLL after delete from beggining\n");
    display();
}