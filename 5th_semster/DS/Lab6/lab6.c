#include <stdio.h>


typedef struct node{
    int data;
    struct node *next;
}node;


node *create_node(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insert_at_beginner(int data, node **head)
{
    node *newnode = create_node(data);
    newnode->next = *head;
    *head = newnode;
}

// recursion for deleletion
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
    return head;
}


void display(node *head)
{
    struct node *current;
    current = head;

    while (current != NULL)
    {
        printf("[%d]", current->data, current->next);
        // printf("[%d|%p]", current->data, current -> next);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }
    free(current);
}


int main(){
    node  ll = NULL;

    printf("Start\n");
    insert_at_beginner(10, &head);
    insert_at_beginner(30, &head);
    insert_at_beginner(20, &head);
    insert_at_beginner(50, &head);
    insert_at_beginner(60, &head);
    insert_at_beginner(40, &head);
    display(head);
    return 0;
}






