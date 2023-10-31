// The only difference between easy and hard versions is the constraint on matrix dimensions.

// It's April and Lawrence's birthday is just round the corner. Lawrence plans to throw a grandiose birthday party where he and his friends will vibe to classical pieces by Chopin, Mozart and Beethoven. Now, Lawrence will be hosting this party in the main hall of his house and wants your help to figure out the maximum number of friends he can invite. Lawrence wants all his friends to sit around one big rectangular table, therefore, he wants to know what is the largest rectangular table he can place such that maximum friends can sit around it.

// The hall is represented as a 2D matrix of size 𝑚
//  x 𝑛
//  and the entries of the matrix are either '.' or 'X' indicating the particular cell is available or preoccupied by some furniture, respectively. You have to find the largest possible rectangle consisting of only free cells such that maximum number of friends can be accommodated.

// Note: The number of friends that can sit around a table equals the perimeter of the table.

// Constraints

// 1≤𝑚,𝑛≤100
// Input
// The first line of input consists of two integers 𝑚
//  and 𝑛
//  respectively. Subsequently, there are 𝑚
//  lines with 𝑛
//  entries in each line which are either '.' or 'X' representing Lawrence's main hall.

// Output
// Print the maximum number of friends Lawrence can invite (note that you have to subtract 1 from the final answer to exclude Lawrence)

// input
// 4 4
// X.XX
// X..X
// ..X.
// ..XX
// output
// 9


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

int n, top = -1, *stack;

void push(int x)
{
    if (top == n)
    {
        return ;
    }
    stack[++top] = x ;
}

int pop()
{
    if (top == -1)
    {
        return -1 ;
    }
    return stack[top--] ;
}

int peek()
{
    if (top == -1)
    {
        return -1 ;
    }
    return stack[top] ;
}

bool isEmpty()
{
    if (top == -1)
    {
        return true ;
    }
    return false ;
}

void empty()
{
    while ( !isEmpty() )
    {
        pop() ;
    }
}

int main()
{
    int m;
    scanf("%d%d", &m, &n) ;
    char matrix[m][n] ;
    getchar() ;
    int hist[n] ;
    for (int p = 0 ; p < n ; p ++)
    {
        hist[p] = 0 ;
    }
    int mx = 0 ;
    stack = (int*)malloc(n*sizeof(int));
    for (int i = 0 ; i < m ; i ++)
    {
        for (int j = 0 ; j < n ; j ++)
        {
            scanf("%c", &matrix[i][j]) ;
            if (matrix[i][j] == '.')
            {
                hist[j] ++ ;
            }
            else
            {
                hist[j] = 0 ;
            }
        }
        // print(hist, n) ;
        // printf("\n") ;
        getchar() ;
        empty() ;
        int leftsmall[n], rightsmall[n] ;
        for (int p = 0 ; p < n ; p ++)
        {
            while (!isEmpty() && hist[peek()] >= hist[p])
            {
                pop() ;
            }
            if (isEmpty())
            {
                leftsmall[p] = 0 ;
            }
            else
            {
                leftsmall[p] = peek() + 1 ;
            }
            push(p) ;
        }
        empty() ;
        for (int p = n - 1 ; p >= 0 ; p --)
        {
            while (!isEmpty() && hist[peek()] >= hist[p])
            {
                pop() ;
            }
            if (isEmpty())
            {
                rightsmall[p] = n - 1 ;
            }
            else
            {
                rightsmall[p] = peek() - 1 ;
            }
            push(p) ;
        }
        // print(leftsmall, n) ;
        // printf("\n") ;
        // print(rightsmall, n) ;
        // printf("\n") ;
        for (int p = 0 ; p < n ; p ++)
        {
            if (hist[p] != 0)
            {
                mx = max(mx, 2 * (hist[p] + rightsmall[p] - leftsmall[p] + 1) - 1) ;
            }
        }
    }
    printf("%d", mx) ;
    return 0 ;
}
