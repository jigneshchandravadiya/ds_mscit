#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct node
{
    int vertex;
    struct node *next;
};

struct node *adj[MAX];
int n;

/* Create a new adjacency node */
struct node *createNode(int v)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->next = NULL;

    return newnode;
}

/* Add an edge to the adjacency list */
void addEdge(int u, int v)
{
    struct node *newnode, *temp;

    /* Add v to the list of u */
    newnode = createNode(v);

    if (adj[u] == NULL)
        adj[u] = newnode;
    else
    {
        temp = adj[u];

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    /* Add u to the list of v (undirected graph) */
    newnode = createNode(u);

    if (adj[v] == NULL)
        adj[v] = newnode;
    else
    {
        temp = adj[v];

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }
}

/* Create graph */
void createGraph()
{
    int i, edges, u, v;

    printf("Enter number of vertices (1-%d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of vertices.\n");
        n = 0;
        return;
    }

    for (i = 0; i < MAX; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    if (edges < 0)
    {
        printf("Invalid number of edges.\n");
        n = 0;
        return;
    }

    printf("Enter edges (u v), vertices numbered 0 to %d:\n",
           n - 1);

    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n)
        {
            printf("Invalid edge. Enter it again.\n");
            i--;
            continue;
        }

        addEdge(u, v);
    }

    printf("\nAdjacency List:\n");

    for (i = 0; i < n; i++)
    {
        struct node *temp = adj[i];

        printf("%d -> ", i);

        while (temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

/* Breadth First Search using queue */
void BFS()
{
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;
    int start, v;
    struct node *temp;

    if (n == 0)
    {
        printf("Create the graph first.\n");
        return;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid starting vertex.\n");
        return;
    }

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        v = queue[front++];

        printf("%d ", v);

        temp = adj[v];

        while (temp != NULL)
        {
            if (!visited[temp->vertex])
            {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }

            temp = temp->next;
        }
    }

    printf("\n");
}

/* Depth First Search using stack */
void DFS()
{
    int visited[MAX] = {0};
    int stack[MAX];
    int top = -1;
    int start, v;
    struct node *temp;

    if (n == 0)
    {
        printf("Create the graph first.\n");
        return;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid starting vertex.\n");
        return;
    }

    stack[++top] = start;

    printf("DFS Traversal: ");

    while (top != -1)
    {
        v = stack[top--];

        if (!visited[v])
        {
            visited[v] = 1;
            printf("%d ", v);

            /* Push adjacent vertices */
            temp = adj[v];

            while (temp != NULL)
            {
                if (!visited[temp->vertex])
                    stack[++top] = temp->vertex;

                temp = temp->next;
            }
        }
    }

    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- GRAPH MENU ---\n");
        printf("1. Create Graph\n");
        printf("2. BFS Traversal\n");
        printf("3. DFS Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createGraph();
                break;

            case 2:
                BFS();
                break;

            case 3:
                DFS();
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