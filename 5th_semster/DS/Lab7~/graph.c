#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct graph
{
    node *arrlist[MAX];
} graph;

graph *creategraph()
{
    graph *g = (graph *)malloc(sizeof(graph));
    for (int i = 0; i < MAX; i++)
    {
        g->arrlist[i] = NULL;
    }
    
    return g;
}

node *createnode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void addedge_list(graph *g, int u, int v)
{
    node *newnode = createnode(v);
    newnode->next = g->arrlist[u];
    g->arrlist[u] = newnode;
}

void addedge_list_undir(graph *g, int u, int v)
{
    addedge_list(g, u, v);
    addedge_list(g, v, u);
}

void remove_edge_list(graph *g, int u, int v)
{
    /* remove u -> v */
    node *temp = g->arrlist[u];
    node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == v)
        {
            if (prev == NULL)
                g->arrlist[u] = temp->next;
            else
                prev->next = temp->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    /* remove v -> u */
    temp = g->arrlist[v];
    prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == u)
        {
            if (prev == NULL)
                g->arrlist[v] = temp->next;
            else
                prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void printgraph_list(graph *g, int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d -> ", i);
        node *temp = g->arrlist[i];
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void init_matrix(int matrix[MAX][MAX], int n)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            matrix[i][j] = 0;
}

void addedge_matrix(int matrix[MAX][MAX], int u, int v)
{
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}

void remove_edge_matrix(int matrix[MAX][MAX], int u, int v)
{
    matrix[u][v] = 0;
    matrix[v][u] = 0;
}

void print_matrix(int matrix[MAX][MAX], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void matrix_to_list(int matrix[MAX][MAX], graph *g, int n)
{
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (matrix[i][j] == 1)
                addedge_list_undir(g, i, j);
}

typedef struct qnode
{
    int data;
    struct qnode *next;
} qnode;

typedef struct
{
    qnode *head;
    qnode *tail;
} queue;

queue* create_queue()
{
    queue *q = (queue*)malloc(sizeof(queue));
    q->head = q->tail = NULL;
    return q;
}

int isempty(queue *q)
{
    return q->head == NULL;
}

void enqueue(queue *q, int val)
{
    qnode *temp = (qnode*)malloc(sizeof(qnode));
    temp->data = val;
    temp->next = NULL;

    if (isempty(q))
        q->head = q->tail = temp;
    else
    {
        q->tail->next = temp;
        q->tail = temp;
    }
}

int dequeue(queue *q)
{
    if (isempty(q))
        return -1;

    qnode *temp = q->head;
    int val = temp->data;

    q->head = temp->next;
    if (q->head == NULL)
        q->tail = NULL;

    free(temp);
    return val;
}

void bfs(graph *g, int start, int n)
{
    int visited[MAX] = {0};
    queue *q = create_queue();

    enqueue(q, start);
    visited[start] = 1;

    while (!isempty(q))
    {
        int current = dequeue(q);
        printf("%d ", current);

        node *temp = g->arrlist[current];

        while (temp != NULL)
        {
            if (!visited[temp->data])
            {
                enqueue(q, temp->data);
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}

void bfs_components(graph *g, int n)
{
    int visited[MAX] = {0};
    int comp = 1;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            printf("Component %d:\n", comp++);

            queue *q = create_queue();
            enqueue(q, i);
            visited[i] = 1;

            while (!isempty(q))
            {
                int current = dequeue(q);
                printf("%d ", current);

                node *temp = g->arrlist[current];

                while (temp != NULL)
                {
                    if (!visited[temp->data])
                    {
                        enqueue(q, temp->data);
                        visited[temp->data] = 1;
                    }
                    temp = temp->next;
                }
            }
            printf("\n");
        }
    }
}

int bfs_shortest(graph *g, int start, int dest, int n)
{
    int visited[MAX] = {0};
    int dist[MAX];

    for (int i = 0; i < MAX; i++)
        dist[i] = -1;

    queue *q = create_queue();

    enqueue(q, start);
    visited[start] = 1;
    dist[start] = 0;

    while (!isempty(q))
    {
        int current = dequeue(q);

        node *temp = g->arrlist[current];

        while (temp != NULL)
        {
            if (!visited[temp->data])
            {
                enqueue(q, temp->data);
                visited[temp->data] = 1;
                dist[temp->data] = dist[current] + 1;

                if (temp->data == dest)
                    return dist[dest];
            }
            temp = temp->next;
        }
    }

    return -1; // no path
}

void dfs(graph *g, int v, int visited[])
{
    visited[v] = 1;
    printf("%d ", v);

    node *temp = g->arrlist[v];

    while (temp != NULL)
    {
        if (!visited[temp->data])
        {
            dfs(g, temp->data, visited);
        }
        temp = temp->next;
    }
}

void dfs_components(graph *g, int n)
{
    int visited[MAX] = {0};
    int comp = 1;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            printf("Component %d:\n", comp++);
            dfs(g, i, visited);
            printf("\n");
        }
    }
}

int dfs_path(graph *g, int src, int dest, int visited[])
{
    if (src == dest)
        return 1;

    visited[src] = 1;

    node *temp = g->arrlist[src];

    while (temp != NULL)
    {
        if (!visited[temp->data])
        {
            if (dfs_path(g, temp->data, dest, visited))
                return 1;
        }
        temp = temp->next;
    }

    return 0;
}

int main()
{
    int n = 6;

    graph *g = creategraph();
    int matrix[MAX][MAX];

    init_matrix(matrix, n);

    addedge_list_undir(g, 1, 2);
    addedge_list_undir(g, 1, 4);
    addedge_list_undir(g, 2, 4);
    addedge_list_undir(g, 2, 3);
    addedge_list_undir(g, 4, 5);
    addedge_list_undir(g, 4, 6);

    addedge_matrix(matrix, 1, 2);
    addedge_matrix(matrix, 1, 4);
    addedge_matrix(matrix, 2, 4);
    addedge_matrix(matrix, 2, 3);
    addedge_matrix(matrix, 4, 5);
    addedge_matrix(matrix, 4, 6);

    printf("Adjacency List:\n");
    printgraph_list(g, n);

    printf("\nAdjacency Matrix:\n");
    print_matrix(matrix, n);

    remove_edge_list(g, 1, 4);
    remove_edge_list(g, 2, 3);

    remove_edge_matrix(matrix, 1, 4);
    remove_edge_matrix(matrix, 2, 3);

    printf("\nAfter Removing Edges:\n");
    printf("Adjacency List:\n");
    printgraph_list(g, n);

    printf("Adjacency Matrix:\n");
    print_matrix(matrix, n);

    graph *g2 = creategraph();
    matrix_to_list(matrix, g2, n);

    printf("Converted List from Matrix:\n");
    printgraph_list(g2, n);


    printf("\n--- BFS Connected Components ---\n");
    bfs_components(g, n);

    printf("\n--- BFS Shortest Distance ---\n");
    int dist = bfs_shortest(g, 1, 3, n);
    printf("Shortest distance from 1 to 3: %d\n", dist);




    printf("\n--- DFS Connected Components ---\n");
    dfs_components(g, n);

    printf("\n--- DFS Path Check ---\n");
    int visited[MAX] = {0};

    if (dfs_path(g, 1, 3, visited))
        printf("There is a Path!\n");
    else
        printf("Impossible!\n");



    free(g);
    free(g2);
    return 0;
}

