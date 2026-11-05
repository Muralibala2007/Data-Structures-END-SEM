
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Check if queue is full
int is_full()
{
    if((rear + 1) % MAX == front)
    {
        return 1;
    }
    return 0;
}

// Check if queue is empty
int is_empty()
{
    if(front == -1 && rear == -1)
    {
        return 1;
    }
    return 0;
}

// Insert element
void enqueue(int data)
{
    if(is_full())
    {
        printf("\nCircular Queue is Full!!! Overflow\n");
        return;
    }

    if(is_empty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = data;
}

// Delete element
void dequeue()
{
    if(is_empty())
    {
        printf("\nCircular Queue is Empty!!! Underflow\n");
        return;
    }

    printf("\nDeleted Element: %d\n", queue[front]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

// Get front element
void getFront()
{
    if(is_empty())
    {
        printf("\nQueue is Empty!!! Underflow\n");
        return;
    }

    printf("\nFront element: %d\n", queue[front]);
}

// Get rear element
void getRear()
{
    if(is_empty())
    {
        printf("\nQueue is Empty!!! Underflow\n");
        return;
    }

    printf("\nRear element: %d\n", queue[rear]);
}

// Display queue
void display()
{
    if(is_empty())
    {
        printf("\nQueue is Empty!!! Underflow\n");
        return;
    }

    printf("\nQueue Elements: ");

    int i = front;

    while(i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }

    printf("%d\n", queue[rear]);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    enqueue(60);
    enqueue(70);

    display();

    getFront();
    getRear();

    return 0;
}
