#include<stdio.h>
#include<stdbool.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

bool isEmpty()
{
    return front == -1;
}

bool isFull()
{
    return (rear + 1) % MAX == front;
}

void enqueue(int x)
{
    if(isFull())
    {
        printf("Queue Overflow\n");
        return;
    }

    if(isEmpty())
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = x;
}

int dequeue()
{
    if(isEmpty())
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int x = queue[front];

    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }

    return x;
}

int getFront()
{
    if(isEmpty())
    {
        printf("Queue is Empty\n");
        return -1;
    }

    return queue[front];
}

int getRear()
{
    if(isEmpty())
    {
        printf("Queue is Empty\n");
        return -1;
    }

    return queue[rear];
}
void display()
{
    if(isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue: ");
    int i;
    for(i = front; ; i = (i + 1) % MAX)
    {
        printf("%d ", queue[i]);
        if(i == rear)
            break;
    }
    printf("\n");
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    printf("Dequeued Element: %d\n", dequeue());
    printf("Front Element: %d\n", getFront());
    printf("Rear Element: %d\n", getRear());

    enqueue(60);

    display();
}