#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct node
{
    int row, col, data;
    struct node *right, *down;
};

struct matrix
{
    int rows, cols;
    struct node *rowHead[MAX];
    struct node *colHead[MAX];
};


void initialize(struct matrix *m, int r, int c)
{
    int i;

    m->rows = r;
    m->cols = c;

    for (i = 0; i < MAX; i++)
    {
        m->rowHead[i] = NULL;
        m->colHead[i] = NULL;
    }
}


void insert(struct matrix *m, int r, int c, int value)
{
    struct node *newnode, *temp, *prev;

    if (value == 0)
        return;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->row = r;
    newnode->col = c;
    newnode->data = value;
    newnode->right = NULL;
    newnode->down = NULL;

    
    temp = m->rowHead[r];
    prev = NULL;

    while (temp != NULL && temp->col < c)
    {
        prev = temp;
        temp = temp->right;
    }

    if (prev == NULL)
        m->rowHead[r] = newnode;
    else
        prev->right = newnode;

    newnode->right = temp;

    
    temp = m->colHead[c];
    prev = NULL;

    while (temp != NULL && temp->row < r)
    {
        prev = temp;
        temp = temp->down;
    }

    if (prev == NULL)
        m->colHead[c] = newnode;
    else
        prev->down = newnode;

    newnode->down = temp;
}


void create(struct matrix *m)
{
    int i, j, value;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m->rows, &m->cols);

    if (m->rows <= 0 || m->cols <= 0 ||
        m->rows > MAX || m->cols > MAX)
    {
        printf("Invalid matrix size.\n");
        m->rows = m->cols = 0;
        return;
    }

    initialize(m, m->rows, m->cols);

    printf("Enter matrix elements:\n");

    for (i = 0; i < m->rows; i++)
    {
        for (j = 0; j < m->cols; j++)
        {
            scanf("%d", &value);
            insert(m, i, j, value);
        }
    }
}


int getValue(struct matrix *m, int r, int c)
{
    struct node *temp = m->rowHead[r];

    while (temp != NULL && temp->col < c)
        temp = temp->right;

    if (temp != NULL && temp->col == c)
        return temp->data;

    return 0;
}


void display(struct matrix *m)
{
    int i, j;

    for (i = 0; i < m->rows; i++)
    {
        for (j = 0; j < m->cols; j++)
            printf("%4d", getValue(m, i, j));

        printf("\n");
    }
}


void addition(struct matrix *a, struct matrix *b,
               struct matrix *result)
{
    int i, j, value;

    if (a->rows != b->rows || a->cols != b->cols)
    {
        printf("Matrix addition is not possible.\n");
        return;
    }

    initialize(result, a->rows, a->cols);

    for (i = 0; i < a->rows; i++)
    {
        for (j = 0; j < a->cols; j++)
        {
            value = getValue(a, i, j) + getValue(b, i, j);

            insert(result, i, j, value);
        }
    }

    printf("Result of matrix addition:\n");
    display(result);
}


void multiplication(struct matrix *a, struct matrix *b,
                    struct matrix *result)
{
    int i, j, k, sum;

    if (a->cols != b->rows)
    {
        printf("Matrix multiplication is not possible.\n");
        return;
    }

    initialize(result, a->rows, b->cols);

    for (i = 0; i < a->rows; i++)
    {
        for (j = 0; j < b->cols; j++)
        {
            sum = 0;

            for (k = 0; k < a->cols; k++)
            {
                sum = sum + getValue(a, i, k) *
                            getValue(b, k, j);
            }

            insert(result, i, j, sum);
        }
    }

    printf("Result of matrix multiplication:\n");
    display(result);
}

int main()
{
    struct matrix a, b, result;
    int choice;

    do
    {
        printf("\n--- MULTILINKED MATRIX MENU ---\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter first matrix A:\n");
                create(&a);

                if (a.rows == 0)
                    break;

                printf("\nEnter second matrix B:\n");
                create(&b);

                if (b.rows == 0)
                    break;

                addition(&a, &b, &result);
                break;

            case 2:
                printf("\nEnter first matrix A:\n");
                create(&a);

                if (a.rows == 0)
                    break;

                printf("\nEnter second matrix B:\n");
                create(&b);

                if (b.rows == 0)
                    break;

                multiplication(&a, &b, &result);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 3);

    return 0;
}