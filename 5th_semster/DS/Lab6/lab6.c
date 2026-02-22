#include <stdio.h>
#include <stdlib.h>


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
node *delete_by_value(node *head, int target){
    if (head == NULL){
        return NULL;
    }
    
    if (head -> data == target){
        node *temp = head -> next;
        free(head);
        return temp;
    }

    head -> next = delete_by_value(head->next, target);
    return head;
}


void display(node *head)
{
    struct node *current;
    current = head;

    while (current != NULL)
    {
        printf("[%d]", current->data);
        // printf("[%d|%p]", current->data, current -> next);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }

}

node* sorted_insert(node* sorted, node* newnode){
    if(sorted == NULL || newnode->data <= sorted->data){
        newnode->next = sorted;
        return newnode;
    }

    sorted->next = sorted_insert(sorted->next, newnode);
    return sorted;
}


node* insertion_sort(node* head){
    if(head == NULL || head->next == NULL)
        return head;

    node* rest = insertion_sort(head->next);

    head->next = NULL;  
    return sorted_insert(rest, head);
}


int main(){
    node *head = NULL;

    printf("Start\n");
    insert_at_beginner(10, &head);
    insert_at_beginner(30, &head);
    insert_at_beginner(20, &head);
    insert_at_beginner(50, &head);
    insert_at_beginner(60, &head);
    insert_at_beginner(40, &head);
    display(head);
    
    printf("\n");
    head = delete_by_value(head, 30);
    display(head);
    
    printf("\n");
    insertion_sort(head);
    display(head);
    

    return 0;
}






