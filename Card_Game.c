#include <conio.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define pass (void)0
#define print(arr, n) for (int i = 0 ; i < n ; i ++) {printf("%d ", arr[i]) ;}

int main()
{
    int n, k ;
    scanf("%d%d", &n, &k) ;
    long int arr[n] ;
    long int mx = 0 ;
    long int rohu = 0, ishu = 0 ;
    int ind ;
    for (int i = 0 ; i < n ; i ++)
    {
        scanf("%ld", &arr[i]) ;
    }
    int i = 0, j = k - 1 ;
    for (int p = i ; p <= j ; p ++)
    {
        if (arr[p] > mx)
        {
            mx = arr[p] ;
            ind = p ;
        }
    } 
    while (i <= n - k && j < n)
    {
        while (i <= ind && j < n)
        {
            if (arr[j] > mx)
            {
                mx = arr[j] ;
                ind = j ;
            }
            if (i % 2 == 0)
            {
                ishu += mx ;
            }
            else
            {
                rohu += mx ;
            }
            i ++ ; j ++ ;
        }
        mx = 0 ;
        if (j != n)
        {
            for (int p = i ; p <= j ; p ++)
            {
                if (arr[p] > mx)
                {
                    mx = arr[p] ;
                    ind = p ;
                }
            }
        }
    }
    if (ishu > rohu)
    {
        printf("ishu") ;
    }
    else if (ishu == rohu)
    {
        printf("draw") ;
    }
    else 
    {
        printf("rohu") ;
    }
}