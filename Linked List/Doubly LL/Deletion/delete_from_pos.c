
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
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

        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = temp->next;
        }

        printf("Do u want to continue? ");
        scanf("%d", &choice);
    }
}

void delete_from_pos(int pos)
{
    if (head == NULL)
    {
        printf("DLL is empty\n");
        return;
    }
    if(pos<1)
    {
        printf("Invalid Position");
    }
    
    if(pos==1)
    {   
        struct Node *temp = head;
        head=head->next;

        if(head!=NULL)
        {
            head->prev=NULL;
        }
        free(temp);
        return;
    }

    struct Node *temp = head;
    int i=1;
    // temp != NULL checks that we haven't reached the end of the list
    //In simple words: It ensures that temp exists before moving to the next node.
    while(i<pos && temp!=NULL)
    {
        temp=temp->next;
        i++;
    }
    if(temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }
//Because if we delete the last node, temp->next is NULL.
    if(temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    temp->prev->next=temp->next;
    free(temp);
}

void display()
{
    if (head == NULL)
    {
        printf("DLL is empty!!\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    create();

    printf("\nOriginal doubly LL:\n");
    display();

    delete_from_pos(3);

    printf("\nAfter deletion from position:\n");
    display();

    return 0;
}

/*

Operation	        Loop condition	Where should temp stop?
Insert at position	 i < pos-1	       Previous node
Delete at position 	   i < pos	       Node to delete

*/