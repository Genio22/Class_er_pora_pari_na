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
    printf("Enter data (enter -1 to skip): ");
    scanf("%d", &value);

    if (value == -1)
    {
        return NULL;
    }

    node *root = create_node(value);
    printf("Enter left child of %d:\n", value);
    root->left = build_tree();
    printf("Enter right child of %d:\n", value);
    root->right = build_tree();

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

int main()
{
    node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n1. Build Tree\n2. Insert\n3. Inorder\n4. Preorder\n5. Postorder\n6. Height\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            root = build_tree();
            break;
        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 3:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;
        case 5:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;
        case 6:
            printf("Height: %d\n", height(root));
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
