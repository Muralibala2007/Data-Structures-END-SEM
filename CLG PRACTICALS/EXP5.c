#include<stdio.h>
#include<stdbool.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

bool isEmpty()
{
    return front==-1 && rear==-1;
}

bool isFull()
{
    return rear==(MAX-1);
}

void enqueue(int x)
{
    if(isFull())
    {
        printf("Queue Overflow\n");
        return;
    }
    if(isEmpty())
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        queue[++rear] = x;
    }
}

int dequeue()
{
    if(isEmpty())
    {
        printf("Queue Underflow\n");
        return -1;
    }
    int x = queue[front];
    if(front==rear)
        front = rear = -1;
    else
        front++;
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
    for(int i = front;i<=rear;i++)
        printf("%d ",queue[i]);
    printf("\n");
}

int main()
{
  enqueue(10); enqueue(20); enqueue(30);
  enqueue(40); enqueue(50); enqueue(60);
  display();

  printf("Deleted Element: %d\n",dequeue());
  printf("Deleted Element: %d\n",dequeue());

  printf("Front Element: %d\n",getFront());
  printf("Rear Element: %d\n",getRear());
  display();
}