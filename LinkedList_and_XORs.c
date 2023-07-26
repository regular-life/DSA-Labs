#include <conio.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define pass (void)0
#define print(arr, n) for (int i = 0 ; i < n ; i ++) {printf("%d ", arr[i]) ;}
#define fr(a,b) for (int i = a ; i < b ; i ++)

struct Node {
   long long data;
    struct Node* next;
};

void display_List(struct Node* head)
{
	struct Node* temp ; 
	temp = head ; 
	while (temp != NULL)
    {
		if (temp->next == NULL)
        {
			printf(" %ld", temp->data) ;
		}
		else
        {
			printf(" %ld->", temp->data) ;
		}
		temp = temp->next ;
	}
	printf("\n");
	return;
}

void kth(struct Node* head, int x, int n)
{
    if (x > n)
    {
        printf("-1\n") ;
        return ;
    }
    struct Node* temp = head ; 
    int i = 1 ;
    while (i != x)
    {
        i ++ ;
        temp = temp->next ;
    }
    printf("%d\n", temp->data) ;
    return ;
}

void addr(struct Node* head, int k, int x, int n)
{
    if (k > n)
    {
        printf("-1\n") ;
        return ;
    }
    struct Node* temp = head ; 
    int i = 1 ;
    while (i != k)
    {
        i ++ ;
        temp = temp->next ;
    }
    temp->data += x ;
    return ;   
}

void subt(struct Node* head, int k, int x, int n)
{
    if (k > n)
    {
        printf("-1\n") ;
        return ;
    }
    struct Node* temp = head ; 
    int i = 1 ;
    while (i != k)
    {
        i ++ ;
        temp = temp->next ;
    }
    temp->data -= x ;
    return ;   
}

void xo(struct Node* head, int k, int n)
{
    if (k > n)
    {
        printf("-1\n") ;
        return ;
    }
    struct Node* temp = head ; 
    int i = 1 ;
    while (i != n - k + 1)
    {
        i ++ ;
        temp = temp->next ;
    }
    int var = temp->data ;
    temp = temp->next ;
    while (temp != NULL)
    {
        var ^= temp->data ;
        temp = temp->next ;
    }
    printf("%d\n", var) ;
    return ;
}

int main()
{
    int n, q, x, k ;
    scanf("%d%d", &n, &q) ;
    struct Node* head = NULL ;
    struct Node* prev = NULL ;
    struct Node* curr = NULL ;
    head = (struct Node*)malloc(sizeof(struct Node)) ;
    prev = (struct Node*)malloc(sizeof(struct Node)) ;
    curr = (struct Node*)malloc(sizeof(struct Node)) ;
    scanf("%d", &head->data) ;
    curr = head ;
    for (int i = 1 ; i < n ; i ++)
    {
        struct Node* new = NULL ;
        new = (struct Node*)malloc(sizeof(struct Node)) ;
        scanf("%ld", &new->data) ;
        curr->next = new ;
        curr = curr->next ;
    }
    curr->next = NULL ;
    char op[20] ;
    while (q --)
    {
        scanf("%s", op) ;
        if (strcmp(op, "Delete") == 0)
        {
            scanf("%d", &x) ;
            struct Node* temp = head ; 
            if (n == 0 || x > n)
            {
                printf("-1\n") ;
            }
            else if (n == 1)
            {
                head = NULL ;
                n -- ;
            }
            else if (x == 1)
            {
                head = temp->next ;
                free(temp) ;
                n -- ;
            }
            else if (x == n)
            {
                for (int i = 1 ; i < n - 1; i ++)
                {
                    temp = temp->next ;
                }
                struct Node* m = temp->next ;
                temp->next = NULL ;
                free(m) ;
                n -- ;
            }
            else
            {
                for (int i = 1 ; i < x - 1 ; i ++)
                {
                    temp = temp->next ;
                }
                struct Node* m = temp -> next ;
                temp->next = m->next ;
                free(m) ;
                n -- ;
            }
        }
        else if (strcmp(op, "KthNode") == 0)
        {
            scanf("%d", &x) ;
            kth(head, x, n) ;
        }
        else if (strcmp(op, "Add") == 0)
        {
            scanf("%d%d", &k, &x) ;
            addr(head, k, x, n) ;
        }
        else if (strcmp(op, "Subtract") == 0)
        {
            scanf("%d%d", &k, &x) ;
            subt(head, k, x, n) ;
        }        
        else if (strcmp(op, "Xor") == 0)
        {
            scanf("%d", &k) ;
            xo(head, k, n) ;
        }
        // display_List(head) ;
    }
    return 0;
}