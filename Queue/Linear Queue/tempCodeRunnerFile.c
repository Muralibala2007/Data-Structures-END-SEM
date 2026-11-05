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
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    getFront();
    getRear();

    dequeue();

    display();

    return 0;
}
