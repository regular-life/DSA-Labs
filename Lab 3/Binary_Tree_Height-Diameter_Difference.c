// You are given the level order traversal of a binary tree. The level order traversal of a binary tree is defined as the sequence of node values visited by level, from the root node at level 0, followed by the nodes at level 1, then level 2, and so on. Each level is visited from left to right. If a node has no child, it is represented by the integer -1 in the level order traversal sequence.

// Your task is to compute the absolute difference between the height and diameter of the binary tree represented by the given level order traversal.

// The height of a binary tree is defined as the length of the longest path from the root node to any leaf node in the tree.

// The diameter of a binary tree is defined as the length of the longest path between any two nodes in the tree.

// Input
// The input consists of two lines. The first line contains a single integer 𝑛
//  (1≤𝑛≤104)
// , the number of nodes in the binary tree.

// The second line contains 2𝑛+1
//  space-separated integers representing the level order traversal of the binary tree, where each integer represents the value of a node in the tree.

// The values of the nodes are unique and range from 1 to 𝑛
// . If a node has no child, it is represented by the integer -1.

// Output
// Output a single integer, the absolute difference between the height and diameter of the binary tree

// input
// 6
// 1 2 3 4 -1 5 -1 6 -1 -1 -1 -1 -1
// output
// 2

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define print(arr, n) for (int i = 0 ; i < n ; i ++) {printf("%d ", arr[i]) ;}

struct node {
    int data ;
    struct node* left ;
    struct node* right ;
    struct node* st ;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node)) ;
    node->data = data ;
    node->left = NULL ;
    node->right = NULL ;
    node->st = NULL ;
    return (node) ;
}

void print2DUtil(struct node* root, int space)
{
    if (root == NULL)
        return;
    space += 10;
    print2DUtil(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    print2DUtil(root->left, space);
}

void print2D(struct node* root)
{
    print2DUtil(root, 0);
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int diameterOpt(struct node* root, int* height)
{
	int lh = 0, rh = 0;

	int ldiameter = 0, rdiameter = 0;

	if (root == NULL) {
		*height = 0;
		return 0;
	}

	ldiameter = diameterOpt(root->left, &lh);
	rdiameter = diameterOpt(root->right, &rh);

	*height = max(lh, rh) + 1;

	return max(lh + rh + 1, max(ldiameter, rdiameter));
}

int main()
{
    int n, x ;
    scanf("%d", &n) ;
    scanf("%d", &x) ;
    if (x == -1)
    {
        printf("0") ;
    }
    else
    {
        struct node* root = newNode(x) ;
        struct node* trav = root ;
        int i = 1 ;
        while (i < 2*n + 1)
        {
            struct node* frs = (struct node*)malloc(sizeof(struct node)) ;
            frs = NULL ;
            struct node* nx = (struct node*)malloc(sizeof(struct node)) ;
            nx = NULL ;
            int len = 0 ;
            while (trav != NULL && i < 2*n + 1)
            {
                scanf("%d", &x) ;

                if (x != -1)
                {
                    struct node* temp = newNode(x) ;
                    trav -> left = temp ;
                    if (frs == NULL)
                    {
                        frs = temp ;
                        nx = frs ;
                    }
                    else
                    {
                        nx -> st = temp ;
                        nx = nx -> st ;
                    }
                    len ++ ;
                }
                else
                {
                    trav -> left = NULL ;
                }


                scanf("%d", &x) ;
                if (x != -1)
                {
                    struct node* temp = newNode(x) ;
                    trav -> right = temp ;
                    if (frs == NULL)
                    {
                        frs = temp ;
                        nx = frs ;
                    }
                    else
                    {
                        nx -> st = temp ;
                        nx = nx -> st ;
                    }
                    len ++ ;
                }
                else
                {
                    trav -> right = NULL ;
                }
                i += 2 ;
                trav = trav -> st ;
            }
            trav = frs ;
            if (len == 0)
            {
                break ;
            }
        }
        int he = 0 ;
        int di = diameterOpt(root, &he) ;
        printf("%d", abs(di - he)) ;
        // print2D(root) ;
    }
    return 0 ;
}
