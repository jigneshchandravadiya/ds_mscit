#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* insert(struct node *root, int value) {
    if (root == NULL) {
        struct node *newnode;
        newnode = (struct node*)malloc(sizeof(struct node));

        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;

        return newnode;
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node *root = NULL;
    int choice, value;

    do {
        printf("\n\n--- BINARY TREE MENU ---");
        printf("\n1. Insert");
        printf("\n2. Preorder Traversal");
        printf("\n3. Inorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter integer value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                break;

            case 5:
                printf("Exiting program...");
                break;

            default:
                printf("Invalid choice!");
        }
    } while (choice != 5);

    return 0;
}