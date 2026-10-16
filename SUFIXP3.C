#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int priority(char ch)
{
    if (ch == '^')
        return 3;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

void main()
{
    char infix[50];
    char suffix[50];
    char stack[50];

    int top = -1;
    int i = 0;
    int j = 0;
    char ch;

    clrscr();

    printf("=================================");
    printf("\n     INFIX TO SUFFIX");
    printf("\n=================================");

    printf("\n\nEnter Infix Expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0')
    {
        ch = infix[i];

        /* Operand */
        if (isalnum(ch))
        {
            suffix[j] = ch;
            j++;
        }

        /* Opening bracket */
        else if (ch == '(')
        {
            top++;
            stack[top] = ch;
        }

        /* Closing bracket */
        else if (ch == ')')
        {
            while (top >= 0 && stack[top] != '(')
            {
                suffix[j] = stack[top];
                j++;
                top--;
            }

            if (top >= 0 && stack[top] == '(')
                top--;
        }

        /* Operator */
        else
        {
            while (top >= 0 &&
                   stack[top] != '(' &&
                   priority(stack[top]) >= priority(ch))
            {
                suffix[j] = stack[top];
                j++;
                top--;
            }

            top++;
            stack[top] = ch;
        }

        i++;
    }

    /* Remove remaining operators */
    while (top >= 0)
    {
        suffix[j] = stack[top];
        j++;
        top--;
    }

    suffix[j] = '\0';

    printf("\n\n---------------------------------");
    printf("\nInfix  Expression : %s", infix);
    printf("\nSuffix Expression : %s", suffix);
    printf("\n---------------------------------");

    printf("\n\nPress any key to exit...");
    getch();
}
