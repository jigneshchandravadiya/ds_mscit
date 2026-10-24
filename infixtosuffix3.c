#include<stdio.h>
#include<ctype.h>

int precedence(char ch)
{
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

void push(char stack[], int *top, char ch)
{
    *top = *top + 1;
    stack[*top] = ch;
}

char pop(char stack[], int *top)
{
    char ch;

    ch = stack[*top];
    *top = *top - 1;

    return ch;
}

char peep(char stack[], int top)
{
    return stack[top];
}

int main()
{
    char infix[100], suffix[100];
    char stack[100];

    int top = -1;
    int i = 0, j = 0;
    char ch;

    printf("Enter Infix Expression : ");
    scanf("%s", infix);

    while(infix[i] != '\0')
    {
        ch = infix[i];

        
        if(isalnum(ch))
        {
            suffix[j] = ch;
            j++;
        }

        
        else if(ch == '(')
        {
            push(stack, &top, ch);
        }

        
        else if(ch == ')')
        {
            while(top != -1 && peep(stack, top) != '(')
            {
                suffix[j] = pop(stack, &top);
                j++;
            }

            if(top != -1 && peep(stack, top) == '(')
            {
                pop(stack, &top);
            }
        }

        
        else
        {
            while(top != -1 &&
                  peep(stack, top) != '(' &&
                  precedence(peep(stack, top)) >= precedence(ch))
            {
                suffix[j] = pop(stack, &top);
                j++;
            }

            push(stack, &top, ch);
        }

        i++;
    }

    
    while(top != -1)
    {
        suffix[j] = pop(stack, &top);
        j++;
    }

    suffix[j] = '\0';

    printf("\nSuffix Expression = %s", suffix);

    return 0;
}