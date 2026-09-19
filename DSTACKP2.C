
#include <stdio.h>
#include <conio.h>

#define MAX 100

int stack[MAX];
int top1 = -1;
int top2 = MAX;

void push1()
{
    int value;

    if (top1 + 1 == top2)
    {
	printf("\nStack Overflow!");
    }
    else
    {
	printf("\nEnter value for Stack 1: ");
	scanf("%d", &value);

	top1++;
	stack[top1] = value;

	printf("%d pushed into Stack 1.", value);
    }
}


void push2()
{
    int value;

    if (top1 + 1 == top2)
    {
	printf("\nStack Overflow!");
    }
    else
    {
	printf("\nEnter value for Stack 2: ");
	scanf("%d", &value);

	top2--;
	stack[top2] = value;

	printf("%d pushed into Stack 2.", value);
    }
}


void pop1()
{
    if (top1 == -1)
    {
	printf("\nStack 1 Underflow!");
    }
    else
    {
	printf("\n%d popped from Stack 1.", stack[top1]);
	top1--;
    }
}

void pop2()
{
    if (top2 == MAX)
    {
	printf("\nStack 2 Underflow!");
    }
    else
    {
	printf("\n%d popped from Stack 2.", stack[top2]);
	top2++;
    }
}


void peep1()
{
    if (top1 == -1)
    {
	printf("\nStack 1 is empty!");
    }
    else
    {
	printf("\nTop element of Stack 1 is: %d", stack[top1]);
    }
}


void peep2()
{
    if (top2 == MAX)
    {
	printf("\nStack 2 is empty!");
    }
    else
    {
	printf("\nTop element of Stack 2 is: %d", stack[top2]);
    }
}


void modify1()
{
    int position, value;

    if (top1 == -1)
    {
	printf("\nStack 1 is empty!");
    }
    else
    {
	printf("\nEnter position to modify in Stack 1 (1 to %d): ",
	       top1 + 1);
	scanf("%d", &position);

	if (position < 1 || position > top1 + 1)
	{
	    printf("\nInvalid position!");
	}
	else
	{
	    printf("Enter new value: ");
	    scanf("%d", &value);

	    stack[position - 1] = value;

	    printf("\nStack 1 element modified successfully.");
	}
    }
}


void modify2()
{
    int position, value;
    int index;

    if (top2 == MAX)
    {
	printf("\nStack 2 is empty!");
    }
    else
    {
	printf("\nEnter position to modify in Stack 2 (1 to %d): ",
	       MAX - top2);
	scanf("%d", &position);

	if (position < 1 || position > MAX - top2)
	{
	    printf("\nInvalid position!");
	}
	else
	{
	    printf("Enter new value: ");
	    scanf("%d", &value);

	    /*
	     * Stack 2 grows from right to left.
	     * Position 1 is the bottom element.
	     */
	    index = MAX - position;

	    stack[index] = value;

	    printf("\nStack 2 element modified successfully.");
	}
    }
}


void display1()
{
    int i;

    if (top1 == -1)
    {
	printf("\nStack 1 is empty!");
    }
    else
    {
	printf("\n\nStack 1 elements are:\n");

	for (i = top1; i >= 0; i--)
	{
	    printf("%d\n", stack[i]);
	}
    }
}


void display2()
{
    int i;

    if (top2 == MAX)
    {
	printf("\nStack 2 is empty!");
    }
    else
    {
	printf("\n\nStack 2 elements are:\n");

	for (i = top2; i < MAX; i++)
	{
	    printf("%d\n", stack[i]);
	}
    }
}


void main()
{
    int choice;

    clrscr();

    do
    {
	printf("\n\n========== DOUBLE STACK MENU ==========");
	printf("\n1. PUSH IN STACK 1");
	printf("\n2. PUSH IN STACK 2");
	printf("\n3. POP FROM STACK 1");
	printf("\n4. POP FROM STACK 2");
	printf("\n5. PEEP STACK 1");
	printf("\n6. PEEP STACK 2");
	printf("\n7. MODIFY STACK 1");
	printf("\n8. MODIFY STACK 2");
	printf("\n9. DISPLAY STACK 1");
	printf("\n10. DISPLAY STACK 2");
	printf("\n11. EXIT");
	printf("\n=======================================");

	printf("\nEnter your choice: ");
	scanf("%d", &choice);

	switch (choice)
	{
	    case 1:
		push1();
		break;

	    case 2:
		push2();
		break;

	    case 3:
		pop1();
		break;

	    case 4:
		pop2();
		break;

	    case 5:
		peep1();
		break;

	    case 6:
		peep2();
		break;

	    case 7:
		modify1();
		break;

	    case 8:
		modify2();
		break;

	    case 9:
		display1();
		break;

	    case 10:
		display2();
		break;

	    case 11:
		printf("\nExiting program...");
		break;

	    default:
		printf("\nInvalid choice! Please try again.");
	}

	if (choice != 11)
	{
	    printf("\n\nPress any key to continue...");
	    getch();
	    clrscr();
	}

    } while (choice != 11);

    getch();
}