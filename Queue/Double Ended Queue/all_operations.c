#include<stdio.h>
#define MAX 5

int DEqueue[MAX];
int front = -1;
int rear = -1;

void is_empty()
{
    if(front ==  -1 && rear == -1)
    {
        printf("\nDE Queue is empty!!!\n");
    }
}

void is_full()
{
    if((front == -1 && rear == MAX -1) || (front == rear +1))
    {
        printf("\nDE Queue is full !!!\n");
    }
}

void enqueue_front(int data)
{
    if((front == 0 && rear == MAX -1) || (front == rear +1))
    {
        printf("\nDE Queue is full !!!\n");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        DEqueue[front] = data;
    }
    else if(front == 0)
    {
        front = MAX-1;
        DEqueue[front] =data;
    }
    else
    {
        front--;
        DEqueue[front]= data;
    }
}

void enqueue_rear(int data)
{
    if((front == 0 && rear == MAX -1) || (front == rear +1))
    {
        printf("DE Queue is full !!!");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        DEqueue[rear]=data;
    }
    else if(rear == MAX-1)
    {
        rear = 0;
        DEqueue[rear]=data;
    }
    else
    {
        rear++;
        DEqueue[rear] = data;
    }
}

void dequeue_front()
{
    if(front == -1 && rear == -1)
    {
        printf("DE Queue is empty");
    }
    else if(front == rear)
    { 
        printf("Dequeued element: %d ",DEqueue[front]);
        front=rear=-1;
    }
    else if(front==MAX-1)
    {
        printf("Dequeued element: %d ",DEqueue[front]);
        front = 0;
    }
    else
    {
        printf("Dequeued element: %d ",DEqueue[front]);
        front++;
    }
}

void dequeue_rear()
{
    if(front == -1 && rear == -1)
    {
        printf("DE Queue is empty");
    }
    else if(front == rear)
    {
        printf("\nDequeued element: %d ",DEqueue[rear]);
        front=rear=-1;
    }
    else if(rear==0)
    {
        printf("\nDequeued element: %d ",DEqueue[rear]);
        rear=MAX-1;
    }
    else
    {
        printf("\nDequeued element: %d ",DEqueue[rear]);
        rear--;
    }
}

void display()
{
    if(front == -1 && rear == -1)
    {
        printf("DE Queue is empty");
        return;
    }

    printf("DE Queue elements: ");
    int i=front;

    while(i!=rear)
    {
        printf("%d ", DEqueue[i]);
        i=(i+1)%MAX;
    }
    printf("%d", DEqueue[i]);

}

void getFront()
{
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is Empty!!! Underflow\n");
        return;
    }

    printf("\nFront element: %d", DEqueue[front]);
}

void getRear()
{
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is Empty!!! Underflow\n");
        return;
    }
    printf("\nRear element: %d\n", DEqueue[rear]);
}

int main()
{
    enqueue_front(10);
    enqueue_front(20);
    enqueue_front(30);
    enqueue_rear(40);
    enqueue_rear(50);

    display();

    getFront();
    getRear();

    dequeue_front();
    dequeue_rear();
    
}