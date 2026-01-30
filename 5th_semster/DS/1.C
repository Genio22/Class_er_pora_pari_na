#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

int sizeoflinkl(struct node *head1);


void insertatbeg(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;

    if (head != NULL)
    {
        n->next = head;
    }
    head = n;
}

void insertatend(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    struct node *currnt;

    currnt = head;
    while (currnt != NULL)
    {
        currnt = currnt->next;
    }
    n = currnt;
    n->next = NULL;
}

// void insert_at_pos(int pos, int data)
// {
//     struct node *newnode = (struct node *)malloc(sizeof(struct node));
//     struct node *current = head;

//     newnode->data = data;
//     newnode->next = NULL;

//     int i = 1;

//     if (current == NULL)
//     {
//         head = newnode;
//     }



//     if (pos > 1)
//     {

//         while (i < pos - 1 || current != NULL)
//         {
//             current = current->next;
//             i++;
//         }

//         newnode->next = current->next;
//         current->next = newnode;
//     }
//     else
//     {
//         newnode->next = head;
//         head = newnode;
//     }
// }

void insert_at_pos(int pos, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *current = head;
    newnode->data = data;
    int i = 1;
    int s = sizeoflinkl(head);

    if (current == NULL)
    {
        newnode->next = head;
        head = newnode;
    }

    if (current != NULL)
    {
        if (pos > 1 && pos <= s)
        {

            while (i < pos - 1)
            {
                current = current->next;
                i++;
            }

            newnode->next = current->next;
            current->next = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
}

void deletelist()
{
    struct node *current;
    current = head;
    free(head->next);
    while (current != NULL)
    {
        current = current->next;
        free(current->next);
    }
    free(current->next);
}

// void display()
// {
//     struct node *current;
//     current = head;
//     while (current != NULL)
//     {
//         printf("[%d] -> ", current->data);
//         current = current->next;
//     }
// }


int sizeoflinkl(struct node *head1)
{
    struct node *current;
    current = head1;

    int count = 0;

    while (current != NULL)
    {
        count++;
        current = current->next;

    }
    return count;
}


int main()
{
    printf("Start\n");
    insertatbeg(10);
    insertatbeg(20);
    insertatbeg(30);
    insertatbeg(40);
    insertatbeg(50);
    insertatbeg(60);
    printf("%d\n", head->data);
    display();

    //   insert_at_pos(* head, 3, 53);
    insert_at_pos(3, 53);
    printf("\n");
    display();

    insert_at_pos(6, 53);
    printf("\n");
    display();

    insert_at_pos(8, 53);
    printf("\n");
    display();

    insert_at_pos(1, 53);
    printf("\n");
    display();

    printf("\nSize = %d", sizeoflinkl(head));

    return 0;
}
