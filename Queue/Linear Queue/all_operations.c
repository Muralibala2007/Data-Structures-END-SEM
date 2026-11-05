#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void is_empty()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty !!! Underflow\n");
    }
    return;
}

void is_full()
{
    if (rear == (MAX - 1))
    {
        printf("\nQueue is full!!! Overflow\n");
    }
    return;
}

void enqueue(int data)
{
    if (rear == (MAX - 1))
    {
        printf("\nQueue is full!!! Overflow\n");
        return;
    }
    else if (front == -1 && rear == -1)
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
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty !!! Underflow\n");
    }
    else if (front == rear)
    {
        printf("\nDeleted Element: %d \n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("\nDeleted Element: %d \n", queue[front]);
        front++;
    }
}

void getFront()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty!!! Underflow\n");
        return;
    }
    else
    {
        printf("\nFront element: %d\n", queue[front]);
    }
}

void getRear()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty!!! Underflow\n");
        return;
    }
    else
    {
        printf("\nRear element: %d\n", queue[rear]);
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty!!! Underflow\n");
        return;
    }

    printf("\nQueue Elements: ");

    for (int i = front; i <= rear; i++)
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

}
