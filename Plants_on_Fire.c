#include <stdio.h>
#include <stdlib.h>

#define fr(a,b) for (int i = a  ; i < b  ; i ++)
#define print(arr,n) for(int i = 0  ; i < n  ; i++){cout << arr[i] << " "  ;}

int isValid(int x, int y, int rows, int cols)
{
    if (x >= 0 && x < rows && y >= 0 && y < cols)
    {
        return 1  ;
    }
    return 0  ;
}

void bfs(int rows, int cols, int grid[rows][cols], int timeToReach[rows][cols])
{
    int queueX[rows * cols] ;
    int queueY[rows * cols] ;
    int front = 0 ;
    int back = 0 ;
    int visited[rows][cols]  ;
    fr(0, rows)
    {
        for (int j = 1 ; j < cols ; j++)
        {
            visited[i][j] = 0  ;
        }
    }
    fr(0, rows)
    {
        if (grid[i][0] == 0)
        {
            queueX[back] = i ;
            queueY[back] = 0 ;
            back++ ;
            visited[i][0] = 1 ;
        }
        if (grid[i][cols - 1] == 0)
        {
            queueX[back] = i ;
            queueY[back] = cols - 1 ;
            back++ ;
            visited[i][cols - 1] = 1 ;
        }
    }

    for (int j = 1 ; j < cols - 1 ; j++)
    {
        if (grid[0][j] == 0)
        {
            queueX[back] = 0 ;
            queueY[back] = j ;
            back++ ;
            visited[0][j] = 1 ;
        }
        if (grid[rows - 1][j] == 0)
        {
            queueX[back] = rows - 1 ;
            queueY[back] = j ;
            back++ ;
            visited[rows - 1][j] = 1 ;
        }
    }
    int time = 0 ;
    while (front < back)
    {
        int size = back - front ;
        while (size--)
        {
            int x = queueX[front] ;
            int y = queueY[front] ;
            front++ ;

            if (grid[x][y] == 0 && timeToReach[x][y] == -1)
            {
                timeToReach[x][y] = time ;
            }

            int dx[] = {-1, 1, 0, 0} ;
            int dy[] = {0, 0, -1, 1} ;

            for (int i = 0 ; i < 4 ; i++)
            {
                int nx = x + dx[i] ;
                int ny = y + dy[i] ;
                if (isValid(nx, ny, rows, cols) == 1 && grid[nx][ny] == 0 && visited[nx][ny] == 0)
                {
                    queueX[back] = nx ;
                    queueY[back] = ny ;
                    back++ ;
                    visited[nx][ny] = 1 ;
                }
            }
        }
        time++ ;
    }
}

int main()
{
    int m, n ;
    scanf("%d %d", &m, &n) ;
    int grid[m][n] ;
    fr(0, m)
    {
        for (int j = 0 ; j < n ; j++)
        {
            scanf("%d", &grid[i][j]) ;
        }
    }
    int timeToReach[m][n] ;
    fr(0, m)
    {
        for (int j = 0 ; j < n ; j++)
        {
            timeToReach[i][j] = -1 ;
        }
    }

    bfs(m, n, grid, timeToReach) ;

    int q ;
    scanf("%d", &q) ;
    while (q--)
    {
        int x, y ;
        scanf("%d %d", &x, &y) ;
        if (grid[x][y] == 1 || timeToReach[x][y] == -1)
        {
            printf("infinity\n") ;
        }
        else
        {
            printf("%d\n", timeToReach[x][y] + 1) ;
        }
    }
    return 0 ;
}