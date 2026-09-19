#include <stdio.h>
#include <conio.h>

#define MAX 100

int stack[MAX];
int top = -1;

/* Function to push an element */
void push()
{
    int value;

    if (top == MAX - 1)
    {
        printf("\nStack Overflow!");
    }
    else
    {
        printf("\nEnter value to push: ");
        scanf("%d", &value);

        top++;
        stack[top] = value;

        printf("%d pushed into stack.", value);
    }
}

/* Function to pop an element */
void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        printf("\n%d popped from stack.", stack[top]);
        top--;
    }
}

/* Function to peep at the top element */
void peep()
{
    if (top == -1)
    {
        printf("\nStack is empty!");
    }
    else
    {
        printf("\nTop element is: %d", stack[top]);
    }
}

/* Function to modify an element */
void modify()
{
    int position, value;

    if (top == -1)
    {
        printf("\nStack is empty!");
    }
    else
    {
        printf("\nEnter position to modify (1 to %d): ", top + 1);
        scanf("%d", &position);

        if (position < 1 || position > top + 1)
        {
            printf("\nInvalid position!");
        }
        else
        {
            printf("Enter new value: ");
            scanf("%d", &value);

            stack[position - 1] = value;

            printf("\nElement modified successfully.");
        }
    }
}

/* Function to display the stack */
void display()
{
    int i;

    if (top == -1)
    {
        printf("\nStack is empty!");
    }
    else
    {
        printf("\n\nStack elements are:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

/* Main function */
void main()
{
    int choice;

    clrscr();

    do
    {
        printf("\n\n========== STACK MENU ==========");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEP");
        printf("\n4. MODIFY");
        printf("\n5. DISPLAY");
        printf("\n6. EXIT");
        printf("\n================================");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peep();
                break;

            case 4:
                modify();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("\nExiting program...");
                break;

            default:
                printf("\nInvalid choice! Please try again.");
        }

        if (choice != 6)
        {
            printf("\n\nPress any key to continue...");
            getch();
            clrscr();
        }

    } while (choice != 6);

    getch();
}