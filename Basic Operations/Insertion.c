#include<stdio.h>
int main()
{
    int size;
    printf("Enter size of array: ");
    scanf("%d",&size);
    int a[size];
    printf("Enter elements of array: ");
    for(int i=0;i<size; i++)
    {
        scanf("%d",&a[i]);
    }
    int num,pos;
    printf("Enter data you want to insert ");
    scanf("%d",&num);
    printf("Enter position: ");
    scanf("%d",&pos);

    if(pos<=0 || pos>size+1)
    {
        printf("Invalid position");
    }
    for(int i=size-1;i>=pos-1;i--)
    {
        a[i+1]=a[i];
    }
    a[pos-1]=num;
    size++;
    
    printf("Elements in array: ");
    for(int i=0;i<size; i++)
    {
        printf("%d ",a[i]);
    }
}