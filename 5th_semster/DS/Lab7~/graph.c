#include <stdio.h>
#include <stdlib.h>

const int v = 100;

typedef struct node
{
    int data;
    node *next;
} node;

typedef struct graph
{
    node *arrlist[v];
} graph;

graph *creategraph()
{
    graph *g = (graph *)malloc(sizeof(graph));
    for (int i = 0; i < v; i++)
    {
        g->arrlist[i] = NULL;
    }

    return g;
}

node* createnode(int data){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void printgraph_list(graph* g){

}

void addedge_matrix(graph *g, int u, int v){

}

void addedge_list(graph *g, int u, int v){
    
}

int main()
{

    return 0;
}
