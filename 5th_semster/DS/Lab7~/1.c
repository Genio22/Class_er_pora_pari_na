#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create_node(int value)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node *build_tree()
{
    int value;
    printf("Enter data (enter -1 for no node): ");
    scanf("%d", &value);

    if (value == -1)
        return NULL;
    node *root = create_node(value);

    char opt;
    printf("Does node %d have a left child? (y/n): ", value);
    scanf(" %c ", &opt);

    if (opt == 'y')
    {
        root->left = build_tree();
    }
    else
    {
        root->left = NULL;
    }

    printf("Does node %d have a right child? (y/n): ", value);
    scanf(" %c ", &opt);

    if (opt == 'y')
    {
        root->right = build_tree();
    }
    else
    {
        root->right = NULL;
    }
    return root;
}

node *insert(node *root, int value)
{

    if (root == NULL)
    {
        return create_node(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void preorder(node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d ", root->data);
        inorder(root->right);
    }
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ", root->data);
    }
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (height(root->left) > height(root->right)) ? height(root->left) + 1 : height(root->right) + 1;
}

int lheight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return lheight(root->left) + 1;
}

int rheight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return rheight(root->right) + 1;
}

void balance(node *root)
{
    ((balance(root->left) - balance(root->right)) <= 1) ? printf("Balance") : printf("Not Balance");
}

int main()
{
    node *root = NULL;

    return 0;
}
