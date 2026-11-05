#include<stdio.h>
int main()
{
    int size;
    printf("Enter size of array: ");
    scanf("%d",&size);
    int a[size];
    printf("Enter elements of arrat: ");
    for(int i=0;i<size; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Elements in array: ");
    for(int i=0;i<size; i++)
    {
        printf("%d ",a[i]);
    }
}