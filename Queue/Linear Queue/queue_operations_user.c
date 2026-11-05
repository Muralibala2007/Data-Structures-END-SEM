#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int is_empty()
{
    if(front == -1 && rear == -1)
    {
        return 1;
    }
    return 0;
}

int is_full()
{
    if(rear == MAX - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(int data)
{
    if(is_full())
    {
        printf("\nQueue is Full!!! Overflow\n");
        return;
    }

    if(is_empty())
    {
        front = rear = 0;
        queue[rear] = data;
    }
    else
    {
        rear++;
        queue[rear] = data;
    }
}

void dequeue()
{
    if(is_empty())
    {
        printf("\nQueue is Empty!!! Underflow\n");
        return;
    }

    if(front == rear)
    {
        printf("\nDeleted Element: %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("\nDeleted Element: %d\n", queue[front]);
        front++;
    }
}

void getFront()
{
    if(is_empty())
    {
        printf("\nQueue is Empty!!! Underflow\n");
        return;
    }

    printf("\nFront element: %d\n", queue[front]);
}

void getRear()
{
    if(is_empty())
    {
        printf("\nQueue is Empty!!! Underflow\n");
        return;
    }
    printf("\nRear element: %d\n", queue[rear]);
}

void display()
{
    if(is_empty())
    {
        printf("\nQueue is Empty!!! Underflow\n");
        return;
    }

    printf("\nQueue Elements: ");

    for(int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice, data;

    while(1)
    {
        printf("\n\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Get Front");
        printf("\n4. Get Rear");
        printf("\n5. Check Queue Full");
        printf("\n6. Check Queue Empty");
        printf("\n7. Display");
        printf("\n8. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                getFront();
                break;

            case 4:
                getRear();
                break;

            case 5:
                if(is_full())
                    printf("Queue is Full\n");
                else
                    printf("Queue is Not Full\n");
                break;

            case 6:
                if(is_empty())
                    printf("Queue is Empty\n");
                else
                    printf("Queue is Not Empty\n");
                break;

            case 7:
                display();
                break;

            case 8:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
