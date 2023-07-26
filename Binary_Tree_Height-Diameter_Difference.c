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