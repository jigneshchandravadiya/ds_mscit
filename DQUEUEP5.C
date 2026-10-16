#include <stdio.h>
#include <conio.h>

#define MAX 50

void insert(int Q[], int n, int *F1, int *R1, int *F2, int *R2)
{
    int no, q;

    printf("\nEnter Queue (1/2) : ");
    scanf("%d", &q);

    if (*R1 + 1 == *R2)
    {
        printf("\nQueue Overflow");
        return;
    }

    printf("Enter Number : ");
    scanf("%d", &no);

    if (q == 1)
    {
        if (*F1 == -1)
        {
            *F1 = 0;
            *R1 = 0;
        }
        else
        {
            *R1 = *R1 + 1;
        }

        Q[*R1] = no;

        printf("\nInserted in Queue 1");
    }
    else if (q == 2)
    {
        if (*F2 == -1)
        {
            *F2 = n - 1;
            *R2 = n - 1;
        }
        else
        {
            *R2 = *R2 - 1;
        }

        Q[*R2] = no;

        printf("\nInserted in Queue 2");
    }
    else
    {
        printf("\nInvalid Queue");
    }
}


void deleteq(int Q[], int *F1, int *R1, int *F2, int *R2)
{
    int q;

    printf("\nEnter Queue (1/2) : ");
    scanf("%d", &q);

    if (q == 1)
    {
        if (*F1 == -1)
        {
            printf("\nQueue 1 Underflow");
            return;
        }

        printf("\nDeleted = %d", Q[*F1]);

        if (*F1 == *R1)
        {
            *F1 = -1;
            *R1 = -1;
        }
        else
        {
            *F1 = *F1 + 1;
        }
    }
    else if (q == 2)
    {
        if (*F2 == -1)
        {
            printf("\nQueue 2 Underflow");
            return;
        }

        printf("\nDeleted = %d", Q[*F2]);

        if (*F2 == *R2)
        {
            *F2 = -1;
            *R2 = -1;
        }
        else
        {
            *F2 = *F2 - 1;
        }
    }
    else
    {
        printf("\nInvalid Queue");
    }
}


void modify(int Q[], int F1, int R1, int F2, int R2)
{
    int q, pos, no;

    printf("\nEnter Queue (1/2) : ");
    scanf("%d", &q);

    if (q == 1)
    {
        if (F1 == -1)
        {
            printf("\nQueue 1 Empty");
            return;
        }

        printf("\nEnter Position : ");
        scanf("%d", &pos);

        if (pos < F1 || pos > R1)
        {
            printf("\nInvalid Position");
            return;
        }

        printf("Enter New Number : ");
        scanf("%d", &no);

        Q[pos] = no;

        printf("\nValue Modified Successfully");
    }
    else if (q == 2)
    {
        if (F2 == -1)
        {
            printf("\nQueue 2 Empty");
            return;
        }

        printf("\nEnter Position : ");
        scanf("%d", &pos);

        if (pos > F2 || pos < R2)
        {
            printf("\nInvalid Position");
            return;
        }

        printf("Enter New Number : ");
        scanf("%d", &no);

        Q[pos] = no;

        printf("\nValue Modified Successfully");
    }
    else
    {
        printf("\nInvalid Queue");
    }
}


void display(int Q[], int F1, int R1, int F2, int R2)
{
    int q;
    int i;

    printf("\nEnter Queue (1/2) : ");
    scanf("%d", &q);

    if (q == 1)
    {
        if (F1 == -1)
        {
            printf("\nQueue 1 Empty");
            return;
        }

        printf("\nQueue 1 : ");

        for (i = F1; i <= R1; i++)
        {
            printf("%d ", Q[i]);
        }
    }
    else if (q == 2)
    {
        if (F2 == -1)
        {
            printf("\nQueue 2 Empty");
            return;
        }

        printf("\nQueue 2 : ");

        for (i = F2; i >= R2; i--)
        {
            printf("%d ", Q[i]);
        }
    }
    else
    {
        printf("\nInvalid Queue");
    }
}


void main()
{
    int Q[MAX];

    int n;
    int F1, R1;
    int F2, R2;
    int ch;

    clrscr();

    F1 = -1;
    R1 = -1;

    F2 = -1;
    R2 = -1;

    printf("Enter Size of Array : ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("\nInvalid Size");
        getch();
        return;
    }

    do
    {
        printf("\n\n==========================");
        printf("\n       DOUBLE QUEUE");
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
                insert(Q, n, &F1, &R1, &F2, &R2);
                break;

            case 2:
                deleteq(Q, &F1, &R1, &F2, &R2);
                break;

            case 3:
                modify(Q, F1, R1, F2, R2);
                break;

            case 4:
                display(Q, F1, R1, F2, R2);
                break;

            case 5:
                printf("\nExit");
                break;

            default:
                printf("\nInvalid Choice");
        }

        if (ch != 5)
        {
            printf("\n\nPress any key...");
            getch();
            clrscr();
        }

    } while (ch != 5);

    getch();
}

