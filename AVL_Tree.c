#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define print(arr, n) for (long long i = 0  ;  i < n  ;  i ++) {printf("%d ", arr[i])  ; }
#define fr(a,b) for (int i = a ; i < b ; i ++)

void swap(long long *a, long long *b)
{
    long long temp = *a  ; 
    *a = *b  ; 
    *b = temp  ; 
}

struct Node
{
    long long value ; 
    struct Node* left ; 
    struct Node* right ; 
    long long height ; 
} ; 

long long max(long long a, long long b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

long long min(long long a, long long b)
{
    if (a > b)
    {
        return b ;
    }
    return a ;
}

long long height(struct Node* node)
{
    if (node == NULL)
    {
        return -1 ; 
    }
    return node->height ; 
}

long long bf(struct Node* loca)
{
    if (loca == NULL)
    {
        return 0 ; 
    }
    return height(loca->left) - height(loca->right) ; 
}

struct Node* newNode(long long value)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node)) ; 
    node->value = value ; 
    node->left = NULL ; 
    node->right = NULL ; 
    node->height = 0 ; 
    return node ; 
}

struct Node* search(long long value, struct Node* head)
{
    if (head == NULL)
    {
        return NULL ; 
    }
    else if (head->value > value)
    {
        return search(value, head->left) ; 
    }
    else if (head->value < value)
    {
        return search(value, head->right) ; 
    }
    else
    {
        return head ; 
    }
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left ;
    struct Node *T2 = x->right ;

    x->right = y ;
    y->left = T2 ;

    y->height = max(height(y->left), height(y->right)) + 1 ;
    x->height = max(height(x->left), height(x->right)) + 1 ;

    return x ;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right ;
    struct Node *T2 = y->left ;

    y->left = x ;
    x->right = T2 ;

    x->height = max(height(x->left), height(x->right)) + 1 ;
    y->height = max(height(y->left), height(y->right)) + 1 ;

    return y ;
}

struct Node* insert(struct Node* head, long long value, long long* leftR, long long* rightR)
{
    if (head == NULL)
    {
        return newNode(value) ; 
    }

    if (value > head->value)
    {
        head->right = insert(head->right, value, leftR, rightR) ; 
    }
    else if (value < head->value)
    {
        head->left = insert(head->left, value, leftR, rightR) ; 
    }

    head->height = 1 + max(height(head->left), height(head->right)) ; 
    long long balance = bf(head) ; 
    if (balance > 1 && value < head->left->value)
    {
        *rightR += 1 ; 
        return rightRotate(head) ; 
    }
    else if (balance < -1 && value > head->right->value)
    {
        *leftR += 1 ; 
        return leftRotate(head) ; 
    }
    else if (balance > 1 && value > head->left->value)
    {
        *rightR += 1 ; 
        *leftR += 1 ; 
        head->left = leftRotate(head->left) ; 
        return rightRotate(head) ; 
    }
    else if (balance < -1 && value < head->right->value)
    {
        *rightR += 1 ; 
        *leftR += 1 ; 
        head->right = rightRotate(head->right) ; 
        return leftRotate(head) ; 
    }

    return head ; 
}

long long subtree(struct Node* node)
{
    if (node == NULL)
    {
        return 0 ; 
    }
    long long sum = node->value ; 
    sum += subtree(node->left) ; 
    sum += subtree(node->right) ; 
    return sum ; 
}

void print2DUtil(struct Node* root, long long space)
{
    if (root == NULL)
        return;
    space += 10;
    print2DUtil(root->right, space) ;
    printf("\n");
    for (long long i = 10; i < space; i++)
        printf(" ");
    printf("%lld\n", root->value) ;
    print2DUtil(root->left, space) ;
}

signed main()
{
    long long n ; 
    scanf("%lld", &n) ; 
    getchar() ; 
    struct Node* root = NULL ; 
    while (n --)
    {
        long long leftR = 0 ; 
        long long rightR = 0 ; 
        char input[1000] ; 
        long long number1 ; 
        scanf("%s", input)  ; 
        if (strcmp(input, "insert") == 0)
        {
            scanf("%lld",&number1) ; 
            long long x = number1 ; 
            root = insert(root, x, &leftR, &rightR) ; 
            printf("%lld %lld\n", leftR, rightR) ; 
        }
        else
        {
            scanf("%lld",&number1) ; 
            long long x = number1 ; 
            struct Node* loca = search(x, root) ; 

            if (loca == NULL)
            {
                printf("NA\n") ; 
            }
            else
            {
                printf("%lld\n", subtree(loca)) ; 
            }
        }
    }
    return 0 ; 
}