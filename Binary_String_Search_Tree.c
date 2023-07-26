#include <stdio.h>
#include <stdlib.h>

#define print(arr, n) for (int i = 0 ; i < n ; i ++) {printf("%d ", arr[i]) ;}
#define fr(a,b) for (int i = a ; i < b ; i ++)

struct node
{
    char str[20] ;
    struct node *left, *right ;
};

struct node* newNode(char s[20])
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->str, s);
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, char s[20])
{
    if (node == NULL)
        return newNode(s) ;

    if (strcmp(s, node->str) < 0)
    {
        node->left = insert(node->left, s) ;
    }
    else if (strcmp(s, node->str) > 0)
    {
        node->right = insert(node->right, s) ;
    }
    return node;
}

int part(char str[20], char pre[20])
{
    int n = sizeof(pre) ;
    fr(0, n)
    {
        if (str[i] != pre[i])
        {
            return -1 ;
        }
    }
    return 0 ;
}

int main()
{
    int n, q ;
    scanf("%d%d", &n, &q) ;
    char st[20] ;
    scanf("%s", st) ;
    struct node* root = newNode(st) ;
    fr(1, n)
    {
        scanf("%s", st) ;
        insert(root, st) ;
    }
    char op[6] ;
    while (q --)
    {
        scanf("%s", op) ;
        if (op[0] == 'D')
        {
            
        }
        else
        {
            
        }
    }
    return 0;
}