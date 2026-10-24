
#include <stdio.h>
#include <conio.h>

void main()
{
    int a[100], n, i, key, choice;
    int low, high, mid, found;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in ascending order:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    printf("\n1. Linear Search");
    printf("\n2. Binary Search");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    found = 0;

    if(choice == 1)
    {
        for(i = 0; i < n; i++)
        {
            if(a[i] == key)
            {
                printf("Element found at position %d", i + 1);
                found = 1;
                break;
            }
        }

        if(found == 0)
            printf("Element not found");
    }
    else if(choice == 2)
    {
        low = 0;
        high = n - 1;

        while(low <= high)
        {
            mid = (low + high) / 2;

            if(a[mid] == key)
            {
                printf("Element found at position %d", mid + 1);
                found = 1;
                break;
            }
            else if(a[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }

        if(found == 0)
            printf("Element not found");
    }
    else
    {
        printf("Invalid choice");
    }

    getch();
}