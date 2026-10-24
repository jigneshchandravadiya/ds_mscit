#include <stdio.h>

#define MAX 20

int block[MAX];
int allocated[MAX];
int process[MAX];
int n;

/* Display memory blocks */
void display()
{
    int i;

    printf("\nMemory Block Status:\n");
    printf("Block\tSize\tStatus\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t", i + 1, block[i]);

        if (allocated[i] == 1)
            printf("Process %d\n", process[i]);
        else
            printf("Free\n");
    }
}

/* Best-Fit Allocation */
void allocation()
{
    int size, i, best = -1;

    printf("Enter process size: ");
    scanf("%d", &size);

    /* Find smallest suitable free block */
    for (i = 0; i < n; i++)
    {
        if (allocated[i] == 0 && block[i] >= size)
        {
            if (best == -1 || block[i] < block[best])
                best = i;
        }
    }

    if (best == -1)
    {
        printf("Allocation failed. No suitable block found.\n");
    }
    else
    {
        allocated[best] = 1;
        process[best] = size;

        printf("Process of size %d allocated to block %d.\n",
               size, best + 1);
    }

    display();
}

/* Deallocation */
void deallocation()
{
    int p, i, found = 0;

    printf("Enter process size to deallocate: ");
    scanf("%d", &p);

    for (i = 0; i < n; i++)
    {
        if (allocated[i] == 1 && process[i] == p)
        {
            allocated[i] = 0;
            process[i] = 0;

            printf("Process deallocated from block %d.\n",
                   i + 1);

            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("Process not found.\n");

    display();
}

int main()
{
    int i, choice;

    printf("Enter number of memory blocks (max %d): ", MAX);
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of blocks.\n");
        return 0;
    }

    printf("Enter sizes of memory blocks:\n");

    for (i = 0; i < n; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &block[i]);

        allocated[i] = 0;
        process[i] = 0;
    }

    do
    {
        printf("\n--- BEST-FIT MEMORY ALLOCATION ---\n");
        printf("1. Allocation\n");
        printf("2. Deallocation\n");
        printf("3. Display Memory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                allocation();
                break;

            case 2:
                deallocation();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}