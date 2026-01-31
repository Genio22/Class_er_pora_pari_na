#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
}node;

node *create_node(int data){
    node *newnode = (node *)malloc(sizeof(node));
    newnode -> data = data ;
    newnode -> next = NULL ;
    return newnode;
}

void insert_at_beginner(int data, node **head){
    node *newnode = create_node(data);
    newnode -> next = *head ;
    *head = newnode; 
}

void insert_at_pos(int pos, int data, node **head){
    node *newnode = create_node (data);
    node *temp_prev, *temp_curr;
    int count = 1;
    temp_prev = temp_curr = *head;

    if (*head == NULL){
        newnode->next = *head;
        *head = newnode;
        return;
    }
    while (count != pos){
        temp_prev = temp_curr;
        temp_curr = temp_curr -> next;
        count ++;
    }
    newnode -> next = temp_prev -> next ;
    temp_prev -> next = newnode ;   
}


void insert_at_end(int data, node **head){
    node *newnode = create_node(data);
    newnode -> next = NULL;
    node *current = *head;
    while (current != NULL){
        current = current -> next;
    }
    current -> next = newnode;
}

// bool contains(int items){

// }

void removefirst(node **head){
    node *current = *head;
    *head = current -> next;
    free(current);
}

void remove_at_any(int pos, node **head){
     
}

void removelast(node **head){
    node *current = *head;

     
}


void display(node *head)
{
    struct node *current;
    current = head;

    while (current != NULL)
    {
        printf("[%d]", current->data, current -> next);
        //printf("[%d|%p]", current->data, current -> next);
        if (current -> next != NULL){
            printf(" -> ");
        }
        current = current->next;
    }
    free(current);
}


int main()
{
    node *head = NULL;

    printf("Start\n");
    insert_at_beginner(10, &head);
    insert_at_beginner(20, &head);
    insert_at_beginner(30, &head);
    insert_at_beginner(40, &head);
    insert_at_beginner(50, &head);
    insert_at_beginner(60, &head);
    display(head);

    printf("\n");
    insert_at_pos(2, 70, &head);
    display(head);

    printf("\n");
    removefirst(&head);
    display(head);

    printf("\n");
    removelast(&head);
    display(head);


    return 0;
}






void removelast(node **head){
    node *current = *head;
    while (current -> next -> next != NULL)
    {
        current = current -> next;
    }
    free(current -> next);
    current -> next = NULL;
    

}