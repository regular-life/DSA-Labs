#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define print(arr, n) for (int i = 0 ; i < n ; i ++) {printf("%d ", arr[i]) ;}

void swap(int *a, int *b)
{
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int min(int a, int b)
{
    if (a > b)
    {
        return b ;
    }
    return a ;
}

struct node
{
    int key ;
    struct node *left, *right ;
};

struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node)) ;
    temp->key = item ;
    temp->left = temp->right = NULL ;
    return temp ;
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL)
    {
        return newNode(key) ;
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key) ;
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key) ;
    }
    return node ;
}

void preorder(struct node* root)
{
    if (root == NULL)
    {
        return ;
    }
    printf("%d", root -> key) ;
    printf(" ") ;
    preorder(root -> left) ;
    preorder(root -> right) ;
    return ;
}

int main()
{
    int n ;
    scanf("%d", &n) ;
    int x ;
    scanf("%d", &x) ;
    struct node* root = newNode(x) ;
    n -- ;
    while (n --)
    {
        scanf("%d", &x) ;
        insert(root, x) ;
    }
    preorder(root) ;
}