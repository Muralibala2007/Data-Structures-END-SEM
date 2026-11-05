#include<stdio.h>
#include<stdbool.h>

#define MAX 10

int stack[MAX];

int top = -1;

bool isEmpty()
{
    return top==-1;
}

bool isFull()
{
    return top==(MAX-1);
}

void push(int x)
{
    if(isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        return -1;
    }

    int x = stack[top--];
    return x;
}

int peek()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack[top];
}

void display()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack: ");
    for(int i = top;i>=0;i--)
        printf("%d ",stack[i]);
    printf("\n");
}

int main()
{
  push(10); push(20); push(30);
  push(40); push(50); push(60);
  display();
  printf("Popped Element: %d\n",pop());
  printf("Top Element: %d\n",peek());
  display();
}
