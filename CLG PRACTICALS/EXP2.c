#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

int priority(char x) 
{
    if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='/')
        return 2;
    else if(x=='^')
        return 3;
}

int main()
{
  char inFix[MAX], postfix[MAX];

  printf("Enter The Infix Expression: ");
  scanf("%s",inFix);
  
  printf("Postfix Expression: ");
  int i;
  for(i = 0;i<strlen(inFix);i++)
  {
    char c = inFix[i];
    if(isalnum(c))
        printf("%c",c);
    else if(c=='(')
        push(c);
    else if(c==')')
    {
        while(peek()!='(')
        {
            printf("%c",pop());
        }
        pop();
    }
    else
    {
        while(top!=-1 && priority(peek())>=priority(c))
            printf("%c",pop());
        push(c);
    }
  }

  while(top!=-1)
    printf("%c",pop());

}