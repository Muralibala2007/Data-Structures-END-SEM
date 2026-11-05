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

void delete_from_pos(int pos)
{
    if(head == NULL)
    {
        printf("CLL is empty\n");
        return;
    }
    if(pos<1)
    {
        printf("Invalid Pos");
    }

    struct Node *temp = head;

    if(pos==1)
    {
        if(head->next == head)
        {
            head=NULL;
            free(temp);
            return;
        }
        struct Node *current = head;

        while(current->next!=head)
        {
            current=current->next;
        }
        head = head->next;
        current->next=head;
        free(temp);
    }
    
    int i=1;
    while(i<(pos-1) && temp->next!=head)
    {
        temp=temp->next;
        i++;
    }
    if(temp->next == head)
    {
        printf("Invalid position\n");
        return;
    }
    
    struct Node *nextNode = temp->next;
    temp->next=nextNode->next;
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
    
    printf("\nCLL before delete from position\n");
    display();

    delete_from_pos(3);

    printf("\nCLL after delete from position\n");
    display();
}