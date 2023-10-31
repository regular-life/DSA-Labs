// You are given a rectangular land of dimension 𝑚∗𝑛
//  represented by a binary matrix, where 0
//  represents normal plants and 1
//  represents supernatural plants. A fire has started spreading from the boundaries of the land where normal plants are present. The fire cannot spread through supernatural plants, but it can spread horizontally and vertically to neighboring normal plants in one unit of time.

// You are given a series of queries, each consisting of two numbers 𝑥
//  and 𝑦
// . For each query, you need to determine the maximum time to pluck the fruits from the plant located at position (𝑥,𝑦)
//  before the fire reaches it. If the plant does not catch fire, print "infinity".

// Constraints

// 1 ≤ 𝑚,𝑛 ≤ 1000
// 0 ≤ 𝑥 < 𝑚
// 0 ≤ 𝑦 < 𝑛
// 0 ≤ 𝑞 < 2∗105

// Input
// The first line of input consists of two integers 𝑚
//  and 𝑛
// , separated by a space, representing the dimensions of the land (number of rows and columns).

// Subsequently, there are 𝑚
//  lines with 𝑛
//  entries in each line, representing the binary 2
// D matrix.

// The next line contains a single integer 𝑞
// , representing the number of queries.

// The following 𝑞
//  lines contain two space-separated integers 𝑥
//  and 𝑦
// , representing the position of a plant for each query.

// Output
// For each query, print the maximum time in next line to pluck the fruits from the plant before the fire reaches it. If the plant does not catch fire, print "infinity".


// input
// 6 5
// 0 0 0 0 0
// 0 0 1 0 0
// 0 1 0 1 0
// 1 0 0 1 0
// 0 1 1 0 0
// 0 0 0 0 0
// 6
// 0 0
// 1 1
// 2 2
// 3 3
// 4 4
// 5 0

// output
// 1
// 2
// infinity
// infinity
// 1
// 1

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
