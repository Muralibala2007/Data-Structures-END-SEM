#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void is_full()
{
    if(((rear+1)%MAX)== front)
    {
        printf("\n Circular queue is Full!!! Overflow");
    }
    else
    {
        printf("\n Queue is not full!!!\n");
    }
}

void is_empty()
{
    if(front == -1 && rear == -1)
    {
        printf("\n Circular queue is empty!!! Underflow \n");
    }
    else{
        printf("\n Circular queue is not empty!!!");
    }
}

void enqueue(int data)
{
    if(((rear+1)%MAX)== front)
    {
        printf("\nCircular queue is Full!!! Overflow");
    }
    else if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear]= data;
    }
    else
    {
        rear = (rear + 1)%MAX;
        queue[rear]=data;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
        {
            printf("\nCircular queue is empty!!! Underflow \n");
        }
        else if(front == rear)//only 1 element is left
        {
            printf("\nDeleted element: %d", queue[front]);
            front=rear=-1;
        }
        else
        {
            printf("\nDeleted Element: %d", queue[front]);
            front = (front + 1) % MAX;
        }
}

void getFront()
{
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is Empty!!! Underflow\n");
        return;
    }

    printf("\nFront element: %d\n", queue[front]);
}

void getRear()
{
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is Empty!!! Underflow\n");
        return;
    }
    printf("\nRear element: %d\n", queue[rear]);
}

void display()
{   
    if(front == -1 && rear == -1)
    {
        printf("\n Circular queue is empty!!! Underflow \n");
    }
    
    printf("\nQueue Elements: ");
    int i=front;
    
    while(i!=rear)
    {
        printf("%d ", queue[i]);
        i=(i+1)%MAX;
    }
    printf("%d\n", queue[rear]);
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