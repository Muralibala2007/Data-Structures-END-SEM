#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAX 100

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

int main()
{
    char exp[MAX];
    printf("Enter Postfix Expression: ");
    scanf("%s",exp);
    int i;
    for(i = 0;i<strlen(exp);i++)
    {
        char c = exp[i];
        if(isdigit(c))
            push(c-'0');
        else if(c=='+'||c=='-'||c=='/'||c=='*'||c=='^')
        {
            int a = pop();
            int b = pop();

            if(c=='+') push(b+a);
            else if(c=='-') push(b-a);
            else if(c=='/') push(b/a);
            else if(c=='*') push(b*a);
            else push(pow(b,a));
        }
    }
    printf("Answer: %d",pop());
}