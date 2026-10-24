#include <stdio.h>
#include <stdlib.h>

struct node
{
    int row, col, data;
    struct node *right, *down;
};

struct node *rowHead[20], *colHead[20];
int rows, cols;

/* Create a new node */
struct node *createNode(int r, int c, int value)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->row = r;
    newnode->col = c;
    newnode->data = value;
    newnode->right = NULL;
    newnode->down = NULL;

    return newnode;
}

/* Create matrix */
void create()
{
    int i, j, value;
    struct node *newnode, *temp;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 || cols <= 0 || rows > 20 || cols > 20)
    {
        printf("Invalid matrix size. Use dimensions from 1 to 20.\n");
        rows = cols = 0;
        return;
    }

    /* Initialize row and column headers */
    for (i = 0; i < rows; i++)
        rowHead[i] = NULL;

    for (j = 0; j < cols; j++)
        colHead[j] = NULL;

    printf("Enter matrix elements:\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &value);

            /* Store only non-zero elements */
            if (value != 0)
            {
                newnode = createNode(i, j, value);

                /* Link node in its row */
                if (rowHead[i] == NULL)
                    rowHead[i] = newnode;
                else
                {
                    temp = rowHead[i];

                    while (temp->right != NULL)
                        temp = temp->right;

                    temp->right = newnode;
                }

                /* Link node in its column */
                if (colHead[j] == NULL)
                    colHead[j] = newnode;
                else
                {
                    temp = colHead[j];

                    while (temp->down != NULL)
                        temp = temp->down;

                    temp->down = newnode;
                }
            }
        }
    }

    printf("Matrix created successfully.\n");
}

/* Display matrix */
void display()
{
    int i, j;
    struct node *temp;

    if (rows == 0 || cols == 0)
    {
        printf("Matrix is not created.\n");
        return;
    }

    printf("\nMatrix:\n");

    for (i = 0; i < rows; i++)
    {
        temp = rowHead[i];

        for (j = 0; j < cols; j++)
        {
            if (temp != NULL && temp->col == j)
            {
                printf("%4d", temp->data);
                temp = temp->right;
            }
            else
                printf("%4d", 0);
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- MULTILINKED MATRIX MENU ---\n");
        printf("1. Create Matrix\n");
        printf("2. Display Matrix\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 3);

    return 0;
}