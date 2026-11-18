#include <stdio.h>

int main()
{
    int a[100], n, key;
    int low, high, mid;
    int flag = 0, loc;

    printf("Enter the size of the list: ");
    scanf("%d", &n);

    printf("Enter the elements in sorted order:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == key)
        {
            loc = mid;
            flag = 1;
            break;
        }
        else if (key < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (flag == 1)
    {
        printf("Key is found at location %d", loc);
    }
    else
    {
        printf("Key is not found in the list");
    }

    return 0;
}
