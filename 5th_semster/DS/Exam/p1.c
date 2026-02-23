
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *next;
}node;

void insertatbeg(node **head, int data){
    node *newnode = (node *)malloc(sizeof(node));
    newnode -> data = data;
    newnode -> next = *head;
    *head = newnode;
}

void display(node *head){
    node *current = head;
    while (current != NULL){
        printf("%d", current-> data);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current -> next;
    }
}

int main() {
    node *head = NULL;
    
    printf("Start\n");
    insertatbeg(&head,10);
    insertatbeg(&head,20);
    insertatbeg(&head,30);
    insertatbeg(&head,40);
    insertatbeg(&head,50);
    insertatbeg(&head,60);
    //printf("%d\n", head->data);
    display(head);
        printf("\n");
    printf("Try programiz.pro");

    return 0;
}