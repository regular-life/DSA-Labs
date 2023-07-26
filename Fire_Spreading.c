#include <conio.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define print(arr, n) for (int i = 0 ; i < n ; i ++) {printf("%d ", arr[i]) ;}

int max(int a, int b, int c)
{
    if (a > b)
    {
        if (c > a)
        {
            return c ;
        }
        return a ;
    }
    if (c > b)
    {
        return c ;
    }
    return b ;
}

int min(int a, int b)
{
    if (a > b)
    {
        return b ;
    }
    return a ;
}

int dis(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1) ;
    int dy = abs(y2 - y1) ;
    return max(dx, dy, abs(dx - dy)) ;
}

int main()
{
    int m , n ;
    scanf("%d%d", &m, &n) ;
    getchar() ;
    int mat[m][n] ;
    int ones[m*n][2] ;
    int cnt = 0 ;
    int mx = 0 ;
    for (int i = 0 ; i < m ; i ++)
    {
        for (int j = 0 ; j < n ; j ++)
        {
            scanf("%d", &mat[i][j]) ;
            if (mat[i][j] == 1)
            {
                ones[cnt][0] = i ;
                ones[cnt][1] = j ;
                cnt ++ ;
            }
        }
        getchar() ;
    }
    for (int i = 0 ; i < m ; i ++)
    {
        for (int j = 0 ; j < n ; j ++)
        {
            if (mat[i][j] == 0)
            {
                int m = 1000000000 ;
                for (int p = 0 ; p < cnt ; p ++)
                {
                    m = min(m, dis(i, j, ones[p][0], ones[p][1])) ;
                }
                mx = max(mx, m, 0) ;
            }
        }
    }
    printf("%d", mx) ;
    return 0 ;
}