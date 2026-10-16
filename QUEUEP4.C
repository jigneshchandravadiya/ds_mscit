#include <stdio.h>
#include <conio.h>

#define MAX 50

void insert(int Q[], int n, int *F, int *R)
{
    int no;

    if (*R == n - 1)
    {
        printf("\nQueue Overflow");
        return;
    }

    printf("\nEnter Number : ");
    scanf("%d", &no);

    *R = *R + 1;
    Q[*R] = no;

    if (*F == -1)
    {
        *F = 0;
    }

    printf("\nNumber Inserted");
}

void deleteq(int Q[], int *F, int *R)
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
        *F = *F + 1;
    }
}

void modify(int Q[], int F, int R)
{
    int pos, no;

    if (F == -1)
    {
        printf("\nQueue Empty");
        return;
    }

    printf("\nEnter Position : ");
    scanf("%d", &pos);

    if (pos < F || pos > R)
    {
        printf("\nInvalid Position");
        return;
    }

    printf("\nEnter New Number : ");
    scanf("%d", &no);

    Q[pos] = no;

    printf("\nValue Modified Successfully");
}

void display(int Q[], int F, int R)
{
    int i;

    if (F == -1)
    {
        printf("\nQueue Empty");
        return;
    }

    printf("\nQueue : ");

    for (i = F; i <= R; i++)
    {
        printf("%d ", Q[i]);
    }
}

void main()
{
    int Q[MAX];
    int n;
    int F = -1;
    int R = -1;
    int ch;

    clrscr();

    printf("Enter Size of Queue : ");
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("\nQueue Size Cannot Be Greater Than 50");
        getch();
        return;
    }

    do
    {
        printf("\n\n==========================");
        printf("\n       SIMPLE QUEUE");
        printf("\n==========================");

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
                deleteq(Q, &F, &R);
                break;

            case 3:
                modify(Q, F, R);
                break;

            case 4:
                display(Q, F, R);
                break;

            case 5:
                printf("\n\nExit");
                break;

            default:
                printf("\nInvalid Choice");
        }

    } while (ch != 5);

    getch();
}
