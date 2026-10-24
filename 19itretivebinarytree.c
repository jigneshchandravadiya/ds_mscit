#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *root = NULL;

/* Iterative insertion */
void insert()
{
    struct node *newnode, *temp, *parent;
    int value;

    printf("Enter value: ");
    scanf("%d", &value);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;

    if (root == NULL)
    {
        root = newnode;
        printf("Node inserted successfully.\n");
        return;
    }

    temp = root;
    parent = NULL;

    while (temp != NULL)
    {
        parent = temp;

        if (value < temp->data)
            temp = temp->left;
        else if (value > temp->data)
            temp = temp->right;
        else
        {
            printf("Duplicate value not allowed.\n");
            free(newnode);
            return;
        }
    }

    if (value < parent->data)
        parent->left = newnode;
    else
        parent->right = newnode;

    printf("Node inserted successfully.\n");
}

/* Iterative inorder display */
void display()
{
    struct node *stack[100];
    struct node *temp = root;
    int top = -1;

    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    printf("Inorder traversal: ");

    while (temp != NULL || top != -1)
    {
        while (temp != NULL)
        {
            stack[++top] = temp;
            temp = temp->left;
        }

        temp = stack[top--];
        printf("%d ", temp->data);

        temp = temp->right;
    }

    printf("\n");
}

/* Delete node containing given information */
void deleteNode()
{
    struct node *temp = root;
    struct node *parent = NULL;
    struct node *successor, *succParent;
    int value;

    printf("Enter value to delete: ");
    scanf("%d", &value);

    /* Search for the node iteratively */
    while (temp != NULL && temp->data != value)
    {
        parent = temp;

        if (value < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if (temp == NULL)
    {
        printf("Value not found.\n");
        return;
    }

    /* Case 1: Node has no left child */
    if (temp->left == NULL)
    {
        if (parent == NULL)
            root = temp->right;
        else if (parent->left == temp)
            parent->left = temp->right;
        else
            parent->right = temp->right;

        free(temp);
    }

    /* Case 2: Node has no right child */
    else if (temp->right == NULL)
    {
        if (parent == NULL)
            root = temp->left;
        else if (parent->left == temp)
            parent->left = temp->left;
        else
            parent->right = temp->left;

        free(temp);
    }

    /* Case 3: Node has two children */
    else
    {
        successor = temp->right;
        succParent = temp;

        /* Find inorder successor */
        while (successor->left != NULL)
        {
            succParent = successor;
            successor = successor->left;
        }

        /* Copy successor's value */
        temp->data = successor->data;

        /* Remove successor from its old position */
        if (succParent->left == successor)
            succParent->left = successor->right;
        else
            succParent->right = successor->right;

        free(successor);
    }

    printf("Node deleted successfully.\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- BINARY SEARCH TREE MENU ---\n");
        printf("1. Iterative Insert\n");
        printf("2. Iterative Display\n");
        printf("3. Delete Node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                deleteNode();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}