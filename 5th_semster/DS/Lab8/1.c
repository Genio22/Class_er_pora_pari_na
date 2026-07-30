#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BSTnode
{
    int data;
    struct BSTnode *left;
    struct BSTnode *right;
} BSTnode;

BSTnode *createnode(int value)
{
    BSTnode *newnode = (BSTnode *)malloc(sizeof(BSTnode));

    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void BST_insert(BSTnode **root, int value)
{
    if (*root == NULL)
    {
        *root = createnode(value);
        return;
    }

    if (value > (*root)->data)
    {
        BST_insert(&(*root)->right, value);
    }
    else
    {
        BST_insert(&(*root)->left, value);
    }
}

void preorder_bst(BSTnode *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
        preorder_bst(root->left);
        preorder_bst(root->right);
    }
}

void inorder_bst(BSTnode *root)
{
    if (root != NULL)
    {
        inorder_bst(root->left);
        printf(" %d ", root->data);
        inorder_bst(root->right);
    }
}

void postorder_bst(BSTnode *root)
{
    if (root != NULL)
    {
        postorder_bst(root->left);
        postorder_bst(root->right);
        printf(" %d ", root->data);
    }
}

void BST_search(BSTnode **root, int value)
{
    if (*root == NULL)
    {
        printf("Not Found in the tree\n");
        return;
    }
    if ((*root)->data == value)
    {
        printf("Found in the tree");
        return;
    }

    if (value > (*root)->data)
    {
        BST_search(&(*root)->right, value);
    }
    else
    {
        BST_search(&(*root)->left, value);
    }
}

int findMin(BSTnode *root)
{
    if (root->left == NULL)
    {
        return root->data;
    }
    return findMin(root->left);
}

int findMax(BSTnode *root)
{
    if (root->right == NULL)
    {
        return root->data;
    }
    return findMax(root->right);
}

void diff_max_min(BSTnode *root)
{
    int max = findMax(root);
    int min = findMin(root);
    printf("Diff: %d\n", max - min);
}

int countleaf(BSTnode *root){
    if (root == NULL){
        return 0;
    }
    if (root->left == NULL && root->right){
        return 1;
    }
    return countleaf (root->left) + countleaf (root->left);

}

int main()
{
    BSTnode *root = NULL;

    BST_insert(&root, 50);
    BST_insert(&root, 30);
    BST_insert(&root, 20);
    BST_insert(&root, 40);
    BST_insert(&root, 70);
    BST_insert(&root, 60);
    BST_insert(&root, 80);

    printf("Preorder traversal: ");
    preorder_bst(root);
    printf("\n");

    BST_search(&root, 30);
    printf("\n");
    BST_search(&root, 100);

    printf("Max: %d", findMax(root));
    printf("\n");
    printf("Min: %d", findMin(root));
    printf("\n");
    diff_max_min(root);
    return 0;
}
