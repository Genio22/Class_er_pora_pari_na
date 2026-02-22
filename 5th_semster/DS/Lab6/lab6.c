#include <stdio.h>


typedef struct node{
    int data;
    struct node *next;
}node;

node *delete_nth(node *head, int target){
    if (head == NULL){
        return NULL;
    }
    
    if (head -> data == target){
        node *temp = head -> next;
        free(head);
        return temp;
    }

    delete_nth(head->next, target);
}






