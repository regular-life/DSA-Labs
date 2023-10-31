// You are tasked with implementing an AVL tree, a self-balancing binary search tree. The tree supports two types of operations: insert x and subtree x.

// For the insert x operation, you need to insert the element x into the AVL tree. After the insertion, you should print two space-separated integers representing the total number of left rotations (L) and right rotations (R) performed during the insertion process, respectively.
// The subtree x operation requires you to print the sum of all elements in the subtree rooted at node x, including the value of x itself if x exists otherwise print 'NA'.
// Constraints:

// The number of queries, denoted by Q, will be between 1
//  and 10^5
// , inclusive. (1 ≤ 𝑄 ≤ 10^5)
// Each query will be either of the two types: insert x or subtree x.
// For the insert x operation, the value of x will be an integer between −10^9
//  and 10^9
// , inclusive. (−10^9 ≤ 𝑥 ≤ 10^9)
// All input and output values will fit in a 64
// -bit signed integer.
// Input
// The first line of the input contains an integer 𝑄
// , representing the number of queries.

// The next 𝑄
//  lines contain the queries. Each query is in one of the following formats:

// insert x: representing the insertion of the element x into the AVL tree.
// subtree x: representing the query to print the sum of the subtree rooted at node x.
// It is guaranteed that the input format will follow the constraints mentioned earlier.
// Output
// print the answer of each query in above mentioned format.


// input
// 9
// insert 1
// subtree 1
// insert 5
// subtree 1
// insert 3
// subtree 1
// subtree 3
// subtree 5
// subtree 10


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
