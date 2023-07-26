#include <stdio.h>
#include <stdlib.h>

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
    int data;
    struct node* left;
    struct node* right;
    struct node* st;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->st = NULL;
    return node;
}

int isBalanced(struct node* root)
{
	int lh, rh;
	if (root == NULL)
		return 1;
	lh = height(root->left);
	rh = height(root->right);

	if (abs(lh - rh) <= 1 && isBalanced(root->left)
		&& isBalanced(root->right))
		return 1 ;
	return 0;
}

int height(struct node* node)
{
	if (node == NULL)
		return 0;
	return 1 + max(height(node->left), height(node->right));
}

int main()
{
    int n, x;
    scanf("%d", &n);
    scanf("%d", &x);
    struct node* root = newNode(x);
    struct node* trav = root;
    n--;

    while (n > 0)
    {
        struct node* frs = NULL;
        struct node* nx = NULL;
        int len = 0;

        while (trav != NULL && n > 0)
        {
            scanf("%d", &x);

            if (x != -1)
            {
                struct node* temp = newNode(x);
                trav->left = temp;

                if (frs == NULL)
                {
                    frs = temp;
                    nx = frs;
                }
                else
                {
                    nx->st = temp;
                    nx = nx->st;
                }

                len++;
            }
            else
            {
                trav->left = NULL;
            }

            n--;

            if (n > 0)
            {
                scanf("%d", &x);

                if (x != -1)
                {
                    struct node* temp = newNode(x);
                    trav->right = temp;

                    if (frs == NULL)
                    {
                        frs = temp;
                        nx = frs;
                    }
                    else
                    {
                        nx->st = temp;
                        nx = nx->st;
                    }

                    len++;
                }
                else
                {
                    trav->right = NULL;
                }

                n -= 1;
                trav = trav->st;
            }
        }

        trav = frs;

        if (len == 0)
        {
            break;
        }
    }
    printf("%d\n", height(root)) ;
    if (isBalanced(root) == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
