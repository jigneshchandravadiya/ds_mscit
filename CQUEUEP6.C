#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 100

void insert(int Q[], int n, int *F, int *R)
{
    int no;

    if ((*F == 0 && *R == n - 1) || (*F == *R + 1))
    {
        printf("\nQueue Overflow");
        return;
    }

    printf("\nEnter Number : ");
    scanf("%d", &no);

    if (*F == -1)
    {
        *F = 0;
        *R = 0;
    }
    else
    {
        *R = (*R + 1) % n;
    }

    Q[*R] = no;

    printf("\nNumber Inserted");
}

void deleteq(int Q[], int n, int *F, int *R)
{
    if (*F == -1)
    {
        printf("\nQueue Underflow");
        return;
    }

    printf("\nDeleted = %d", Q[*F]);

    if (*F == *R)
    {
        *F = -1;
        *R = -1;
    }
    else
    {
        *F = (*F + 1) % n;
    }
}

void modify(int Q[], int n, int F, int R)
{
    int pos, no, i;

    if (F == -1)
    {
        printf("\nQueue Empty");
        return;
    }

    printf("\nEnter Position : ");
    scanf("%d", &pos);

    i = F;

    while (1)
    {
        if (i == pos)
        {
            printf("Enter New Number : ");
            scanf("%d", &no);

            Q[i] = no;

            printf("\nValue Modified Successfully");
            return;
        }

        if (i == R)
            break;

        i = (i + 1) % n;
    }

    printf("\nInvalid Position");
}

void display(int Q[], int n, int F, int R)
{
    int i;

    if (F == -1)
    {
        printf("\nQueue Empty");
        return;
    }

    printf("\nQueue : ");

    i = F;

    while (1)
    {
        printf("%d ", Q[i]);

        if (i == R)
            break;

        i = (i + 1) % n;
    }
}

void main()
{
    int n;
    int Q[MAX];
    int F = -1, R = -1;
    int ch;

    clrscr();

    printf("Enter Size of Queue : ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("\nInvalid Queue Size");
        getch();
        return;
    }

    do
    {
        clrscr();

        printf("\n\n----- CIRCULAR QUEUE -----");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Modify");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\n\nEnter Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                insert(Q, n, &F, &R);
                break;

            case 2:
                deleteq(Q, n, &F, &R);
                break;

            case 3:
                modify(Q, n, F, R);
                break;

            case 4:
                display(Q, n, F, R);
                break;

            case 5:
                printf("\nExit");
                break;

            default:
                printf("\nInvalid Choice");
        }

        if (ch != 5)
        {
            printf("\n\nPress any key to continue...");
            getch();
        }

    } while (ch != 5);

    getch();
}
